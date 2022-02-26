// function solution(N, number) {
//     let dp = [new Set()];
    
//     for (let i=1; i<=8; i++) {
//         dp.push(new Set())
//         dp[i].add(new Array(i).fill(N).join('') * 1);
//         for (let j=1; j<=i; j++) {
//             for (let x of [...dp[j]]) {
//                 for (let y of [...dp[i - j]]) {
//                     dp[i].add(x + y);
//                     dp[i].add(x - y);
//                     dp[i].add(x * y);
//                     if (y != 0)
//                         dp[i].add(x / y - (x / y % 1));
//                 }
//             }
//         }
//         if (dp[i].has(number))
//             return (i);
//     }
//     return (-1);
// }

#include <vector>
#include <set>
#include <iostream>

using namespace std;

int makeN(int N, int size)
{
    int answer = 0;
    for (int i = 0; i < size; i++)
        answer = answer * 10 + N;
    return answer;
}

int solution(int n, int num)
{
    vector<set<int> > dp;

    dp.push_back(set<int>());
    for (int i = 1; i <= 8; i++)
    {
        dp.push_back(set<int>());
        dp[i].insert(makeN(n, i));
        for (int j = 1; j<=i; j++){
            for (auto x : dp[j]) {
                for (auto y : dp[i-j]){
                    dp[i].insert(x+y);
                    dp[i].insert(x-y);
                    dp[i].insert(x*y);
                    if (y != 0)
                        dp[i].insert(x/y);
                }
            }
        }
        if (dp[i].find(num) != dp[i].end())
            return(i);
    }
    return -1;
}

int main()
{
    printf("===%d\n", solution(5, 12));
    return 0;
}