//
// Created by ivans on 01/12/2025.
//

#ifndef Y2025_ADVENTOFCODE_DAY_BASE_H
#define Y2025_ADVENTOFCODE_DAY_BASE_H
#include <string>
#include <vector>

class DayBase
{
public:
    explicit DayBase(std::string filename);
protected:
    [[nodiscard]] std::vector<std::string> GetPerLineTextData() const;
    [[nodiscard]] std::vector<std::string> GetPerDelimiterTextData(std::string delimiter) const;
    [[nodiscard]] std::vector<std::vector<char>> GetPerCharacter2dArrayTextData() const;

    static std::string AddTwoStringsAsNumbers(std::string str1, std::string str2);
private:
    std::string m_filename;
};
#endif //Y2025_ADVENTOFCODE_DAY_BASE_H