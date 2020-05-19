%{
	#include <stdio.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include <string.h>
%}
DIGIT	[0-9]+
LETTER	[A-Za-z]+

%%
[ ]+		{ printf(" "); }
[\tab]+ 	{ printf(" "); }
[0-9]+		{ printf("십진법 %d\n이진법 %d\n",atoi(yytext),dtob(atoi(yytext))); }

abcd		{ puts("abCD"); }
[a-z]+		{ for(int i=0;i<strlen(yytext);i++){
			*(yytext+i) = toupper(*(yytext+i)); 
			}
			printf("%s",yytext); }

%%
int dtob(int n){
	int a;
	int b=1;
	int result=0;
	
	while(n != 0){
		a = n % 2;
		n /= 2;
		result = result + a*b;
		b *= 10;
	}
	return result;
}

int main()
{
	yylex();
}