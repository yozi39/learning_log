#include<bits/stdc++.h>
using namespace std;

const int N = 8e5+5;

string s,t;
int n,d[N],m;

int main(){
    cin>>n>>t;
    s = ' ';
    for(auto v:t){
        s+="#";
        s+=v;
    }
    s+="##";
    m = s.size()-2;

    bool flag = false;
    for(int i=2,l=1,r=1;i<=m;i++){
        int len = r>=i? min(d[r-i+l],r-i+1):1;
        while(s[i-len] == s[i+len])len++;
        if(i+len-1>r){
            r = i+len-1,l = i-len+1;
            if(r==m)flag = true;
        }
        d[i] = len;
        if(flag){
            cout<<n-d[i]+1;
            return 0;
        }
    }
}