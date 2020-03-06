#include <bits/stdc++.h>
using namespace std;

bool solver(int n,string s){
    queue<string> q;
    q.push("1");
    int i=2;
    while(i<=n){
        string temp = q.front();
        q.push(temp+"0");
        q.push(temp+"1");
        if(s.find(temp)==string::npos){
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    cout<<solver(n,s);
}