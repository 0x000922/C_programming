#include <bits/stdc++.h>

using namespace std;

/*
    -program description


    grid travellor(m, n)
        number of ways to travel from top left to bottom right


*/


long gridways(int m, int n, int i, int j, vector<vector<long>> &dp)
{   
    if( i == m - 1 || j == n - 1)
    {
        dp[i][j] = 1;
        return 1;
    }
    if( dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = gridways(m , n, i + 1,j, dp) + gridways(m, n ,  i, j + 1, dp);

    return dp[i][j];
}


int main()
{
    
    vector<vector<long>> dp ( 18, vector<long> (18, -1));
    cout << gridways( 18,18, 0, 0, dp);

    return 0;
}