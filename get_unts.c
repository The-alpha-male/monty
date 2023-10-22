#include <stdlib.h>
#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *go_toint(int n);

/**
 * go_toint - Convert int to string
 * @n: int to convert
 * Return: string
 */

char *go_toint(int n)
{
int i, temp, digits = 0;
char *s;

temp = n;
while (temp != 0)
{
digits++;
temp /= 10;
}
s = malloc(sizeof(char) * (digits + 1));
if (s == NULL)
return (NULL);
for (i = 0; i < digits; i++)
{
s[i] = (n % 10) + '0';
n /= 10;
}
s[i] = '\0';
return (s);
}
