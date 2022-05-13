%{
#include <iostream>
#include <stack>
using namespace std;

int yylex();
%}

digit				[0-9]
operator			[+\-*/]
anyChar				.*.
prefix				^{operator}{anyChar}({digit}+)$
infix				^({digit}+){anyChar}({digit}+)$
postfix				^({digit}+){anyChar}{operator}$

%%
{prefix}			return 1;
{infix}				return 2;
{postfix}			return 3;
.					cout << "Unexpected Character" << endl;
%%

int yywrap(void){ return 0; }

bool isDigit(char exp){
	return (exp >= '0' && exp <= '9');
}

int evalPostfix(string exp)
{
	stack<int> stack;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isDigit(exp[i])) stack.push(exp[i] - '0');
        else {
            int x = stack.top();
            stack.pop();
 
            int y = stack.top();
            stack.pop();
			
            if (exp[i] == '+') stack.push(y + x);
            else if (exp[i] == '-') stack.push(y - x);
            else if (exp[i] == '*') stack.push(y * x);
            else if (exp[i] == '/') stack.push(y / x);
        }
    }
    return stack.top();
}

int evalInfix(string exp){
	return 0;
}

int evalPrefix(string exp){
	stack<int> stack;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (isDigit(exp[i])) stack.push(exp[i] - '0');
        else {
            int x = stack.top();
            stack.pop();
 
            int y = stack.top();
            stack.pop();
			
            if (exp[i] == '+') stack.push(y + x);
            else if (exp[i] == '-') stack.push(y - x);
            else if (exp[i] == '*') stack.push(y * x);
            else if (exp[i] == '/') stack.push(y / x);
        }
    }
    return stack.top();
}

int main()
{
	cout << "OUTPUT :\n";
    int token = yylex();

	while(token) {
		switch(token){
			case 1:
				cout <<  evalPrefix(yytext);
				break;
			case 2:
				cout << evalInfix(yytext);
				break;
			case 3:
				cout << evalPostfix(yytext);
				break;
			default:
				cout << "Error in line " << yylineno << "at: " << yytext;
				return 1;
				break;
		}
	 	token = yylex();
	}
    return 0;
}