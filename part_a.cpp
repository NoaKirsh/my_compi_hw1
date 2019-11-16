#include "tokens.hpp"
#include <string>
#include <ostream>
#include <iostream>
#include <cstring>
#include <string.h>
#include <regex>

//---------------------------- helper functions ----------------------------------------------

#define watch(x) #x


void showToken(const char * token_name, int num_line)
{
    printf("%d %s %s\n", num_line, token_name, yytext);
}

std::string replace(std::string string, std::string src, std::string dst){
    std::string::size_type len = 0;
    while ((len = string.find(src, len)) != std::string::npos)
    {
        string.replace(len, src.size(), dst);
        len += dst.size();
    }
    return string;
}

std::string handle_hex(std::string str){
    str = replace(str, "\\x20", " ");
    str = replace(str, "\\x21", "!");
    str = replace(str, "\\x22", "\"");
    str = replace(str, "\\x23", "#");
    str = replace(str, "\\x24", "$");
    str = replace(str, "\\x25", "%");
    str = replace(str, "\\x26", "&");
    str = replace(str, "\\x27", "\'");
    str = replace(str, "\\x28", ")");
    str = replace(str, "\\x29", "(");
    str = replace(str, "\\x2A", "*");
    str = replace(str, "\\x2B", "+");
    str = replace(str, "\\x2C", ",");
    str = replace(str, "\\x2D", "-");
    str = replace(str, "\\x2E", ".");
    str = replace(str, "\\x2F", "/");
    str = replace(str, "\\x2a", "*");
    str = replace(str, "\\x2b", "+");
    str = replace(str, "\\x2c", ",");
    str = replace(str, "\\x2d", "-");
    str = replace(str, "\\x2e", ".");
    str = replace(str, "\\x2f", "/");

    str = replace(str, "\\x30", "0");
    str = replace(str, "\\x31", "1");
    str = replace(str, "\\x32", "2");
    str = replace(str, "\\x33", "3");
    str = replace(str, "\\x34", "4");
    str = replace(str, "\\x35", "5");
    str = replace(str, "\\x36", "6");
    str = replace(str, "\\x37", "7");
    str = replace(str, "\\x38", "8");
    str = replace(str, "\\x39", "9");
    str = replace(str, "\\x3A", ":");
    str = replace(str, "\\x3B", ";");
    str = replace(str, "\\x3C", "<");
    str = replace(str, "\\x3D", "=");
    str = replace(str, "\\x3E", ">");
    str = replace(str, "\\x3F", "?");
    str = replace(str, "\\x3a", ":");
    str = replace(str, "\\x3b", ";");
    str = replace(str, "\\x3c", "<");
    str = replace(str, "\\x3d", "=");
    str = replace(str, "\\x3e", ">");
    str = replace(str, "\\x3f", "?");

    str = replace(str, "\\x40", "@");
    str = replace(str, "\\x41", "A");
    str = replace(str, "\\x42", "B");
    str = replace(str, "\\x43", "C");
    str = replace(str, "\\x44", "D");
    str = replace(str, "\\x45", "E");
    str = replace(str, "\\x46", "F");
    str = replace(str, "\\x47", "G");
    str = replace(str, "\\x48", "H");
    str = replace(str, "\\x49", "I");
    str = replace(str, "\\x4A", "J");
    str = replace(str, "\\x4B", "K");
    str = replace(str, "\\x4C", "L");
    str = replace(str, "\\x4D", "M");
    str = replace(str, "\\x4E", "N");
    str = replace(str, "\\x4F", "O");
    str = replace(str, "\\x4a", "J");
    str = replace(str, "\\x4b", "K");
    str = replace(str, "\\x4c", "L");
    str = replace(str, "\\x4d", "M");
    str = replace(str, "\\x4e", "N");
    str = replace(str, "\\x4f", "O");

    str = replace(str, "\\x50", "P");
    str = replace(str, "\\x51", "Q");
    str = replace(str, "\\x52", "R");
    str = replace(str, "\\x53", "S");
    str = replace(str, "\\x54", "T");
    str = replace(str, "\\x55", "U");
    str = replace(str, "\\x56", "V");
    str = replace(str, "\\x57", "W");
    str = replace(str, "\\x58", "X");
    str = replace(str, "\\x59", "Y");
    str = replace(str, "\\x5A", "Z");
    str = replace(str, "\\x5B", "[");
    str = replace(str, "\\x5C", "\\");
    str = replace(str, "\\x5D", "]");
    str = replace(str, "\\x5E", "^");
    str = replace(str, "\\x5F", "_");
    str = replace(str, "\\x5a", "Z");
    str = replace(str, "\\x5b", "[");
    str = replace(str, "\\x5c", "\\");
    str = replace(str, "\\x5d", "]");
    str = replace(str, "\\x5e", "^");
    str = replace(str, "\\x5f", "_");

    str = replace(str, "\\x60", "`");
    str = replace(str, "\\x61", "a");
    str = replace(str, "\\x62", "b");
    str = replace(str, "\\x63", "c");
    str = replace(str, "\\x64", "d");
    str = replace(str, "\\x65", "e");
    str = replace(str, "\\x66", "f");
    str = replace(str, "\\x67", "g");
    str = replace(str, "\\x68", "h");
    str = replace(str, "\\x69", "i");
    str = replace(str, "\\x6A", "j");
    str = replace(str, "\\x6B", "k");
    str = replace(str, "\\x6C", "l");
    str = replace(str, "\\x6D", "m");
    str = replace(str, "\\x6E", "n");
    str = replace(str, "\\x6F", "o");
    str = replace(str, "\\x6a", "j");
    str = replace(str, "\\x6b", "k");
    str = replace(str, "\\x6c", "l");
    str = replace(str, "\\x6d", "m");
    str = replace(str, "\\x6e", "n");
    str = replace(str, "\\x6f", "o");

    str = replace(str, "\\x70", "p");
    str = replace(str, "\\x71", "q");
    str = replace(str, "\\x72", "r");
    str = replace(str, "\\x73", "s");
    str = replace(str, "\\x74", "t");
    str = replace(str, "\\x75", "u");
    str = replace(str, "\\x76", "v");
    str = replace(str, "\\x77", "w");
    str = replace(str, "\\x78", "x");
    str = replace(str, "\\x79", "y");
    str = replace(str, "\\x7A", "z");
    str = replace(str, "\\x7B", "{");
    str = replace(str, "\\x7C", "|");
    str = replace(str, "\\x7D", "}");
    str = replace(str, "\\x7E", "~");
    str = replace(str, "\\x7F", "o");
    str = replace(str, "\\x7a", "z");
    str = replace(str, "\\x7b", "{");
    str = replace(str, "\\x7c", "|");
    str = replace(str, "\\x7d", "}");
    str = replace(str, "\\x7e", "n");
    str = replace(str, "\\x7f", "~");
    return str;
}

