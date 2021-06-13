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
void print2dvi(vector<vector<int>> a)
{
    for(auto i: a)
        print1Dvi(i);
    cout  << endl;
}
int search_k(int i, int j, vector<vector<int>> &a, unordered_map<int,vector<int>> &nums){

    int target = -1 * a[i][j];
    int k = -1;
    
    vector<int> b = nums[target];

    if(a.size() != 0)
    {
        for(auto l : b)
        {
            if( l != i and l != j)
                return l;
        }
    }

// 
    // for(k = 0 ; k < nums.size(); k++){
        // if(nums[k] == target and k != i and k != j){
            // return k;
        // }
    // }
    return -1;

}

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> pairsum(n, vector<int>(n, 0));

    unordered_map<int, vector<int>> mmfreq;

    for(int i = 0; i < n; i++)
    {
        mmfreq[nums[i]].push_back(i);
    }

    set<vector<int>> res;
    vector<vector<int>> resi;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(i != j)
            {
                pairsum[i][j] = nums[i] +  nums[j];
                // pairsum[j][i] = nums[i] + nums[j];
            }
        }
    }

    print2dvi(pairsum);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int k = -1;
            if(i != j)
            {
                k = search_k(i, j, pairsum, mmfreq);
                if(k != -1)
                {
                    vector<int> a {nums[i], nums[j], nums[k]};
                    sort(a.begin(), a.end());
                    res.insert(a);
                }
                k = -1;
            }

        }
    }    
    for(auto i: res)
    {
        resi.push_back(i);
    }
    return resi;

}

int main()
{
    vector<int> a {-1,0,1,2,-1,-4};
    cout << 1;
    vector<vector<int>> res = threeSum(a);
    print2dvi(res);
    return 0;
}