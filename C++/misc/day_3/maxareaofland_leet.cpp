#include <bits/stdc++.h>

using namespace std;

void dfs( vector<vector<int>> &grid, vector<vector<bool>> &visi, int i, int j, int &marea)
{
    if( grid[i][j] == 1 and !visi[i][j] and i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size())
    {
        // mark place as visited
        
              
        // four directions allowed
        int marea += 1;
        //int marea = max( m, marea);
        dfs(grid, visi, i, j + 1, m);
        dfs(grid, visi, i + 1, j, m);
   
        dfs(grid, visi, i - 1, j, m);
        dfs(grid, visi, i, j - 1, m);
    }
    

}
int maxAreaOfIsland(vector<vector<int>>& grid) {
        // bool arr[][]
    int m = grid.size(); int n = grid[0].size();
    vector<vector<bool>> visi(m, vector<bool> ( n, false));
    int marea = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if( !visi[i][j] and grid[i][j] == 1)
            {
                int m = 0;
                
                dfs(grid, visi, i, j, m);
                marea = max( marea,  m );
            }
        
        }
    
    }   
        
}

int main(){
}
