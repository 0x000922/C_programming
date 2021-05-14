#include <bits/stdc++.h>

using namespace std;

/*
    -program description

    - making all subset of all elements of n distint elements


    + recursive solution

*/

set<vector<int>> res;
vector<vector<int>> res_v;

void subsets_build_recur(vector<int> nums, int index, vector<int> ans)
{

    if (index > nums.size())
        return;

    ans.push_back(nums[index]);
    res_v.push_back(ans);

    for (int i = index + 1; i < nums.size(); i++)
    {
        subsets_build_recur(nums, i, ans);
    }
    // res.insert(ans);
}

vector<vector<int>> subsets_build_itr(vector<int> a)
{
    vector<vector<int>> res;

    int n = a.size();

    // subset can have varying lengths i.e. from 1 to n

    // for(int i = 1; i < n; i++)
    int i = 1;
    while (i <= n)
    {
        int cnt = i;

        for (int j = 0; j < n; j++)
        {
            vector<int> temp;
            int k = j;
            cnt = i;
            while (cnt > 0 and k < n)
            {
                // cout << cnt << " ";
                temp.push_back(a[k]);
                k++;
                cnt--;
            }
            res.push_back(temp);
            // cout << temp.size() << endl;
        }
        i++;
    }

    return res;
}

void printarr(vector<int> a)
{
    for (auto i : a)
        cout << i << " ";
    cout << endl;
}
void printbigarr()
{
    for (auto i : res_v)
        printarr(i);
}
void printset()
{

    for (auto i : res)
        printarr(i);
}

int main()
{
    vector<int> a{1, 2, 3, 4};

    // auto res = subsets_build_itr(a);

    // for(auto i : res)
    //     printarr(i);

    for(int i = 0; i < a.size(); i++)
        subsets_build_recur(a, i, vector<int>{});
    printbigarr();
    // printset();

    return 0;
}