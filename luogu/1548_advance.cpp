#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int zfx=0,cfx(0);
    for(int a=1;a<=n;a++){
        for(int b=1;b<=m;b++){
            if(a==b)zfx+=(n-a+1)*(m-b+1);
            else cfx+=(n-a+1)*(m-b+1);
        }
    }
    cout<<zfx<<' '<<cfx;
}