#include<bits/stdc++.h>
using namespace std;
//p2158
const int N=4e4+10;
int n,p[N],phi[N];

bool st[N];int cnt;
void give_phi(){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!st[i]){
            p[++cnt]=i;
            phi[i]=i-1;
        }

        for(int j=1;1ll*i*p[j]<=n;j++){
            st[i*p[j]]=true;
            if(i%p[j]==0){
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
            else{
                phi[i*p[j]]=phi[i]*(p[j]-1);
            }
        }
    }
}

int main(){
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }

    give_phi();

    long long ans=0;
    for(int i=1;i<n;i++){
        ans+=phi[i];
    }
    cout<<2*ans+1;
}