#include<bits/stdc++.h>
using namespace std;

const int N=105;

int cnt[N];

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=1;i<=100;i++)cnt[i]=0;

        for(int i=1;i<=n;i++){
            int x;cin>>x;
            cnt[x]++;
        }

        for(int k=1;k<=n;k++){
            for(int i=100;i>=1;i--){
                if(cnt[i]>=k){
                    cout<<i<<' ';
                }
            }
        }
        cout<<'\n';
    }
}