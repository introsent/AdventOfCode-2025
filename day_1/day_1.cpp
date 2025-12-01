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

int Day1::GetAnswerPart1()
{
    ResetPosition();
    int answer = 0;

    for (const auto& instruction : m_data)
    {
        ProcessInstruction(instruction);
        if (IsAtZero())
        {
            answer++;
        }
    }
    return answer;
}

int Day1::GetAnswerPart2()
{
    ResetPosition();
    int answer = 0;
    for (const auto& line : m_data)
    {
        char firstPart = ParseDirection(line);
        int secondPart = ParseSteps(line);
        int currentPosition = m_position;

        answer += secondPart / BOUNDS; // integer division
        if (firstPart == 'L')
        {
            m_position -= (secondPart % 100);
            if (m_position < 0)
            {
                m_position = BOUNDS + m_position;

                if (currentPosition != 0 && m_position != 0)
                {
                    answer++;
                }
            }
        }
        if (firstPart == 'R')
        {
            m_position += (secondPart % BOUNDS);
            if (m_position > BOUNDS - 1)
            {

                m_position = m_position - BOUNDS;

                if (currentPosition != 0 && m_position != 0)
                {
                    answer++;
                }
            }
        }

        if (IsAtZero())
        {
            answer++;
        }
    }

    return answer;
}

char Day1::ParseDirection(const std::string& instruction)
{
    return instruction[0];
}

int Day1::ParseSteps(const std::string& instruction)
{
    return std::stoi(instruction.substr(1));
}

void Day1::Rotate(int steps)
{
    m_position = (m_position + steps) % BOUNDS;
    if (m_position < 0) m_position += BOUNDS;
}

void Day1::ProcessInstruction(const std::string& instruction)
{
    char direction = ParseDirection(instruction);
    int steps = ParseSteps(instruction);

    if (direction == 'L')
    {
        Rotate(-steps);
    }
    else if (direction == 'R')
    {
        Rotate(steps);
    }
}

bool Day1::IsAtZero() const
{
    return m_position == 0;
}


