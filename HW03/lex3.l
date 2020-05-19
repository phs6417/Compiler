%{
	#include <stdio.h>
	
	int word_count=0;
	int open_count=0;
	int close_count=0;
	
%}

%%
[A-Z][a-z]+	word_count++;
\/\*		open_count++;
\*\/		close_count++;
"{"		{ printf("begin"); }
"}"		{ printf("end"); }
"\n"		{ printf(" "); }
%%
main()
{

	yylex();
	printf("word_count = %d\n", word_count);
	printf(" /*  = %d\n", open_count);
	printf(" */  = %d\n", close_count);

	if(open_count == close_count)
		printf("Count is same \n");
	else
		printf("Count is not same \n");

	return 0;
}