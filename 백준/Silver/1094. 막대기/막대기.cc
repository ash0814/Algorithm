#include <iostream>
using namespace std;
 
int main() 
{
    int X;
    cin >> X;
 
    int ans = 0;
    while (X > 0) {
        if (X % 2)
            ans++;
        X /= 2;
    }
 
    cout << ans;
    return 0;
}