#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = i; j <= N; j++)
			cout << "*";
		for (int j = 1; j < 2 * i-1; j++)
			cout << " ";
		for (int j = i; j <= N; j++)
			cout << "*";
		cout << endl;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - i; j++)
			cout << "*";
		for (int j = 0; j < 2 * i; j++)
			cout << " ";
		for (int j = 0; j < N-i; j++)
			cout << "*";
		cout << endl;
	}
}