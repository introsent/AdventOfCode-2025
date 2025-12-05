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

std::string DayBase::SubtractStringsAsNumbers(std::string str1, std::string str2)
{
    std::string result;
    int carry = 0; // here carry works as "borrow"

    // Reverse both strings to process from least significant digit
    std::ranges::reverse(str1);
    std::ranges::reverse(str2);

    int maxLength = std::max(static_cast<int>(str1.size()), static_cast<int>(str2.size()));

    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < str1.size()) ? (str1[i] - '0') : 0;
        int digit2 = (i < str2.size()) ? (str2[i] - '0') : 0;

        // Apply borrow
        digit1 -= carry;

        int diff;
        if (digit1 < digit2) {
            digit1 += 10;
            carry = 1; // we borrowed from next digit
        } else {
            carry = 0;
        }

        diff = digit1 - digit2;

        result += char(diff + '0');
    }

    // Reverse into correct order
    std::ranges::reverse(result);

    // Remove leading zeros (but keep one if result is zero)
    size_t nonZeroPos = result.find_first_not_of('0');
    if (nonZeroPos == std::string::npos)
        return "0";

    return result.substr(nonZeroPos);
}

int DayBase::compareIntegerStrings(std::string str1, std::string str2)
{
    // compare lengths
    if (str1.size() < str2.size()) return -1;
    if (str1.size() > str2.size()) return 1;

    // lexicographical compare
    if (str1 < str2) return -1;
    if (str1 > str2) return 1;

    return 0;
}
