#ifndef EDITABLETEXT_H
#define EDITABLETEXT_H
#include "text.h"
class EditableText: public Text{
public:
    EditableText(std::string s) : Text(s){}
    int update_string(unsigned int n, std::string s);
    int update_token(unsigned int n, unsigned int i, std::string s);
    Position search(std::string);
};

#endif // EDITABLETEXT_H
