#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int col[16] = {0, };
int N;
int res = 0;

bool check(int level)
{
    for(int i = 0; i < level; i++)
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)// 대각선이거나 같은 라인
            return false;
        //col[i]가 의미하는 것이 X좌표, i가 의미하는것이 Y좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
    return true;
}

void dfs(int x)
{
    if(x == N)
        res++;
    else
    {
        for(int i = 0; i < N; i++)
        {
            col[x] = i; // 해당 위치에 퀸을 배치
            if(check(x)) // 유효하다면 다음행의 퀸 배치, 유효하지않다면 다른 위치로 퀸 배치 변경
                dfs(x+1);
        }
    }
}
int main() {
    cin >> N;
    dfs(0);
    cout << res;
}