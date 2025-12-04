//
// Created by ivans on 01/12/2025.
//

#include "day_base.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

DayBase::DayBase(std::string filename) : m_filename(std::move(filename))
{

}

std::vector<std::string> DayBase::GetPerLineTextData() const
{
    std::vector<std::string> lines;

    std::ifstream file(m_filename);
    if (!file.is_open()) std::cerr << "Error opening file " << m_filename << std::endl;

    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}

std::vector<std::string> DayBase::GetPerDelimiterTextData(std::string delimiter) const
{
    std::vector<std::string> data;

    std::ifstream file(m_filename);
    if (!file.is_open()) std::cerr << "Error opening file " << m_filename << std::endl;

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string temporary;
        while (std::getline(ss, temporary, delimiter[0]))
        {
            data.push_back(temporary);
        }
    }
    return data;
}

std::vector<std::vector<char>> DayBase::GetPerCharacter2dArrayTextData() const
{
    std::vector<std::vector<char>> data;

    std::ifstream file(m_filename);
    if (!file.is_open()) std::cerr << "Error opening file " << m_filename << std::endl;

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<char> chars;
        std::ranges::for_each(line.begin(), line.end(), [&chars](auto ch)
        {
            chars.push_back(std::move(ch));
        });

        data.emplace_back(std::move(chars));
    }

    return data;
}

std::string DayBase::AddTwoStringsAsNumbers(std::string str1, std::string str2)
{
    std::string result;
    int carry = 0;

    // Reverse both strings to process from least significant digit
    std::ranges::reverse(str1);
    std::ranges::reverse(str2);

    int maxLength = std::max(static_cast<int>(str1.size()), static_cast<int>(str2.size()));

    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < str1.size()) ? (str1[i] - '0') : 0;
        int digit2 = (i < str2.size()) ? (str2[i] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10; // carry
        result += char(sum % 10) + '0'; // append digit
    }

    // append remaining carry if there is one
    if (carry) {
        result += char(carry + '0');
    }

    // Reverse the result to get the correct order
    std::ranges::reverse(result);
    return result;

}
