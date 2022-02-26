#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int makeInt(char *s)
{
    int tmp, ret;
	int len;

	len = strlen(s);
	tmp = atoll(s);
	ret = 0;
	for (int i = 0; i < len; i++)
	{
		if (tmp % pow(10, i) == 1)
			ret = ret + pow(2, i);
	}
	return (ret);
}

char * addBinary(char * a, char * b){
    int a_int, b_int, res;
    char *ret;

    a_int = makeInt(a);
    b_int = makeInt(b);
    res = a + b;
    printf("%d, %d\n", a_int, b_int);
	return ("a");
}

int main()
{
	addBinary("11", "1000");
	return (0);
}
