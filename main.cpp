#include <iostream>

#include <memory>


#include "day_1/day_1.h"
#include "day_2/day_2.h"
#include "day_3/day_3.h"
#include "day_4/day_4.h"
#include "day_5/day_5.h"

int main()
{
    /* DAY 1
    auto pDay1 = std::make_unique<Day1>("../day_1/data/data.txt");
    std::cout << "Answer to day 1 part 1: " << pDay1->GetAnswerPart1() << std::endl;
    std::cout << "Answer to day 1 part 2: " << pDay1->GetAnswerPart2() << std::endl;
    */

    /* DAY 2
    auto pDay2 = std::make_unique<Day2>("../day_2/data/data.txt");
    std::cout << "Answer to day 2 part 1: " << pDay2->GetAnswerPart1() << std::endl;
    std::cout << "Answer to day 2 part 2: " << pDay2->GetAnswerPart2() << std::endl;
    */

    /* DAY 3
    auto pDay3 = std::make_unique<Day3>("../day_3/data/data.txt");
    std::cout << "Answer to day 3 part 1: " << pDay3->GetAnswerPart1() << std::endl;
    std::cout << "Answer to day 3 part 2: " << pDay3->GetAnswerPart2() << std::endl;
    */

    /* DAY 4
    auto pDay4 = std::make_unique<Day4>("../day_4/data/data.txt");
    std::cout << "Answer to day 4 part 1: " << pDay4->GetAnswerPart1() << std::endl;
    std::cout << "Answer to day 4 part 2: " << pDay4->GetAnswerPart2() << std::endl;
    */

    auto pDay5 = std::make_unique<Day5>("../day_5/data/data.txt");
    std::cout << "Answer to day 5 part 1: " << pDay5->GetAnswerPart1() << std::endl;
    std::cout << "Answer to day 5 part 2: " << pDay5->GetAnswerPart2() << std::endl;


}
