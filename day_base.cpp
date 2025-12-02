//
// Created by ivans on 01/12/2025.
//

#include "day_base.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

DayBase::DayBase(std::string filename) : m_filename(std::move(filename))
{

}

std::vector<std::string> DayBase::GetPerLineTextData() const
{
    std::vector<std::string> lines;

    std::ifstream file(m_filename);
    if (!file.is_open()) std::cerr << "Error opening file " << m_filename << std::endl;

    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}

std::vector<std::string> DayBase::GetPerDelimiterTextData(std::string delimiter) const
{
    std::vector<std::string> data;

    std::ifstream file(m_filename);
    if (!file.is_open()) std::cerr << "Error opening file " << m_filename << std::endl;

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string temporary;
        while (std::getline(ss, temporary, delimiter[0]))
        {
            data.push_back(temporary);
        }
    }
    return data;
}
