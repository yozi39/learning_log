#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=105;

int n,m;
int a[N];
int f[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;

        f[l]++;
        f[r+1]--;
    }

    int pos=0;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+f[i];
        if(a[i]!=1 && pos==0){
            pos=i;
            cout<<i<<' ';
        }
    }
    if(pos==0)cout<<"OK";
    else cout<<a[pos];
}