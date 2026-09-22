#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n;
int pre[N];

int main(){
    int T;cin>>T;

    while(T--){
        string s;
        cin>>n>>s;
        s=' '+s;

        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+(s[i]=='1');
        }

        if(s[1]=='1'){
            cout<<n-pre[n]<<'\n';
            continue;
        }

        int ans=n;
        for(int i=1;i<=n;i++){
            int l=pre[i];
            int r=(n-i)-(pre[n]-pre[i]);

            ans=min(ans,l+r);
        }

        cout<<ans<<'\n';
    }
}