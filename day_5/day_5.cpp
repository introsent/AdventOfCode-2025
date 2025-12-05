//
// Created by ivans on 04/12/2025.
//

#include "day_5.h"

#include <algorithm>
#include <iostream>

Day5::Day5(std::string filename) : DayBase(std::move(filename))
{
    m_data = GetPerLineTextData();
}

int Day5::GetAnswerPart1()
{
    int answer = 0;

    bool isEmptyLineFound = false;
    for (const auto& line : m_data)
    {
        if (line.empty())
        {
            isEmptyLineFound = true;
            continue;
        }

        if (!isEmptyLineFound)
        {
            size_t delimiterPos = line.find("-");
            if (delimiterPos == std::string::npos)
            {
                std::cerr << "Delimiter not found in the line.\n";
            }

            std::string part1 = line.substr(0, delimiterPos);
            std::string part2 = line.substr(delimiterPos + 1);

            m_boundsArray.push_back(std::array<std::string, 2>{part1, part2});
        }
        else
        {
            for (const auto& bound : m_boundsArray)
            {
                if (isIntegerStringInRange(line, bound[0], bound[1]))
                {
                    answer++;
                    break;
                }
            }
        }
    }

    return answer;
}

std::string Day5::GetAnswerPart2()
{
    if (m_boundsArray.empty())
    {
        for (const auto& line : m_data)
        {
            if (line.empty())
            {
                break;
            }
            size_t delimiterPos = line.find("-");
            if (delimiterPos == std::string::npos)
            {
                std::cerr << "Delimiter not found in the line.\n";
            }

            std::string part1 = line.substr(0, delimiterPos);
            std::string part2 = line.substr(delimiterPos + 1);

            m_boundsArray.push_back(std::array<std::string, 2>{part1, part2});
        }
    }

    // Sort by lower bound
    std::ranges::sort(m_boundsArray,
                      [&](const auto& a, const auto& b)
                      {
                          return compareIntegerStrings(a[0], b[0]) < 0;
                      });

    std::string currentLow  = m_boundsArray[0][0];
    std::string currentHigh = m_boundsArray[0][1];

    std::string total = "0";

    for (int i = 1; i < m_boundsArray.size(); i++)
    {
        const std::string& low  = m_boundsArray[i][0];
        const std::string& high = m_boundsArray[i][1];

        // expandedHigh = currentHigh + 1
        std::string expandedHigh = AddTwoStringsAsNumbers(currentHigh, "1");

        // Overlapping or touching
        if (compareIntegerStrings(low, expandedHigh) <= 0)
        {
            if (compareIntegerStrings(high, currentHigh) > 0)
                currentHigh = high;
        }
        else
        {
            // Add length of finished interval
            std::string diff = SubtractStringsAsNumbers(currentHigh, currentLow);
            diff = AddTwoStringsAsNumbers(diff, "1");
            total = AddTwoStringsAsNumbers(total, diff);

            // Start new interval
            currentLow  = low;
            currentHigh = high;
        }
    }
    // Final interval
    {
        std::string diff = SubtractStringsAsNumbers(currentHigh, currentLow);
        diff = AddTwoStringsAsNumbers(diff, "1");
        total = AddTwoStringsAsNumbers(total, diff);
    }

    return total;
}

bool Day5::isIntegerStringInRange(const std::string& value, const std::string& low, const std::string& high)
{
    return compareIntegerStrings(value, low) >= 0 &&
         compareIntegerStrings(value, high) <= 0;
}



