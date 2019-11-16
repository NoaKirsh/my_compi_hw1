%{

/* Declarations section */
#include <stdio.h>
#include "tokens.hpp"

%}

%option yylineno
%option noyywrap
digit   		([0-9])
letter  		([a-zA-Z])
whitespace		([ \n\t\r])
relop			(==|!=|<|>|<=|>=)
binop			([*+-/])
escapehex		(\\x[0-9][0-9a-fA-F])
escapechar		(\\[\"nrt0])
stringchar		([\x00-\x09\x0b-\x0c\x0e-\x21\x23-\x5b\x5d-\x7f])
idchar			([0-9a-zA-Z])
comment_start   ([//])

%%

{whitespace}                                    ;
void    										return VOID;
int												return INT;
byte											return BYTE;
b												return B;
bool											return BOOL;
and    											return AND;
or    											return OR;
not    											return NOT;
true    										return TRUE;
false    										return FALSE;
return     										return RETURN;
if						    					return IF;
else    										return ELSE;
while    										return WHILE;
break    										return BREAK;
continue    									return CONTINUE;
;						    					return SC;
,    											return COMMA;
\(    											return LPAREN;
\)    											return RPAREN;
{    											return LBRACE;
}    											return RBRACE;
=						    					return ASSIGN;
{relop}					    					return RELOP;
{binop}					    					return BINOP;
{comment_start}[^\x0a|\x0d|\x0d\x0a)].*			return COMMENT;
{letter}{idchar}*								return ID;
([1-9]{digit}*|[0])				    			return NUM;
\"({escapehex}|{stringchar}|{escapechar}|[\\])*\"	return STRING;
\"({escapehex}|{stringchar}|{escapechar}|[\\])* printf("Error unclosed string\n");
.	                                            printf("Error %s\n", yytext); exit(0);

%%

