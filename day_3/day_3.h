//
// Created by ivans on 03/12/2025.
//

#ifndef Y2025_ADVENTOFCODE_DAY_3_H
#define Y2025_ADVENTOFCODE_DAY_3_H
#include <string>
#include <vector>
#include "../day_base.h"


class Day3 : public DayBase
{
public:
    explicit Day3(std::string filename);

    int GetAnswerPart1();
    int GetAnswerPart2();

private:
    std::vector<std::string> m_data;
};



#endif //Y2025_ADVENTOFCODE_DAY_3_H
