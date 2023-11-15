#include "main.h"

int _printf(const char *format, ...)
{
	va_list arr;
	va_start(arr, format);

	int count = 0;

	if (format == NULL)
	{
		exit(1);
	}
	if (arr == NULL)
		exit(1);

	while (format[count] != '\0')
	{
		int count2 = 0;

		char valCollected = va_args(arr[count], char);
		if (*(format + count) == '%')
		{
			if (format[count + 1] == 'c')
			{
				write(1, &valCollected, 1);
			}
			else if (format[count + 1] == 's')
			{
				while (arr[count2] != '\0')
				{
					write(1, &arr[count2], 1);
					count2++;
				}
				return (count2);
			}
		}
		count++;
		return (count);
	}
}
