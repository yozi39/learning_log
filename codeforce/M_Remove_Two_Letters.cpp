#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=0;

string change(char a,char b){
    string tmp;
    if(a>b) tmp=b+a;
    else tmp=a+b;
    return tmp;
}

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        string s;cin>>s;

        int cnt=0;
        for(int i=0;i<n-2;i++){
            if(s[i]==s[i+2])cnt++;
        }

        cout<<n-1-cnt<<'\n';
    }
}