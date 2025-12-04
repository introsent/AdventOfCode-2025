//
// Created by ivans on 04/12/2025.
//

#ifndef Y2025_ADVENTOFCODE_DAY_4_H
#define Y2025_ADVENTOFCODE_DAY_4_H
#include <string>
#include <vector>
#include "../day_base.h"


class Day4 : public DayBase
{
public:
    explicit Day4(std::string filename);

    int GetAnswerPart1();
    int GetAnswerPart2();

    static constexpr int OFFSETS[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };
    const int ROLL_OF_PAPERS { 4 };
private:
    std::vector<std::vector<char>> m_data;

};




#endif //Y2025_ADVENTOFCODE_DAY_4_H