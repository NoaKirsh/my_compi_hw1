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

void handle_strings(int num_line){
    //remove " ":
    char new_string[strlen(yytext)-2];
    memcpy( new_string, &yytext[1], strlen(yytext)-2);
    new_string[strlen(yytext)-2] = '\0';

    //remove escapes:
    std::string new_string_2(new_string);
    new_string_2 = replace(new_string_2, "\\n", "\x0A");
    new_string_2 = replace(new_string_2, "\\\"", "\"");
    new_string_2 = replace(new_string_2, "\\\\", "\\");
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
            showToken("COMMENT", num_line);
        }else if (token == ID) {
            showToken("ID", num_line);
        }else if (token == NUM) {
            showToken("NUM", num_line);
        }else if (token == STRING) {
            handle_strings(num_line);
        }else {
            printf("Error &s\n", token);
        }
    }
    return 0;
}
