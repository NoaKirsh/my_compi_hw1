#include "tokens.hpp"
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
    int token;
    stack<int> stack;
    const char *tokens[] = {"", "VOID", "INT", "BYTE", "B", "BOOL", "AND", "OR", "NOT", "TRUE", "FALSE", "RETURN", "IF",
                            "ELSE", "WHILE", "BREAK", "CONTINUE", "SC", "COMMA", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
                            "ASSIGN", "RELOP", "BINOP", "COMMENT", "ID", "NUM", "STRING"};

    vector<pair<string, int>> tokenVector;
    while (token = yylex()){
        if (token == NUM || token == BINOP){
            tokenVector.push_back(make_pair(yytext, token));
        } else {
            printf("Error: %s\n", tokens[token]);
            exit(0);
        }
    }

    while (!tokenVector.empty()){
        pair<string, int> tokenPair = tokenVector.back();
        tokenVector.pop_back();
        if (tokenPair.second == NUM) {
            stack.push(stoi(tokenPair.first));
        } else {
            if (stack.empty()){
                printf("Error: Bad Expression\n");
                exit(0);
            }
            int n = stack.top();
            stack.pop();
            if (stack.empty()){
                printf("Error: Bad Expression\n");
                exit(0);
            }
            int m = stack.top();
            stack.pop();
            switch (tokenPair.first[0]) {
                case '+':
                    stack.push(n + m);
                    break;
                case '-':
                    stack.push(n - m);
                    break;
                case '*':
                    stack.push(n * m);
                    break;
                case '/':
                    stack.push(n / m);
                    break;
            }
        }
    }
    if(stack.size() != 1){
        printf("Error: Bad Expression\n");
        exit(0);
    }
    printf("%d\n", stack.top());
    return 0;

}