#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e6+10;
LL t[N];
LL n,m;

LL cal(int x){
    LL sum=0;
    for(int i=1;i<=n;i++){
        if(t[i]>x){
            sum+=(t[i]-x);
        }
    }
    return sum;
}

int main(){
    cin>>n>>m;
    int max=-1;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        if(t[i]>max)max=t[i];
    }

    int left=0,right=max;
    while(left<right){
        LL mid=(left+right+1)/2;
        if(cal(mid)>=m){
            left=mid;
        }
        else{
            right=mid-1;
        }
    }
    cout<<right;
}