#include <iostream>
#include <string.h>

using namespace std;

int r;
int c;
int n;

void    print_board(int **board)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == -1)
                cout << '.';
            else
                cout << 'O';
            // cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int **board_input(int **board)
{
    board = new int*[r];
    for (int i = 0; i < r; i++){
        board[i] = new int[c];
        memset(board[i], 0, sizeof(int)*c);
    }
	for (int i = 0; i < r; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < c; j++) {
            if (a[j] == '.')
			    board[i][j] = -1;
            else
                board[i][j] = 1;
		}
	}
    return (board);
}

//hyson코드_재귀로 bomb 짜서 한번에 터짐

void    bomb(int **board, int i, int j)
{
    board[i][j] = -1;
	if (i + 1 < r)
	{
		if (board[i + 1][j] == 3)
			bomb(board, i + 1, j);
		else
			board[i + 1][j] = -1;
	}
	if (j + 1 < c)
	{
		if (board[i][j + 1] == 3)
			bomb(board, i, j + 1);
		else
			board[i][j + 1] = -1;
	}
	if (i - 1 >= 0)
	{
		if (board[i - 1][j] == 3)
			bomb(board, i - 1, j);
		else
			board[i - 1][j] = -1;
	}
	if (j - 1 >= 0)
	{
		if (board[i][j - 1] == 3)
			bomb(board, i, j - 1);
		else
			board[i][j - 1] = -1;
	}
}

void    foo(int **board)
{
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (board[i][j] == 3)
                bomb(board, i, j);
        }
    }
}

void board_plus(int **board)
{
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            board[i][j]++;
        }
    }
}

int main()
{
    cin >> r >> c >> n;
    int **board = board_input(board);
    
    for (int i = 1; i < n; i++){
		board_plus(board);
		if (i >= 2)
            foo(board);
	}
    print_board(board);
    return (0);
}