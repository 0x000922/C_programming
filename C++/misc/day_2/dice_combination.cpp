#include <bits/stdc++.h>


using namespace std;


/*
    -program description


    given sum n

    tell how manys ways of making N by rolling dice  ( 1..6)
    sum = 0
    memo = {}
     // recursive function
    def func(n, yet):
        if n == 0:
            sum += 1
            try :
                if memo[]
            return
        else if n < 0:
            return 
        else:
            for i in range( 1..6):      // 6 ^ n worst case
                func(n - i)

*/
// int sum = 0;
int mod = 1000000007;
// const int sdp = 1000001;
// int dp[sdp] = {};
int givesum( int n, int yet, vector<long long> &dp)
{
    
    // if( n == yet)
    // {
    //     // sum = (sum + 1) % mod;
    //     // dp[yet] = ( dp[yet] + 1 ) % mod;
    //     cout << 1 << endl;
    //     return 1;
    // }
    // else if(  yet > n )
    // {
    // cout << 2 << endl;
    //     return 0;
    // }
    // else if( yet <= n and dp[yet] != 0)
    // {
    //     cout << 3 << endl;
    //     return dp[yet];
    // } 
    // else
    // {   int s = 0;
        // cout << yet << endl;
        dp[0] = 1;
        // dp[1] = 1;

        for(int j = 1; j <= n; j++)
        {
            for( int i = 1; i <= 6; i++)
            {   
                // int s2 = givesum(n, yet + i, dp) % mod;
                // s =  (s % mod + s2) % mod;
                // if( yet <= n)
                    // dp[yet] = s;
                if(i > j)
                    break;
                dp[j] = ( dp[j] + dp[j - i] ) % mod;
            }
        }
        return dp[n];
    // }
    // return 0;
}



int main()
{

    int n;
    cin >> n;
    vector<long long> dp( n + 1, 0);
    cout << givesum(n, 0, dp) << endl;
    // cout << sum;
    return 0;
}