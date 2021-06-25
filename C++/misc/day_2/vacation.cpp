#include <bits/stdc++.h>

using namespace std;

/*
    -program description


    N days  3 activities ( 1,2, 3 ) and happiness values
    the person will not perfom the same activity coloumn after doing it once (  he get's bored ) 
    a b c
    a b c
    a b c

    def func( int arr[], int prev[], i, j)    

        if prev.size() == 2
            if prev[0] != prev[1]:
                for k in range(3):
                    func( arr, {prev[1]}, i + 1, k)
            else:
                for k in range(3)
                    if k != prev[1]
                        func(arr, {prev}, i, k)
        else
            func( arr, {}, i + 1, prev[1])


*/
int max_h = INT_MIN;
void vacation_recur (vector<vector<int>> arr, int i, int j, int prev, int s)
{

    if( i == arr.size() - 1)
    {
        for(int l = 0; l < 3; l++)
        {
            if( l != prev)
            {
                // cout << arr[i][l];
                // cout <<  endl;
                max_h = max( max_h, s + arr[i][l]);
            }
        }
        return;
    }
    else
    {
        vector<int> k = arr[i];        
        
            for(int l = 0; l < 3; l++)
            {
                if( prev != l)
                {
                    // cout << k[l] << " ";
                    
                    vacation_recur( arr, i + 1, l, l, s + k[l]);
                }
            }
        // }
    }


}

int vacationdp( vector<vector<int>> arr, int n)
{
    vector<vector<int>> dp( n, vector<int> (3, 0));
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (int k = 1; k  < arr.size() ; k++)
    {
        /* code */
        dp[k][0] = arr[k][0] + max( dp[k - 1][1], dp[k - 1][2]); 
        dp[k][1] = arr[k][1] + max( dp[k - 1][0], dp[k - 1][2]); 
        dp[k][2] = arr[k][2] + max( dp[k - 1][0], dp[k - 1][1]) ;
    }
    return *max_element( dp[n -1].begin(), dp[n - 1].end());

}

int main()
{
    
    int n;
    cin >> n;
    vector<vector<int>> arr( n, vector<int> (3, 0));

    for(auto &i: arr)
    {
        int x,y,z;
        cin >> x >> y >> z;
        i[0] = x; i[1] = y; i[2] = z;
    }
    if( n > 1)
    {

        // vacation_recur( arr, 1,0, 0,arr[0][0]);
        // vacation_recur( arr, 1,1, 1,arr[0][1]);
        // vacation_recur( arr, 1,2, 2,arr[0][2]);

        cout << vacationdp(arr, n) << endl;  
    }
    else
    {
        int r = max ( arr[0][1], arr[0][0]);
        cout << max( r, arr[0][2]) << endl;
    }

    return 0;
}