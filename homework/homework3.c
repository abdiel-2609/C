#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0

int main()
{
	int s, parentesis, llaves, corchetes, apost, comillas;
	parentesis = llaves = corchetes = apost = comillas = FALSE;
	int last_digit = FALSE;
	int ignore = FALSE;
	
	while ((s = getchar()) != EOF)
	{
		ignore = FALSE;
		switch (s)
		{
			case '(': parentesis++;
				break;
			case '[': corchetes++;
				break;
			case '{': llaves++;
				break;
			case ')': parentesis++;
				break;
			case ']': corchetes++;
				break;
			case '}': llaves++;
				break;
			case '\"': comillas++;
				break;
			case '\'': apost++;
				break;
			case '.': ignore = 1;
				break;
			case ',': ignore = 1;
				break;
				
		}
		if (ignore)
		{
			continue;
		}
		if((!parentesis) && (!corchetes) && (!llaves) && (!comillas) && (!apost))
		{
			if (!isdigit(s) && last_digit == TRUE)
			{
				putchar('x');
				last_digit = FALSE;
			}
			isdigit(s) ? last_digit = TRUE : putchar(s);
		}
		else 
		{
			putchar(s);
		}
	}
	getch();
}
/*Inspired by my partners: Héctor Mtz and Ángel Raúl Chávez
Thanks guys :D */
