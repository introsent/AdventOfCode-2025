//
// Created by ivans on 02/12/2025.
//

#ifndef Y2025_ADVENTOFCODE_DAY_2_H
#define Y2025_ADVENTOFCODE_DAY_2_H
#include "../day_base.h"
#include <array>

class Day2 : DayBase
{
public:
    explicit Day2(std::string filename);

    int GetAnswerPart1();
    int GetAnswerPart2();

    void TestData() const;
private:
    void ProcessTextData();

    std::vector<std::string> m_textData;
    std::vector<std::array<int, 2>> m_data;
};


#endif //Y2025_ADVENTOFCODE_DAY_2_H