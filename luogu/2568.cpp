#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e7+10;
int n,phi[N],p[N],cnt;
LL f[N];

bool st[N];
void get_phi(){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!st[i]){
            phi[i]=i-1;
            p[++cnt]=i;
        }
        
        for(int j=1;1ll*i*p[j]<=n;j++){
            int x=i*p[j];
            st[x]=true;
            if(i%p[j]==0){
                phi[x]=phi[i]*p[j];
                break;
            }
            else{
                phi[x]=phi[i]*(p[j]-1);
            }
        }
    }
}

int main(){
    cin>>n;
    if(!n){
        cout<<0;
        return 0;
    }

    get_phi();
    for(int i=1;i<=n;i++)f[i]=f[i-1]+phi[i];

    LL sum=0;
    for(int i=1;i<=cnt;i++){
        sum+=f[n/p[i]]*2-1;
    }
    cout<<sum;

}