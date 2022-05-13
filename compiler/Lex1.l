%{
#include <iostream>
using namespace std;
int yylex();
%}

digit				[0-9]+
operator			[+|-|*|/|%]
identifier			^([a-zA-Z_]).*[a-zA-Z0-9_]
keywordSet1   		auto|break|case|char|const|continue|default|do|double|else|enum
keywordSet2   		extern|float|for|goto|if|int|long|register|return|short|signed|sizeof
keywordSet3   		static|struct|switch|typedef|union|unsigned|void|volatile|while
keyword				{keywordSet1}|{keywordSet2}|{keywordSet3}

%%
{digit}  	    return 1;
{operator}      return 2;
{keyword}       return 3;
{identifier}    return 4;
.			    ;
%%

int yywrap(void){return 0;}

int main()
{
	cout << "Enter your input:\n";
	int token = yylex();
	while(token){
		switch(token){
			case 1:
				cout << yytext << " is DIGIT";
				break;
			case 2:
				cout << yytext << " is OPERATOR";
				break;
			case 3:
				cout << yytext << " is KEYWORD";
				break;
			case 4:
				cout << yytext << " is IDENTIFIER";
				break;
			default:
				break;
		}
		token = yylex();
	}
	return 0;
}