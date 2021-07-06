#include <bits/stdc++.h>

using namespace std;

/*
    -program description
*/
void print1Dvi(vector<int> a)
{
    for(auto i: a)
        cout << i << " ";

    cout << "\n";
}

void print2d(vector<vector<int>> &grid)
{
    for(auto i : grid)
    {
        print1Dvi(i);
    }
}



void mcost( vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp, int i, int j)
{

    if( i >= 1 and j >= 1 and i < m and j < n)
    {
        dp[i][j] = min( dp[i - 1][j], dp[i][j - 1] ) + grid[i][j];
    }
}



int micost( vector<vector<int>> &grid, int m, int n)
{

    vector<vector<int>> dp( m, vector<int> (n, INT_MAX));

    dp[0][0] = grid[0][0];

    for(int i = 1; i < m;  i++)
    {   
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for(int i = 1; i < n; i++)
    {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    print2d(dp);
    cout << " ------------------" << endl;

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            mcost(grid, m, n, dp, i, j);
        }
    }
    print2d(dp);
    return dp[m - 1][n - 1];
}



int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid( m, vector<int> (n, 0));

    for(auto &i: grid)
    {
        for(auto &j : i)
        {
            cin >> j;
        }
    }
    cout << micost(grid, m, n);

    return 0;
}