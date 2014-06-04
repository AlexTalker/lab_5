#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "text.h"

Text::Text(std::string input)
{
    buffer = this->parser(input);
}

std::size_t Text::length()
{
    return buffer.size();
}

std::size_t Text::tok_length(unsigned int n)
{
    return buffer[n-1].size();
}

std::string Text::get_token(unsigned int n, unsigned int i)
{
    std::string result = "";
    if(0 < n && n <= this->length()){
        if(0 < i && i <= buffer[n-1].size()){
            result = buffer[n-1][i-1];
        }
    }
    return result;
}

std::string Text::string(unsigned int i)
{
    return (i < this->length() && i > 0)?this->multiple(buffer[i-1]):"";
}

std::string Text::strings()
{
    std::string temp;
    for(unsigned int i = 0; i < buffer.size();){
        temp += string(++i);
    }
    return temp;
}

std::vector<std::vector<std::string> > Text::parser(std::string str)
{
    std::vector<std::vector<std::string>> result;
    std::string line;
    std::istringstream lines(str);
    while (std::getline(lines, line))
    {
        //result.emplace_back(std::vector<std::string>{});
        result.push_back(parse_string(line));
    }
    return result;
}

std::vector<std::string> Text::parse_string(std::string line){
    std::istringstream lexes(line);
    std::string lex;
    std::vector<std::string> result;
    while (lexes >> lex)
    {
        result.push_back(std::move(lex));
    }
    return result;
}

std::string Text::multiple(std::vector<std::string> v)
{
    //concatenate some vector tokens in one string with spaces
    std::string glued;
    std::for_each(std::begin(v), std::end(v), [&](std::string& s) { glued += s + ' ';});
    //  glued.resize(glued.length() - 1);
    return glued;
}

bool Text::operator==(Text& t)
{
    if(this->length() == t.length())
    {
        for(unsigned int i = 1; i <= this->length();i++)
        {
            if(this->tok_length(i) == t.tok_length(i)){
                for(unsigned int j = 1;j <= this->tok_length(i);j++)
                {
                    if(this->get_token(i,j) == t.get_token(i,j))
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
bool Text::operator!=(Text& t){
    return !(*this == t);
}

Text &Text::operator=(Text & right)
{
    this->buffer = parser(right.strings());
    return *this;
}

std::string Text::operator[](unsigned int n){
    return this->multiple(buffer[n-1]);
}
