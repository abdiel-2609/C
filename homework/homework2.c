#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//#define k 25 // los primeros k num.

int primo(int a);
void binario(int b);
int k;
int main ()
{
    printf("Introduce a k number\n");
    scanf("%d", &k);
    printf("The binary prime numbers are:\n\n");
	for (int i = 0; i < k; i++)
	{
		if (primo(i) == 1)
		{
			printf("%d\n", i);
			binario(i);
		}
	}
	return 0;
}
int primo(int a)
{
	int divisor = 2;
	int residuo = 0;
	while(divisor < a)
	{
		residuo = fmod(a, divisor);
		if (residuo == 0)
		{
			return 0;
		}
		divisor++;
	}
	return 1;
}
void binario(int b)
{
	int result = b;
	int residuo = 0;
	char bin[50];
	char bin2[1] = "";
	float tmp = 0;
	while (result >= 2)
	{
		tmp = result;
		result = floor(result / 2);
		residuo = fmod(tmp, 2);
		sprintf(bin2, "%d", residuo);
		strcat(bin, bin2);
	}
	sprintf(bin2, "%d", result);
	strcat(bin, bin2);
	printf("%s\n", strrev(bin));
}


