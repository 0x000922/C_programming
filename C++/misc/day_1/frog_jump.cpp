#include <bits/stdc++.h>

using namespace std;

/*
    -program description

    - frog jump question
    where input
    N
    h1 h2 h3 h4

*/
void print1Dvi(vector<int> a)
{
    for(auto i: a)
        cout << i << " ";

    cout << "\n";
}
int mcost = INT_MAX;

void mincost(vector<int>& h, int i, vector<int>& dp, int net)
{
	

	// int h1 = abs(mincost(h, i + 1, dp) - h[i]);
	// int h2 = abs(mincost(h, i + 2, dp) - h[i]);
	// // dp[i] = min( h1, h2);
	// return dp[i];
    //return 0;
	// cout << net << " ";
	if(i == h.size() - 1)
	{
		mcost = min(mcost, net);
		// cout << mcost << " ";
		// return;
	}
	if( i >= h.size())
		return;

	if(i + 2 < h.size())
	{
		 
		mincost(h, i + 1, dp, net + abs(h[i] - h[i + 1]));
		 
		//  cout << endl;
		 mincost(h, i + 2, dp, net + abs(h[i] - h[i + 2]));
	}
	else{
		if(i + 1 < h.size())
		{
			mcost = min(net  + abs( h[i] - h[i + 1]), mcost);
		}
	}


}

int mincostdpkjumps(vector<int>& h, vector<int>& dp, int k)
{
	int n = h.size();
	if( n == 2)
		return abs(h[0] - h[1]);
	int i = n - 1;
	dp[i] = 0;
	i--;
	for(; i >= n - 1 - k && i >= 0; i--)
	{
		dp[i] = abs(h[i] - h[n - 1]);  // filling up the inital dp table for k steps
	}
	for(; i >= 0; i--)
	{
		int j = i + 1;
		for(; j < n && abs(j - i) <= k; j++) // searching for the min jump within k upsteps
		{
			dp[i] = min(
				dp[j] + abs(h[i] - h[j]),
				dp[i]);
				// dp[j] + abs(h[i] - h[j]));
		}
	}
	return dp[0];
}

int mincostdp(vector<int>& h, vector<int> &dp)
{
	int n = h.size();
	if( n == 2)
		return abs(h[0] - h[1]);
	
	int i = n - 1;
	dp[i] = 0, dp[i - 1] = abs(h[i] - h[i - 1]);
	i -= 2;
	for(; i >= 0; i--)
	{
		dp[i] = min(
			dp[i + 1] + abs(h[i] - h[i + 1]),
			dp[i + 2] + abs(h[i] - h[i + 2])
		);
	}

	return dp[0];


}

int main()
{
	int N,  k;
	cin >> N;
	cin >> k;
    	vector<int> h;
    	for(int i = 0; i < N; i++)
    	{
        	int x;
        	cin >> x;
        	h.push_back(x);

    	}
	vector<int> dp(N,INT_MAX);
	cout << mincostdpkjumps(h, dp, k) << endl;
    // print1Dvi(dp);
    return 0;
}
