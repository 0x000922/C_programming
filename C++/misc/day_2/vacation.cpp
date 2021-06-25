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

    int prev = -1;
    int comp = -1;
    // finding the greatest selection of all the places in first row
    if ( dp[0][2] > dp[0][1])
    {
        comp = dp[0][2];
        prev = 2;
    }   
    else
    {
        comp = dp[0][1];
        prev = 1;
    }
    if( max(comp, dp[0][0]) == dp[0][0])
    {
        prev = 0;
    }
    comp = max( comp, dp[0][0]);
    



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

        vacation_recur( arr, 1,0, 0,arr[0][0]);
        vacation_recur( arr, 1,1, 1,arr[0][1]);
        vacation_recur( arr, 1,2, 2,arr[0][2]);

        cout << max_h << endl;  
    }
    else
    {
        int r = max ( arr[0][1], arr[0][0]);
        cout << max( r, arr[0][2]) << endl;
    }

    return 0;
}