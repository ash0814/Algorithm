#include <iostream>
#include <string.h>

using namespace std;

int r;
int c;
int n;

void input_setting()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

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
        }
        cout << "\n";
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


void    foo(int **board)
{
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (board[i][j] == 3){
                if (i - 1 >= 0  && board[i-1][j] != 3)
                    board[i-1][j] = -1;
                if (i + 1 < r  && board[i+1][j] != 3)
                    board[i+1][j] = -1;
                if (j - 1 >= 0  && board[i][j-1] != 3)
                    board[i][j-1] = -1;
                if (j + 1 < c  && board[i][j+1] != 3)
                    board[i][j+1] = -1;
                board[i][j] = -1;
            }
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

int **copyBoard(int **board)
{
    int **copy = new int*[r];
    for (int i = 0; i < r; i++){
        copy[i] = new int[c];
        memset(copy[i], 0, sizeof(int)*c);
    }
    for (int i = 0; i < r; i++){    
        for (int j = 0; j < c; j++){
            copy[i][j] = board[i][j];
        }
    }
    return (copy);
}

int main()
{
    input_setting();
    cin >> r >> c >> n;
    int **board = board_input(board);
    int **zero_board;
    int **third_board;
    int **fifth_board;

    if (n < 2){
        print_board(board);
        return (0);
    }
    
    for (int k = 2; k < 6; k++){
        board_plus(board);
        if (k >= 2)
            foo(board);
        if (k == 3)
            third_board = copyBoard(board);
        else if (k == 4)
            zero_board = copyBoard(board);
        else if (k == 5)
            fifth_board = copyBoard(board);
    }
    if (n % 2 == 0)
        print_board(zero_board);
    else if (n % 4 == 3)
        print_board(third_board);
    else if (n % 4 == 1)
        print_board(fifth_board);
    
    return (0);
}