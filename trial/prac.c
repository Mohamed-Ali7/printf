#include <stdarg.h>
#include <stdio.h>

int printint(int count, ...)
{
	va_list arr;
	va_start(arr, count);

	int loop, sum = 0;

	for (loop = 0; loop < count; loop++)
	{
		int x = va_arg(arr, int);
		sum += x;
	}
	va_end(arr);
	return (sum);
}

int main(void)
{
	int x = printint(3, 4, 5, 1);

	printf("the sum is %d", x);

	return (0);
}
