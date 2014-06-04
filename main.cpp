#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "text.h"
#include "editabletext.h"

int main()
{
    std::string input, line;
    std::ifstream file{"test.txt"};
    while(std::getline(file,line)){
        input += line + '\n';
    }
    Text t(input);
    Text b("Hello, world!");
    std::cout << input.c_str() << std::endl << (t == t) << std::endl << (t != t) << std::endl;
    b = t;
    std::cout << b.strings() << std::endl;
    return 0;
    //divide
//    std::string input, line;
//    while (std::getline(std::cin, line))
//    {
//        input += line + '\n';
//    }
//    Text t = Text(input);
//    std::cout << "Time for input number of string";
//    unsigned int n = 0;
//    std::cin >> n;
//    std::cout << t.string(n);
//    return 0;
// ======================== divide old and new code ===================
//    //divide
//    std::vector<std::vector<std::string>> buffer;

//    std::string input;
//    std::string line;
//    while (std::getline(std::cin, line))
//    {
//        input += line + '\n';
//    }
//    std::istringstream lines(input);

//    while (std::getline(lines, line))
//    {
//        buffer.emplace_back(std::vector<std::string>{});
//        std::istringstream lexes(line);
//        std::string lex;
//        while (lexes >> lex)
//        {
//            buffer.back().push_back(std::move(lex));
//        }
//    }
//    //multiple
//    std::string glued;
//    std::for_each(std::begin(buffer[0]), std::end(buffer[0]), [&](std::string& s) { glued = glued + s + ' ';});
//    glued.resize(glued.length() - 1);
//    std::cout << glued;
}
