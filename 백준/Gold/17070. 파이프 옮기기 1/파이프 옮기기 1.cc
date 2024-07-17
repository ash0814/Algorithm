#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N;
int map[17][17] = {0, };
int dp[17][17][3] = {0, };
// 가로 0, 세로 1, 대각선 2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dp[0][1][0] = 1;

	for (int j = 2; j < N; j++) {
		if (map[0][j] == 1)
			break;
		else
			dp[0][j][0] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 2; j < N; j++) {
			if (map[i][j] == 0) {
				dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
				dp[i][j][1] = dp[i-1][j][2] + dp[i-1][j][1];
				if (map[i-1][j] == 0 && map[i][j-1] == 0)
					dp[i][j][2] = dp[i-1][j-1][1] + dp[i-1][j-1][0] + dp[i-1][j-1][2];
			}
		}
	}

	cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
}