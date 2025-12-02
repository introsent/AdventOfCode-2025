//
// Created by ivans on 02/12/2025.
//

#include "day_2.h"

#include <iostream>
#include <sstream>

Day2::Day2(std::string filename) : DayBase(std::move(filename))
{
    m_textData = GetPerDelimiterTextData(",");
    ProcessTextData();
}

int Day2::GetAnswerPart1()
{
    return 0;
}

int Day2::GetAnswerPart2()
{
    return 0;
}

void Day2::TestData() const
{
    for (const std::array<int, 2>& ids: m_data)
    {
        std::cout << ids[0] << " " << ids[1] << std::endl;
    }
}

void Day2::ProcessTextData()
{
    for (const std::string& text : m_textData)
    {
        std::stringstream ss(text);
        std::string id;
        std::array<int, 2> idArray{0, 0};

        int inx = 0;
        while (std::getline(ss, id, '-'))
        {
            idArray[inx] = std::stoi(id);
            ++inx;
        }

        m_data.push_back(idArray);
    }
}
