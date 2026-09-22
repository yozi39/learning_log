#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=3005;

int n;
int a[N];

int main(){
    int T;cin>>T;

    while(T--){
        cin>>n;
        int minn=1e9;
        for(int i=1;i<=3;i++){
            int x;cin>>x;
            if(x<n)minn = min(minn,x);
        }
        if(minn != 1e9)cout<<n-minn<<'\n';
        else cout<<0<<'\n';
    }
}