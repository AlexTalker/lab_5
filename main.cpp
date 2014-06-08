#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "text.h"
#include "editabletext.h"
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{
    if(argc == 2){
        std::ifstream file{argv[1]};
        if(file.is_open()){
            std::string input, line;
            while(std::getline(file,line)){
                input += line + '\n';
            }
            EditableText text(input);
            char console;
            cin >> console;
            for(;console != 'q';cin >> console){
                switch (console) {
                case 'w':
                    //write
                    unsigned int n,i;
                    cout << "String(0) or Token(1)?";
                    cin >> i;
                    if(i == 0 || i == 1){
                        cout << "Nuber of string:";
                        cin >> n;
                        if(n > 0 && n < text.length()){
                            std::string temp;
                            if(i == 1){
                                cout << "Number of token:";
                                cin >> i;
                                if(i > 0 && i <= text.tok_length(n)){
                                    cout << "Input a token:";
                                    cin >> temp;
                                    cout << (text.update_token(n,i,temp)?"Fail!\n":"Success!\n");
                                }
                            }else{
                                cout << "Input a string:";
                                cin >> temp;
                                cout << (text.update_string(n,temp)?"Fail!\n":"Success!\n");
                            }
                        }
                    }
                    break;
                case 'r':{
                    //read
                    char c = ' ';
                    cout << "What do you want read: (s)tring or (t)oken?";
                    cin >> c;
                    unsigned int n = 0;
                    cout << "Input a number of string:";
                    if(c == 's'){
                        cin >> n;
                        cout << text.string(n) << endl;
                    }
                    else if(c == 't'){
                        unsigned int i;
                        cout << "Input a token number:";
                        cin >> i;
                        Position p = {n,i};
                        cout << ((text.get_token(p) == "")?"String empty or not included.":text.get_token(p)) << endl;
                    }
                    else{
                        cout << "Oops, your did bad choice" << c << "." << endl;
                    }
                }
                    break;
                case 's':{
                    //save
                    std::string file_path = "";
                    cout << "Input a path:";
                    cin >> file_path;
                    if(!file_path.empty()){
                        unsigned int i = 0;
                        cout << "Do you really have overwrite file" << file_path << "?(1 - yes, 0 - no)";
                        cin >> i;
                        if(i == 1){
                            std::ofstream file(file_path, std::ios::out|std::ios::trunc);
                            if(file.is_open()){
                                file << text.strings();
                            }
                            else{
                                cout << "Fail to open file!";
                            }
                            file.close();
                        }
                    }
                    else{
                        cout << "Empty path!";
                    }
                }
                    break;
                case 'f':{
                    //file info
                    char c = ' ';
                    cout << "What information you want get: amount of (s)trings or (t)okens in string?";
                    cin >> c;
                    if(c == 's'){
                        cout << "Amount of strings in file:" << text.length() << endl;
                    }
                    else if( c == 't'){
                        unsigned int n = 0;
                        cout << "Input a string number:";
                        cin >> n;
                        cout << "Amount tokens in string " << n << ":" << text.tok_length(n) << endl;
                    }
                    else{
                        cout << "Sorry, i nothing know about " << c << endl;
                    }
                }
                    break;
                case 'h':
                    //help
                    cout << "Write a:\n"
                         << "w - call write menu" << endl
                         << "r - call read menu" << endl
                         << "s - call save menu" << endl
                         << "f - call file menu" << endl
                         << "h - call this menu" << endl;
                    break;
                default:
                    cout << "Bad input, try write symbol h." << endl;
                    break;
                }
            }
        }
        else{
            cout << "File can't be open." << endl;
            return -1;
        }
    }
    else{
        cout << "No file for edit!" << endl;
    }
    return 0;
}
