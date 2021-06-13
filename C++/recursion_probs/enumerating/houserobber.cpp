#include <bits/stdc++.h>

using namespace std;

/*
    -program description
*/
// int max_c ;
// recursive solution
int max_count( vector<int> &nums, int i, int curr, int &max_c)
{
    if(i > nums.size() - 1)
    {
        return curr;
    }
    curr += nums[i];
    max_c = max( max_c, curr);
    // max_c = max(max_c, curr);
    int p;
    for(int s = i + 2; s < nums.size(); s++)

    {
        cout << curr << " ";
        // cout << max_count(nums, s, curr, max_c) << " ";
        // p = ;
        max_c = max(max_count(nums, s, curr, max_c), max_c);
    }
    
    return max_c;
}


int main()
{
    
    vector<int> a {2 ,7, 9, 3, 1};
    int max_c = -1;
    cout << endl;
    cout << max_count(a, 0, 0, max_c);
    cout << endl << max_c;
    return 0;
}