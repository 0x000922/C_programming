#include <bits/stdc++.h>

using namespace std;

/*
    -program description

    - You are given an integer x. Can you make x by summing up some number of 11,111,1111,11111,…? 
    (You can use any number among them any number of times).

*/
long long digi11[] = {0, 0, 11, 111, 1111, 11111, 111111, 1111111, 11111111};

int digit(int n)
{

    int cnt = 0;
    while (n > 0)
    {
        n = n / 10;
        cnt++;
    }

    return cnt;
}

bool exitingcombo(int n)
{
    bool flag = false;
    // cout <<  n << " ";
    if( n < 11 and  n > 0)
        return false;
    if( n == 0)
        return true;
    if( n < 0)
        return false;
    else{
        // bool flag = false;
        int n_digi = digit(n);
        if( n_digi >= 9)
            n_digi = 8;
        else if( digi11[n_digi] > n)
            n_digi -= 1;
        for(int i = 2; i <= 8; i++)
            flag = flag || exitingcombo(n - digi11[i]);
    }
    
    return flag;
}

bool comparator( const string &a, const string &b){

    // int na = a.size(), nb = b.size();
    // int t = min(na,nb) - 1;
    // int i = 0;
    string nab = a + b;
    string nba = b + a;     
    for(auto i: a)
    {
        nab.push_back(i);
    }
    for(auto i: b)
    {
        nab.push_back(i);
    }
    for(auto i: b)
    {
        nba.push_back(i);
    }
     for(auto i: a)
    {
        nba.push_back(i);
    }
    if(nab > nba)
    {
        return true;
    }
    else
    {
        return false;
    }

}


string func(){

    vector<string> r = {"89","8" };

    sort(r.begin(), r.end(), comparator);
    // string f = "89";
    string res;

    for( auto j : r)
    {    
        for(auto i : j)
        {   
            res.push_back(i);
        }
    }
    int a = stoi(res);
    cout << a <<  endl;
    return res;
}

int main()
{
    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     int n;
    //     cin >> n;
    //     bool val = exitingcombo(n);
    //     if( val)
    //         cout << "YES";
    //     else
    //         cout << "NO";
    //     cout << endl;
    // }

    cout << func();
    // cout << func( n, k) << endl;
    return 0;
}