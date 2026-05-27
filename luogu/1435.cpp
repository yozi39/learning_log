#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
string s;
int f[N][N];

int main(){
    cin>>s;

    int cnt=0;
    for(auto v:s){
        f[cnt][cnt++]=0;
    }

    for(int len=2;len<=s.size();len++){
        for(int i=0;i<=s.size()-len;i++){
            if(s[i]==s[i+len-1])f[len][i]=f[len-2][i+1];
            else{
                f[len][i]=min(f[len-1][i]+1,f[len-1][i+1]+1);
            }
        }
    }
    cout<<f[s.size()][0];
}