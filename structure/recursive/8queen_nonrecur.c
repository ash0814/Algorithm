#include <stdio.h>

int count = 0;
int pos[5];
int flag[5];
int flag_b[9];
int flag_c[9];
int c = 0;
int list[100][4] = {0, };

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
			if (i == 4){
			printf("{result set}\n");
				print();
			}
			else{
				// flag[j] = 1;
				// flag_b[i + j] = 1;
				// flag_c[i - j + 4] = 1;
				list[c][0] = i;
				list[c][1] = j;
				list[c][2] = i+j;
				list[c][3] = i-j+4;
				c++;
				break;
				// printf("i, j, n, m = %d %d %d %d\n", i, j, i+j, i-j+4);
				// printf("before : ");
				// print();
				// set(i + 1);
				// flag[j] = 0;
				// flag_b[i + j] = 0;
				// flag_c[i - j + 4] = 0;
				// printf("after : ");
				// print();
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
	for (int i = 0; i < 5; i++)
		set(i);
	for (int i = 0; i < c; i++)
		printf("<<<%d %d %d %d>>>\n", list[i][0], list[i][1], list[i][2], list[i][3]);
	return (0);
}