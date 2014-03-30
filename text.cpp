#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "text.h"

std::string Text::multiple(std::vector<std::string> v)
{
    //concatenate some vector tokens in one string with spaces
    std::string glued;
    std::for_each(std::begin(v), std::end(v), [&](std::string& s) { glued += s + ' ';});
//  glued.resize(glued.length() - 1);
    return glued;
}

Text::Text(std::string input)
{
    //divide input to by vector string, trings divided by tokens
    std::string line;
    std::istringstream lines(input);
    while (std::getline(lines, line))
    {
        buffer.emplace_back(std::vector<std::string>{});
        std::istringstream lexes(line);
        std::string lex;
        while (lexes >> lex)
        {
            buffer.back().push_back(std::move(lex));
        }
    }
}

std::size_t Text::length()
{
    return buffer.size();
}

std::string Text::string(unsigned int i)
{
    return (i < this->length() && i > 0)?this->multiple(buffer[i-1]):"";
}
