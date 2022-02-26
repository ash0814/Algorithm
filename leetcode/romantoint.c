#include <stdio.h>
#include <string.h>

int romanToInt(char * s){
	int len = strlen(s);
	int ret = 0;

	for (int i = 0; i < len; i++){
		if (s[i] == 'I') {
			if (i + 1 < len && (s[i + 1] == 'V' || s[i + 1] == 'X'))
				ret--;
			else
				ret++;
		} else if (s[i] == 'V') {
			ret += 5;
		} else if (s[i] == 'X') {
			if (i + 1 < len &&(s[i+1] == 'L' || s[i+1]=='C'))
				ret -= 10;
			else
				ret += 10;
		} else if (s[i] == 'L') {
			ret+=50;
		} else if (s[i] == 'C') {
			if (i + 1 < len &&(s[i+1] == 'D' || s[i+1]=='M'))
				ret -= 100;
			else
				ret += 100;
		} else if (s[i] == 'D') {
			ret+=500;
		} else if (s[i] == 'M') {
			ret+=1000;
		} else
			return (-1);
	}
		return ret;
}

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("ret = %d\n", romanToInt(argv[1]));
	return (0);
}
