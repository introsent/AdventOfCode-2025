#include <iostream>

#include "day_1/day_1.h"
#include <memory>

#include "day_2/day_2.h"

int main()
{
    /* DAY 1
    auto pDay1 = std::make_unique<Day1>("../day_1/data/data.txt");
    std::cout << "Answer to day 1 part 1: " << pDay1->GetAnswerPart1() << std::endl;
    std::cout << "Answer to day 1 part 2: " << pDay1->GetAnswerPart2() << std::endl;
    */

    auto pDay2 = std::make_unique<Day2>("../day_2/data/data.txt");
    std::cout << "Answer to day 2 part 1: " << pDay2->GetAnswerPart1() << std::endl;
    std::cout << "Answer to day 2 part 2: " << pDay2->GetAnswerPart2() << std::endl;
}
