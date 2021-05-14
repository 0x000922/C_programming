#include <bits/stdc++.h>

using namespace std;

/*
    -program description
*/
bool check(string s)
{

    int n = s.size() - 1;

    if(n == 0 or n == 1)
    {
        return true;
    }

    if(s[0] == s[n])
    {
        // passing a reduced string
        
        return check(s.substr(1, n - 1));
    }
    else
    {
        return false;
    }
}



int main()
{
    string t1 = "abc";
    string t2 = "a";
    string t3 = "asdasdasd";
    string t4 = "kanak";

    cout << check(t1) << endl ;
    cout << check(t2) << endl ;
    cout << check(t3) << endl ;
    cout << check(t4) << endl ;

    return 0;
}