#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int len = sticker.size();
    
    int dp[100000];
    int dp2[100000];

    if (len <= 3){
        if (len == 1)
            return (sticker[0]);
        if (len == 2)
            return (max(sticker[0], sticker[1]));
        return (max(sticker[2], max(sticker[0], sticker[1])));
    }
    dp[0] = sticker[0];
    dp[1] = sticker[1];
    dp[2] = sticker[0] + sticker[2];
    for (int i = 3; i < len - 1; i++){
        dp[i] = max(dp[i - 2], dp[i - 3]);
        dp[i] += sticker[i];
        dp[i] = max(dp[i], dp[i - 1]);
    }
    dp2[0] = 0;
    dp2[1] = sticker[1];
    dp2[2] = sticker[2];
    dp2[3] = sticker[1] + sticker[3];
    for (int i = 4; i < len; i++){
        dp2[i] = max(dp2[i - 2], dp2[i - 3]);
        dp2[i] += sticker[i];
        dp2[i] = max(dp2[i], dp2[i - 1]);
    }
    answer = max(dp[len-2], dp2[len-1]);

    return answer;
}

int main()
{
    int sticker[100000];

    solution(sticker);
    return (0);
}