#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,a[N],pos[N];

int main(){
    int T;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pos[a[i]]=i;
        }

        bool ok=true;
        int st=1;

        if(n%2){
            if(pos[1]%2==0)ok=false;
            st=2;
        }

        for(int i=st;i<n;i+=2){
            if(pos[i]%2==pos[i+1]%2){
                ok=false;
                break;
            }
        }

        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
}