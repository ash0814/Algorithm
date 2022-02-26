#include <stdio.h>

int pos[5];
int flag[5];
int flag_b[9];
int flag_c[9];

void print()
{
	for (int i = 0; i < 5; i++)
		printf("%2d", pos[i]);
	printf("\n");
}

void set(int i)
{
	for (int j = 0; j < 5; j++)
	{
		if (!flag[j] && !flag_b[i + j] && !flag_c[i - j + 4])
		{
			pos[i] = j;
			if (i == 4)
				print();
			else{
				flag[j] = 1;
				flag_b[i + j] = 1;
				flag_c[i - j + 4] = 1;
				set(i + 1);
				flag[j] = 0;
				flag_b[i + j] = 0;
				flag_c[i - j + 4] = 0;
			}
		}
	}
}
int main(void)
{
	for (int i = 0; i < 5; i++)
		flag[i] = 0;
	for (int i = 0; i < 9; i++)
		flag_b[i] = flag_c[i] = 0;
	set(0);
	return (0);
}