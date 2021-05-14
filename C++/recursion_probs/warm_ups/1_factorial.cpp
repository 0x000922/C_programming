#include <bits/stdc++.h>

using namespace std;

/*
    -program description
*/
int func(int n)
{
    if(n == 0 or n == 1)
    {
        return 1;
    }
    return n * func(n - 1);
}

int main()
{
    cout << func(5);

    return 0;
}