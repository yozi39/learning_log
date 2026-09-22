#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=0;
//meow
int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        string v;cin>>v;

        if(n<4){
            cout<<"NO\n";
            continue;
        }

        int pos=0,cnt=0;
        unordered_set<char> mp;

        while(v[pos]=='m' || v[pos]=='M'){
            cnt++;pos++;
            mp.insert('m');
        }
        while(v[pos]=='e' || v[pos]=='E'){
            cnt++;pos++;
            mp.insert('e');
        }
        while(v[pos]=='o' || v[pos]=='O'){
            cnt++;pos++;
            mp.insert('o');
        }
        while(v[pos]=='w' || v[pos]=='W'){
            cnt++;pos++;
            mp.insert('w');
        }

        if(cnt==n && mp.count('m') && mp.count('e') && mp.count('o') && mp.count('w'))cout<<"YES\n";
        else cout<<"NO\n";
    }
}