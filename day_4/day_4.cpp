//
// Created by ivans on 04/12/2025.
//

#include "day_4.h"

#include <algorithm>

Day4::Day4(std::string filename) : DayBase(std::move(filename))
{
    m_data = GetPerCharacter2dArrayTextData();
}

int Day4::GetAnswerPart1()
{
    int answer = 0;
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        for (std::size_t j = 0; j < m_data[i].size(); ++j) {

            if (m_data[i][j] == '.') continue;

            int arCounter = 0;

            // iterate through neighbors
            for (auto& off : OFFSETS) {
                int ni = static_cast<int>(i) + off[0];
                int nj = static_cast<int>(j) + off[1];

                // bounds check
                if (ni < 0 || nj < 0) continue;
                if (ni >= static_cast<int>(m_data.size())) continue;
                if (nj >= static_cast<int>(m_data[ni].size())) continue;

                if (m_data[ni][nj] == '@') {
                    arCounter++;
                }
            }
            if (arCounter < ROLL_OF_PAPERS)
            {
                answer++;
            }
        }
    }
    return answer;
}

int Day4::GetAnswerPart2()
{
    bool canAccessMore = true;
    while (canAccessMore)
    {
        int amountCanBeRemoved = 0;
        for (std::size_t i = 0; i < m_data.size(); ++i) {
            for (std::size_t j = 0; j < m_data[i].size(); ++j) {

                if (m_data[i][j] == '.' || m_data[i][j] == 'x') continue;

                int arCounter = 0;

                // iterate through neighbors
                for (auto& off : OFFSETS) {
                    int ni = static_cast<int>(i) + off[0];
                    int nj = static_cast<int>(j) + off[1];

                    // bounds check
                    if (ni < 0 || nj < 0) continue;
                    if (ni >= static_cast<int>(m_data.size())) continue;
                    if (nj >= static_cast<int>(m_data[ni].size())) continue;

                    if (m_data[ni][nj] == '@') {
                        arCounter++;
                    }
                }
                if (arCounter < ROLL_OF_PAPERS)
                {
                    m_data[i][j] = 'x';
                    amountCanBeRemoved++;
                }
            }
        }
        if (amountCanBeRemoved == 0)
        {
            canAccessMore = false;
        }
    }

    int answer = 0;
    for (const auto& row : m_data) {
        answer += static_cast<int>(std::ranges::count(row, 'x'));
    }

    return answer;
}
