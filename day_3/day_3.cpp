//
// Created by ivans on 03/12/2025.
//

#include "day_3.h"

#include <algorithm>
#include <iostream>
#include <ostream>

Day3::Day3(std::string filename) : DayBase(std::move(filename))
{
    m_data = GetPerLineTextData();
}

int Day3::GetAnswerPart1()
{
    int answer = 0;
    for (const auto& joltage : m_data)
    {
        std::string stringForMax = joltage.substr(0, joltage.length() - 1);
        auto maxEl = std::ranges::max_element( stringForMax );
        const auto maxElPos = std::ranges::distance(stringForMax.begin(), maxEl);

        std::string subString = joltage.substr(maxElPos + 1);
        auto nextMaxEl = std::ranges::max_element(subString);

        answer += std::stoi(std::string{*maxEl, *nextMaxEl});
    }
    return answer;
}