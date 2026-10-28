#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define qp '\n'

void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int l=-1,r=-1,cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(l==-1)l=i;
            r=i;cnt++;
        }
    }
    if(cnt==0){
        cout<<0<<qp;
        return;
    }
    int ret=cnt*11;
    if(l<=k)ret=min(ret,cnt*11-1);
    if(n-1-r<=k)ret=min(ret,cnt*11-10);
    if(cnt>=2&&l+n-1-r<=k)ret=min(ret,cnt*11-11);
    cout<<ret<<qp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)solve();
}