#include "q.h"

int main(void)
{
	intque *que;

	if (!(que = (intque *)malloc(sizeof(intque))))
		return (1);
	if (init(que, 12)){
		puts("fail");
		return 1;
	}

	while (1)
	{
		int m, x;

		printf("Data : %d / %d \n", size(que), capacity(que));
		printf("(1) Enque (2) Deque (3) Peek (4) Print (5) Search (6) Search2 (0) Exit : ");
		scanf("%d", &m);

		if (m == 0)
			break;
		switch (m){
			case 1 :
				printf("Enque Data : ");
				scanf("%d", &x);
				if (enque(que, x))
					printf("error : Enque fail\n");
				break;
			case 2 :
				if (deque(que, &x))
					printf("error : Deque fail\n");
				else
					printf("Deque Data : %d\n", x);
				break;
			case 3 :
				if (peek(que, &x))
					printf("error : Peek fail\n");
				else
					printf("Peek Data : %d\n", x);
				break;
			case 4 :
				printq(que);
				break;
			case 5 :
				printf("Search Data : ");
				scanf("%d", &x);
				int res = search(que, x);
				if (res != -1)
					printf("result = %d\n", res);
				else
					printf("Search Fail\n");
				break;
			case 6 :
				printf("Search2 Data : ");
				scanf("%d", &x);
				int res2 = search2(que, x);
				if (res2 != -1)
					printf("result = %d\n", res2);
				else
					printf("Search2 Fail\n");
				break;
		}
	}
	terminate(que);
	free (que);
	return (0);
}