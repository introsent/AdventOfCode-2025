//
// Created by ivans on 01/12/2025.
//

#include "day_1.h"

#include <iostream>
#include <utility>

Day1::Day1(std::string filename) : DayBase(std::move(filename))
{
    m_data = GetPerLineTextData();
}

int Day1::GetAnswer()
{
    int answer = 0;
    for (const auto& line : m_data)
    {
        char firstPart = line[0];
        int secondPart = std::stoi(line.substr(1));

        if (firstPart == 'L')
        {
            m_position -= (secondPart % 100);
            if (m_position < 0)
            {
                m_position = 100 + m_position;
            }
        }
        if (firstPart == 'R')
        {
            m_position += (secondPart % 100);
            if (m_position > 99)
            {
                m_position = m_position - 100;
            }
        }

        std::cout << m_position << std::endl;
        if (m_position == 0)
        {
            answer++;
        }
    }

    return answer;
}