//    for(int i = 0; i <= 0xFF; i++) {
//        printf("%d\n", i);
//        std::string i_str = std::to_string(i);
//        str = replace(str, i_str, i);
//    }

void handle_strings(int num_line){
    //remove " ":
    char new_string[strlen(yytext)-2];
    memcpy( new_string, &yytext[1], strlen(yytext)-2);
    new_string[strlen(yytext)-2] = '\0';

    //remove escapes:
    std::string new_string_2(new_string);
    new_string_2 = handle_hex(new_string_2);

    new_string_2 = replace(new_string_2, "\\n", "\x0A");
    new_string_2 = replace(new_string_2, "\\t", "\x09");
    new_string_2 = replace(new_string_2, "\\r", "\x0D");
    new_string_2 = replace(new_string_2, "\\\"", "\"");

    std::cout << num_line << " STRING " << new_string_2 << std::endl;
}

//---------------------------- my parser ----------------------------------------------


int main()
{
    int num_line = 1;
    int token;
    while(token = yylex()) {
        if (token == 30) { // \n
            num_line++;
        }else if (token == VOID) {
            showToken("VOID", num_line);
        }else if (token == INT) {
            showToken("INT", num_line);
        }else if (token == BYTE) {
            showToken("BYTE", num_line);
        }else if (token == B) {
            showToken("B", num_line);
        }else if (token == BOOL) {
            showToken("BOOL", num_line);
        }else if (token == AND) {
            showToken("AND", num_line);
        }else if (token == OR) {
            showToken("OR", num_line);
        }else if (token == NOT) {
            showToken("NOT", num_line);
        }else if (token == TRUE) {
            showToken("TRUE", num_line);
        }else if (token == FALSE) {
            showToken("FALSE", num_line);
        }else if (token == RETURN) {
            showToken("RETURN", num_line);
        }else if (token == IF) {
            showToken("IF", num_line);
        }else if (token == ELSE) {
            showToken("ELSE", num_line);
        }else if (token == WHILE) {
            showToken("WHILE", num_line);
        }else if (token == BREAK) {
            showToken("BREAK", num_line);
        }else if (token == CONTINUE) {
            showToken("CONTINUE", num_line);
        }else if (token == SC) {
            showToken("SC", num_line);
        }else if (token == COMMA) {
            showToken("COMMA", num_line);
        }else if (token == LPAREN) {
            showToken("LPAREN", num_line);
        }else if (token == RPAREN) {
            showToken("RPAREN", num_line);
        }else if (token == LBRACE) {
            showToken("LBRACE", num_line);
        }else if (token == RBRACE) {
            showToken("RBRACE", num_line);
        }else if (token == ASSIGN) {
            showToken("ASSIGN", num_line);
        }else if (token == RELOP) {
            showToken("RELOP", num_line);
        }else if (token == BINOP) {
            showToken("BINOP", num_line);
        }else if (token == COMMENT) {
            printf("%d COMMENT //\n", num_line);
        }else if (token == ID) {
            showToken("ID", num_line);
        }else if (token == NUM) {
            showToken("NUM", num_line);
        }else if (token == STRING) {
            handle_strings(num_line);
        }
    }
    return 0;
}
