%{

/* Declarations section */
#include <stdio.h>
#include "tokens.hpp"

%}

%option yylineno
%option noyywrap
digit   		([0-9])
letter  		([a-zA-Z])
whitespace		([\r\t\n ])
relop			(==|!=|<|>|<=|>=)
binop			([*+-/])
idchar			([0-9a-zA-Z])
escapechar		(\[\"nr])
escapehex		(\x[0-9][0-9a-fA-F])
stringchar		([\x00-\x09\x0b-\x0c\x0e-\x21\x23-\x5b\x5d-\x7f])


%%


void											return VOID;
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
\\.*(\x0a|\x0d|\x0d\x0a)						return COMMENT;
{letter}{idchar}*								return ID;
[1-9]{digit}+									return NUM;
"({stringchar}|{escapehex}|{escapechar})*"		return STRING;



%%

