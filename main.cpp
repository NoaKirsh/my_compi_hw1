#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#define watch(x) #x
#include "tokens.hpp"

bool in_hex_range(char tmp[3]){
    return ('0' < tmp[0] && tmp[0] < '7') && (('0' <= tmp[1] && tmp[1] <= '9') ||
            ('a' <= tmp[1] && tmp[1] <= 'f') || ('A' <= tmp[1] && tmp[1] <= 'F'));
}

void handle_hex(std::string str) {
    int size = str.size();
    char buffer[size];
    int  bf_itr = 0;

    for(std::string::size_type i = 0; i < size; i++, bf_itr++){
        char c = str[i];
        if(str[i] == '\\') {
            c = str[++i];
            bool hex_range;
            switch (c) //checking what comes after \.
            {
                case 'x':
                    char tmp[3];
                    tmp[0] = str[++i];
                    tmp[1] = str[++i];
                    tmp[2] = '\0';
                    hex_range = in_hex_range(tmp);
                    if(hex_range) {
                        c = (char) strtoul(tmp, NULL, 16);
                        break;
                    }else {
                        std::cout << "Error undefined escape sequence " << str.substr(i-3, 4) << std::endl;
                        return ;
                    }
                case '0':
                    std::cout << yylineno << " STRING " << str.substr(0, i) << std::endl;
                    return;
                case 'r': c = '\r'; break;
                case 't': c = '\t'; break;
                case 'n': c = '\n'; break;
                case '"': c = '\"'; break;
                case '\\': break;
                default: {}
                    std::cout << "Error undefined escape sequence " << str.substr(i-1, 2) << std::endl;
                    return;
            }
        }
        buffer[bf_itr] = c;
    }
    buffer[bf_itr] = '\0';
    std::cout << yylineno << " STRING " << buffer << std::endl;
}

int main() {
    std::string s = "\\x13";
    handle_hex(s);
//    char a = '5';
//    char b = '7';
//    int num = get_hex_value(a, b);
//    std::cout << num << std::endl;
}