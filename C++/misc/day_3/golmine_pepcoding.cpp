#include <bits/stdc++.h>

using namespace std;

/*
    -program description goldmine
    
    left wall to right wall
    
    the pointer can only go  (i, j )  right up ( i - 1, j + 1)
                                right ( i, j + 1)
                                right down ( i + 1, j + 1)
                                
    finding the maxpath value taken from left to right wall
    
*/
bool isvalid(int i, int j, int m, int n)
{
    if( i < m and j < n and i >= 0 and j >= 0)
    {
       // cout << i << " " << j << endl;
        return true;
    } 
    return false;
}
void vector2dprint( vector<vector<int>> &mat)
{
    for(auto i : mat)
    {
        for(auto j: i)
            cout << j << " ";
        cout << endl;

    }


}

int goldmine(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    
    vector<vector<int>> dp(m, vector<int> (n ,0));
    
    for(int i = 0; i < m; i++)
    {
        dp[i][0] = mat[i][0];
    }
    
        for(int j = 1; j < n; j++)
        {
                
            for(int i = 0; i < m; i++)
            {
                if( isvalid(i + 1, j - 1, m, n))
                {
                    dp[i][j] = max( dp[i][j], mat[i][j] + dp[i + 1][ j - 1]);
                }
                if ( isvalid(i, j - 1, m, n))
                {
                    dp[i][j] = max( dp[i][j], mat[i][j] + dp[i][ j - 1]);
                }
                if( isvalid(i - 1, j - 1, m, n))
                {
                    dp[i][j] = max( dp[i][j], mat[i][j] + dp[i - 1][ j - 1]);   
                }
            }
        }
        cout << endl;
        vector2dprint(dp);
    
    
    
    
    int ma = 0;
    for(int i = 0; i < m; i++)
        ma = max( ma, dp[i][n - 1]);
    return ma;
    
}

int main()
{
    int m; int n;
    cin >> m >> n;
    
    vector<vector<int>> mat (m, vector<int> (n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << goldmine(mat);
    
    return 0;
}
