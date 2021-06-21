#include <bits/stdc++.h>

using namespace std;

/*
    -program description



    -  k rooted tree from a graph
     each node has k roots
    
    -  total sum n paths

    - there must be atleast a minimum edge of value d

    cnt = 0
    def func([], k, n, d):
        if( n == 0 && d)
            cnt++;
            return;
        for  i = 1..k:
            func([i], k, n - i)
        



*/
int ni = 101;
int cnt = 0;
// vector<vector<int>> dp(n, vector<int> (1,0));
/*
    k rooted tree is exponential time frame we need dp to optimize the solution


    the k rooted problem has a which it has to solve every time 

    where it might have to caluclate the path taken by

*/
vector<vector<int>> dp(ni, vector<int> (2, 0));
int func(int k, int n, int d, int maxedge)
{
    if(n == 0 and d <= maxedge)
    {
        cnt++;
        
        return 0;
        // return;
    }
    if(n < 0)
    {
        return 0
        ;
    }
    for(int i = 1; i <= k; i++)
    {
        // minedge = min(minedge, i);
        maxedge = max(maxedge, i);
        if(i > d)
        {
            dp[n][1] = dp[n - i][0] +dp[n - i][1];

        }

        func(k, n - i, d, maxedge);
    }

}



int main()
{
    
    int n, k, d;
    cin >> n >> k >> d;
    func(k, n, d, INT_MIN);
    cout << endl << cnt;

    return 0;
}