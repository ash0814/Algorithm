#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;

  int dp[1000001] = {
      0,
  };
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= N; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
    dp[i] %= 15746;
  }

  cout << dp[N] << endl;
}