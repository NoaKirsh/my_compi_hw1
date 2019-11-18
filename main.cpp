#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#define watch(x) #x
//
//void after_backslash(std::string next_char){
//    switch(next_char){
//        case '\"': return "\"";
//        case '\\': return "\\";
//        case 'n': return "\n";
//        case 'n': return "\n";
//        case 'n': return "\n";
//        case 'n': return "\n";
//    }
//}

int get_hex_value(char a, char b){
    if('0' <= b && b <= '9')
        return 16*(a-'0') + (b-'0');
    else
        return 16*(a-'0') + (tolower(b)-'a');
}

std::string handle_hex(std::string str) {
    int size = str.size();
    char buffer[size];
    int  bf_itr = 0;
    for(std::string::size_type i = 0; i < size; i++, bf_itr++){

        char c = str[i];
        if(str[i] == '\\') {
            c = str[++i];
            switch (c)
            {
                case 'x':
                    char tmp[3];
                    tmp[0] = str[++i];
                    tmp[1] = str[++i];
                    tmp[2] = '\0';
                    c = (char)strtoul(tmp, NULL, 16);
                    break;
                case 'r': c = '\r'; break;
                case 't': c = '\t'; break;
                case 'n': c = '\n'; break;
                case '0': c = '\0'; break;
                case '"': c = '\"'; break;
                case '\\': break;
                default: {}
                    // TODO: Excpetion / Error
            }
        }
        buffer[bf_itr] = c;
    }
    buffer[bf_itr] = '\0';
    return std::string(buffer);
}

int main() {
    std::string s = "Hello \\x57orld!\\r\\nThis\\tis\\t\\x63oo\\x6C, as always";
    std::cout << handle_hex(s) << std::endl;
//    char a = '5';
//    char b = '7';
//    int num = get_hex_value(a, b);
//    std::cout << num << std::endl;
}