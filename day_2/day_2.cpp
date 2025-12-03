//
// Created by ivans on 02/12/2025.
//

#include "day_2.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <execution>

Day2::Day2(std::string filename) : DayBase(std::move(filename))
{
    m_textData = GetPerDelimiterTextData(",");
    ProcessTextData();
}

std::string Day2::GetAnswerPart1()
{
    return Solve(
            [&](const std::string& id, std::string& answer)
            {
                if (id.size() % 2 == 0)
                {
                    int middle = id.size() / 2;
                    std::string idPart1 = id.substr(0, middle);
                    std::string idPart2 = id.substr(middle, middle);

                    if (idPart1 == idPart2)
                    {
                        answer = AddTwoStringsAsNumbers(answer, id);
                    }
                }
            }
        );
}


std::string Day2::GetAnswerPart2()
{
    return Solve(
            [&](const std::string& id, std::string& answer)
            {
                int middle = id.size() / 2;
                if (middle == 0) return;

                for (int i = 1; i <= middle; i++)
                {
                    if (id.size() % i != 0) continue;
                    std::string idPart1 = id.substr(0, i);

                    std::string desiredStr;
                    int repeatTimes = id.size() / i;
                    desiredStr.reserve(idPart1.size() * repeatTimes);
                    for (int j = 0; j < repeatTimes; j++) {
                        desiredStr.append(idPart1);
                    }

                    if (desiredStr == id)
                    {
                        answer = AddTwoStringsAsNumbers(answer, id);
                        break;
                    }
                }
            }
        );
}

void Day2::TestData() const
{
    for (const std::array<std::string, 2>& ids: m_data)
    {
        std::cout << ids[0] << " " << ids[1] << std::endl;
    }
}

std::string Day2::Solve(const CheckerFunction& checker)
{
    std::string answer;

    std::for_each(std::execution::par, m_data.begin(), m_data.end(),
        [&](const std::array<std::string, 2>& ids)
        {
            std::string id = ids[0];

            while (true)
            {
                checker(id, answer);

                if (id == ids[1])
                    break;

                id = AddTwoStringsAsNumbers(id, "1");
            }
        });

    return answer;
}

void Day2::ProcessTextData()
{
    for (const std::string& text : m_textData)
    {
        std::stringstream ss(text);
        std::string id;
        std::array<std::string, 2> idArray{"", ""};

        int inx = 0;
        while (std::getline(ss, id, '-'))
        {
            idArray[inx] = id;
            ++inx;
        }

        m_data.push_back(idArray);
    }
}

