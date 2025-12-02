//
// Created by ivans on 02/12/2025.
//

#ifndef Y2025_ADVENTOFCODE_DAY_2_H
#define Y2025_ADVENTOFCODE_DAY_2_H
#include "../day_base.h"
#include <array>
#include <functional>

class Day2 : DayBase
{
public:
    explicit Day2(std::string filename);

    std::string GetAnswerPart1();
    std::string GetAnswerPart2();

    void TestData() const;
private:
    using CheckerFunction = std::function<void(const std::string& id, std::string& answer)>;

    std::string Solve(const CheckerFunction& checker);
    void ProcessTextData();
    static std::string AddTwoStringsAsNumbers(std::string str1, std::string str2);

    std::vector<std::string> m_textData;
    std::vector<std::array<std::string, 2>> m_data;
};


#endif //Y2025_ADVENTOFCODE_DAY_2_H