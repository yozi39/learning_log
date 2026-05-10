#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n,m;
long long a[N];

long long find(long long x){//给定一个x看有多少断
    long long sum=0,ret=1;
    for(int i=1;i<=n;i++){
        if(sum+a[i]>x){
            sum=a[i];
            ret++;
        }
        else{
           sum+=a[i]; 
        }
    }
    return ret;
}

int main(){
    cin>>n>>m;long long right=0,left=0;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        left=max(left,a[i]);
        right+=a[i];
    }

    while(left<right){
        long long mid=(left+right)/2;
        if(find(mid)<=m){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    cout<<right;
}