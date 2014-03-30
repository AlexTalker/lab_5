#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <vector>

class Text
{
protected:
    std::vector<std::vector<std::string>> buffer;
    std::string multiple(std::vector<std::string> v);
public:
    Text(std::string input);
    std::size_t length();
    std::string string(unsigned int i);
};

#endif // TEXT_H
