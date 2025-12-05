//
// Created by ivans on 04/12/2025.
//

#ifndef Y2025_ADVENTOFCODE_DAY_5_H
#define Y2025_ADVENTOFCODE_DAY_5_H
#include <set>
#include <string>
#include <vector>
#include "../day_base.h"
#include <array>

class Day5 : public DayBase
{
public:
    explicit Day5(std::string filename);

    int GetAnswerPart1();
    std::string GetAnswerPart2();

    static bool isIntegerStringInRange(const std::string& value,
                                       const std::string& low,
                                       const std::string& high);
private:
    std::vector<std::string> m_data;
    std::vector<std::array<std::string, 2>> m_boundsArray;
    std::set<std::string> m_ingredientIDs;
};




#endif //Y2025_ADVENTOFCODE_DAY_5_H