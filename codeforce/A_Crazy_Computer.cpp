#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=100005;

int n,c,ret,last;

int main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x-last<=c){
            ret++;
            last=x;
        } else {
            ret=1;
            last=x;
        }
    }
    cout<<ret;
}