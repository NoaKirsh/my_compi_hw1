#include <iostream>
#include <stdio.h>
#include <algorithm>

#define watch(x) #x

std::string replace(std::string string, std::string src, std::string dst){
    std::string::size_type n = 0;
    while ((n = string.find(src, n)) != std::string::npos)
    {
        string.replace( n, src.size(), dst);
        n += dst.size();
    }
    return string;
}



int main_yy() {

//    std::string string("Hello \\x57orld!\\r\\nThis\\tis\\t\\x63oo\\x6C, as always");
    std::string string("\\\"");
    std::cout << "\\\"" << std::endl;
    std::cout << replace(string, "\\\"", "\"");


//    char* str = "Hello \x57orld!\r\nThis\tis\t\x63oo\x6C, as always";
//    std::string new_str = std::string(str);
////    std::cout << str << std::endl;
//    std::cout << new_str << std::endl;
//    printf("Hello \x57orld!\r\nThis\tis\t\x63oo\x6C, as always", new_str);
//
//    replace(new_str, "\\", "\\\\");
//    std::cout << new_str << std::endl;

//    std::cout << "Hello \x57orld!\r\nThis\tis\t\x63oo\x6C, as always" << std::endl; //given
//    std::cout << "Hello \\x57orld!\\r\\nThis\\tis\\t\\x63oo\\x6C, as always" << std::endl; // expected
    return 0;
}