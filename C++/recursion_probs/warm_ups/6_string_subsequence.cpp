#include <bits/stdc++.h>

using namespace std;

/*
    -program description
*/

bool check(string s1, string s2)
{
    if(s1.size() == 0)
        return true;
    
    if(s2.size() == 0)
        return false;

    
    if(s1[0] == s2[0])
    {
        return check( s1.substr(1, s1.size() - 1), s2.substr(1, s2.size() - 1));
    }
    return check( s1, s2.substr(1, s2.size() - 1));


}

int main()
{
    string s1 = "tb";
    string s2 = "table";

    cout << check(s1, s2) << endl;
    // s1 = ;
    // s2 = ;
    
    return 0;
}