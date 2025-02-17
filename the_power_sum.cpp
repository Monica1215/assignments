#include <bits/stdc++.h>
using namespace std;

int the_power_sum(int x, int n, int k)
{
    int pw = pow(k,n);
    if (pw > x) return 0;
    if (pw == x) return 1;
    return the_power_sum(x, n, k+1) + the_power_sum(x-pw, n, k+1);
}


int main()
{
    int x, n;
    cin >> x >> n;
    cout << the_power_sum(x, n, 1);
    return 0;
}
