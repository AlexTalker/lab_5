#ifndef EDITABLETEXT_H
#define EDITABLETEXT_H
#include "text.h"
struct Position{
    unsigned int n,i;
};
class EditableText: public Text{
public:
    int update_string(unsigned int n, std::string s);
    int update_token(unsigned int n, unsigned int i, std::string s);
    Position search(std::string);
};

#endif // EDITABLETEXT_H
