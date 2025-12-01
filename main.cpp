#include <iostream>

#include "day_1/day_1.h"
#include <memory>
int main()
{
    std::unique_ptr<Day1> pDay1 = std::make_unique<Day1>("../day_1/data/data.txt");
    std::cout << "Answer to day 1 part 1: " << pDay1->GetAnswerPart1() << std::endl;
    std::cout << "Answer to day 1 part 2: " << pDay1->GetAnswerPart2() << std::endl;
}