#include <bits/stdc++.h>

using namespace std;

/*
    -program description

    a list of n distinct elements, write a function that lists all permutations of that list.


*/
void printarr(vector<int> a)
{
    for (auto i : a)
        cout << i << " ";
    cout << endl;
}

void make(vector<int> nums,int index,vector<int> ans, vector<vector<int>> &res, vector<bool> visited)
{
    int i = 0;
    // cout << !visited[index] << " " << ans.size() << " " <<  nums.size() << endl;
    if(!visited[index] && ans.size() < nums.size())
    {
        ans.push_back(nums[index]);
        visited[index] = true;
    }
    else
    {
        return;
    }
    if( ans.size() == nums.size())
            res.push_back(ans);
    // printarr(ans);
    for(; i < nums.size(); i++)
    {
        if(i == index)
            continue;
        else
        {
            make(nums, i, ans, res, visited);
        }
    }
}
vector<vector<int>> res_v;


void printbigarr()
{
    for (auto i : res_v)
        printarr(i);
}
void all_permutations(vector<int> nums)
{
    

    for(int i = 0; i < nums.size(); i++)
    {
        vector<bool> visited(nums.size(), false);
        
        make(nums, i, vector<int> {}, res_v, visited);
    }

    printbigarr();
}


int main()
{
    vector<int> a{1, 2, 3, 4};

    all_permutations(a);


    return 0;
}