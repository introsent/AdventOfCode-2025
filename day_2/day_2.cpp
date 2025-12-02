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
    std::string answer;

    std::for_each(std::execution::par, m_data.begin(), m_data.end(),
          [&answer](const std::array<std::string, 2>& ids)
          {
              std::string id = ids[0];

              while (true)
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

                  if (id == ids[1])
                      break;

                  id = AddTwoStringsAsNumbers(id, "1");
              }
          });
    return answer;
}

int Day2::GetAnswerPart2()
{
    return 0;
}

void Day2::TestData() const
{
    for (const std::array<std::string, 2>& ids: m_data)
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

std::string Day2::AddTwoStringsAsNumbers(std::string str1, std::string str2)
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

