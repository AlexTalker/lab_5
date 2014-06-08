#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <vector>
struct Position{
    unsigned int n,i;
};

class Text
{
protected:
    std::vector<std::vector<std::string>> buffer;
    std::vector<std::vector<std::string>> parser(std::string);
    std::string multiple(std::vector<std::string>);
    std::vector<std::string> parse_string(std::string line);
public:
    Text(std::string input = "");
    //количество строк
    std::size_t length();
    //количество лексем
    std::size_t tok_length(unsigned int);
    //получить токен
    std::string get_token(Position p);
    //забрать содержимое одной строки
    std::string string(unsigned int);
    //забрать все строкой
    std::string strings(void);
    // overload operators
    bool operator==(Text&);
    bool operator!=(Text&);
    Text& operator=(Text&);
    std::string operator[](unsigned int);
};

#endif // TEXT_H
