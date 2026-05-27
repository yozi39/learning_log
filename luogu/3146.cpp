#include<bits/stdc++.h>
using namespace std;

const int N=250;
int n;
int a[N],pre[N],f[N][N];

int main(){
    cin>>n;
    int ans=-0x3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i]; 
        f[i][i]=a[i]; 
        ans=max(ans,a[i]);      
    }

    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                if(f[i][k] && f[i][k]==f[k+1][j]){
                    f[i][j]=max(f[i][j],f[i][k]+1);
                }
                ans=max(ans,f[i][j]);
            }
        }
    }

    cout<<ans;
}