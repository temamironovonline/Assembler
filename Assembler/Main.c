#include <stdio.h>

int amount(int, int);
int difference(int, int);
int multiply(int, int);
int division(int, int);
int divisionRemainder(int, int);
int comprasionTwo(int, int);
int comprasionThree(int, int, int);
void changeElementsPlace(int*, int*);

//https://codetown.ru/assembler/delenie-umnozhenie/

int amountAssembler(int, int);
int differenceAssembler(int, int);
int multiplyAssembler(int, int);
int divisionAssembler(int, int);
int comprasionTwoAssembler(int, int);
int comprasionThreeAssembler(int, int, int);
void changeElementsPlaceAssembler(int*, int*);

int amount(int a, int b)
{
	int c = a + b;
	return c;
}

int amountAssembler(int a, int b)
{
	int c;
	_asm 
	{
		mov eax, a;
		add eax, b;
		mov c, eax;
	}
	return c;
}


int difference(int a, int b)
{
	int c = a - b;
	return c;
}

int differenceAssembler(int a, int b)
{
	int c;
	_asm
	{
		mov eax, b;
		sub eax, a;
		mov c, eax;
	}
	return c;
}

int multiply(int a, int b)
{
	int c = a * b;
	return c;
}

int multiplyAssembler(int a, int b)
{
	int c;
	_asm
	{
		mov eax, a;
		mov ebx, b;
		mul eax;
		mov c, eax;
	}
	return c;
}


int division(int a, int b)
{
	int c = a / b;
	return c;
}

int divisionAssembler(int a, int b)
{
	int c;
	_asm
	{
		mov eax, a;
		mov edx, 0;
		mov ebx, b;
		div ebx;
		mov c, eax;
	}
	return c;
}

int divisionRemainder(int a, int b)
{
	int c = a % b;
	return c;
}

int comprasionTwo(int a, int b)
{
	if (a > b) return 1;
	else if (b > a) return 2;
	else return 0;
}

int comprasionThree(int a, int b, int c)
{
	if (a > b && a > c) return 1;
	else if (b > a && b > c) return 2;
	else if (c > a && c > b) return 3;
	else return 0;
}

void changeElementsPlace(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main(void)
{
	system("chcp 1251>n");
	int var1 = 3, var2 = 5, var3 = 10;
	printf("%d\n", amount(var1, var2));
	printf("%d\n", difference(var1, var2));
	printf("%d\n", multiply(var1, var2));
	printf("%d\n", comprasionTwo(var1, var2));
	printf("%d\n", comprasionThree(var1, var2, var3));

	printf("%d\n", division(var3, var2));
	printf("%d\n", divisionRemainder(var1, var2));

	int* var6 = &var1, * var7 = &var2;
	printf("%d %d ", *var6, *var7);

	changeElementsPlace(var6, var7);
	printf("%d %d ", *var6, *var7);

	printf("\nАссемблер\n");
	printf("%d\n", amountAssembler(var1, var2));
	printf("%d\n", differenceAssembler(var1, var2));
	printf("%d\n", multiplyAssembler(var1, var2));
	printf("%d\n", divisionAssembler(var1, var2));
}