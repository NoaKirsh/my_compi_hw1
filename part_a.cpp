#include "tokens.hpp"
#include <string>
#include <ostream>
#include <iostream>
#include <cstring>
#include <regex>

//---------------------------- helper functions ----------------------------------------------

void showToken(const char * token_name)
{
    printf("%d %s %s\n", yylineno, token_name, yytext);
}

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
            switch (c) {//checking what comes after \.
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
                        std::cout << "Error undefined escape sequence " << str.substr(i-2, 3) << std::endl;
                        exit(0);
                    }
                case '0':
                    std::cout << yylineno << " STRING " << str.substr(0, i) << std::endl;
                    return;
                case 'r': c = '\r'; break;
                case 't': c = '\t'; break;
                case 'n': c = '\n'; break;
                case '"': c = '\"'; break;
                    if(str[i+1] == '\0'){
                        std::cout << "Error unclosed string\n" << std::endl;
                        exit(0);
                    } else break;
                case '\\': break;
                default: {
                    std::cout << "Error undefined escape sequence " << str.substr(i, 2) << std::endl;
                    exit(0);
                }
            }
        }
        buffer[bf_itr] = c;
    }
    buffer[bf_itr] = '\0';

    std::cout << yylineno << " STRING " << buffer << std::endl;
}



void handle_strings() {

    if(strlen(yytext) == 2){
        std::cout << yylineno << " STRING " << "" << std::endl;
        return;
    }

    char new_string[strlen(yytext) - 2];
    memcpy(new_string, &yytext[1], strlen(yytext) - 2);
    new_string[strlen(yytext) - 2] = '\0';

    std::string new_string_2(new_string);
    handle_hex(new_string_2);
}


//---------------------------- my parser ----------------------------------------------


int main()
{
    int token;
    while(token = yylex()) {
        if (token == VOID) {
            showToken("VOID");
        }else if (token == INT) {
            showToken("INT");
        }else if (token == BYTE) {
            showToken("BYTE");
        }else if (token == B) {
            showToken("B");
        }else if (token == BOOL) {
            showToken("BOOL");
        }else if (token == AND) {
            showToken("AND");
        }else if (token == OR) {
            showToken("OR");
        }else if (token == NOT) {
            showToken("NOT");
        }else if (token == TRUE) {
            showToken("TRUE");
        }else if (token == FALSE) {
            showToken("FALSE");
        }else if (token == RETURN) {
            showToken("RETURN");
        }else if (token == IF) {
            showToken("IF");
        }else if (token == ELSE) {
            showToken("ELSE");
        }else if (token == WHILE) {
            showToken("WHILE");
        }else if (token == BREAK) {
            showToken("BREAK");
        }else if (token == CONTINUE) {
            showToken("CONTINUE");
        }else if (token == SC) {
            showToken("SC");
        }else if (token == COMMA) {
            showToken("COMMA");
        }else if (token == LPAREN) {
            showToken("LPAREN");
        }else if (token == RPAREN) {
            showToken("RPAREN");
        }else if (token == LBRACE) {
            showToken("LBRACE");
        }else if (token == RBRACE) {
            showToken("RBRACE");
        }else if (token == ASSIGN) {
            showToken("ASSIGN");
        }else if (token == RELOP) {
            showToken("RELOP");
        }else if (token == BINOP) {
            showToken("BINOP");
        }else if (token == COMMENT) {
            printf("%d COMMENT //\n", yylineno);
        }else if (token == ID) {
            showToken("ID");
        }else if (token == NUM) {
            showToken("NUM");
        }else if (token == STRING) {
            handle_strings();
        }
    }
    return 0;
}
