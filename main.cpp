#include <iostream>

#include "day_1/day_1.h"
#include <memory>
int main()
{
    std::unique_ptr<Day1> pDay1 = std::make_unique<Day1>("../day_1/data/data.txt");
    int answerDay1 = pDay1->GetAnswer();
    std::cout << "Answer to day 1: " << answerDay1 << std::endl;
}