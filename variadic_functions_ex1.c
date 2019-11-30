#include <stdio.h>
#include <stdarg.h>

int sumnum(int num, ...)
{
	int sum = 0;
	va_list argptr;
	int count;

	count = 0;
	va_start(argptr, num);
	while(count < num)
	{
		sum += va_arg(argptr, int);
		count++;
	}
	va_end(argptr);
	return (sum);
}

int main(void)
{
	int total;
	total = sumnum(5, 1, 1, 1, 1, 1);
	printf("total = %d\n", total);

	return (0);
}
