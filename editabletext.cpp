#include "editabletext.h"

int EditableText::update_string(unsigned int n, std::string s){
    if(n > 0 && n <= this->length()){
        buffer[n-1] = parse_string(s);
        return 0;
    }
    return -1;
}

int EditableText::update_token(unsigned int n, unsigned int i, std::string s){
    if(n > 0 && n <= this->length()){
        if(i > 0 && i <= this->tok_length(n)){
            buffer[n-1][i-1] = parse_string(s)[0];
            return 0;
        }
    }
    return -1;
}
Position EditableText::search(std::string s){
    Position p{0,0};
    std::string pattern = parse_string(s)[0];
    bool flag = true;
    for(unsigned int n = 1; n<=length() && flag;n++){
        for(unsigned int i = 1;i <= tok_length(n);i++){
            if(get_token(n,i) == pattern){
                flag = false;
                p.n = n;
                p.i = i;
            }
        }
    }
    return p;
}
