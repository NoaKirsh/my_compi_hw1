#include <iostream>
#include <stdio.h>
#include <algorithm>

#define watch(x) #x

std::string handle_hex(std::string str) {
    for (int i = 0; i <= 0xFF; i++) {
        printf("%x\n", i);
        std::string i_str = std::to_string(i);
//        str = replace(str.begin(), str.end(), i_str, i);
    }
}

int maisn() {
    std::string s = "Hello \\x57orld!\\r\\nThis\\tis\\t\\x63oo\\x6C, as always";
    handle_hex(s);
}