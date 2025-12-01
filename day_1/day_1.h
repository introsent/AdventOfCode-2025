//
// Created by ivans on 01/12/2025.
//

#ifndef Y2025_ADVENTOFCODE_DAY_1_H
#define Y2025_ADVENTOFCODE_DAY_1_H
#include <string>
#include "../day_base.h"


class Day1 : public DayBase
{
public:
    explicit Day1(std::string filename);

    int GetAnswer();
private:
    std::vector<std::string> m_data;
    int m_position { 50 };
};


#endif //Y2025_ADVENTOFCODE_DAY_1_H