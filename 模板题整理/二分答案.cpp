/*
    二分答案模板
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e6+10;
int a[N],t[N];
LL n,k;

LL calc(LL x){//计算可以切多少段在x长度
    LL sum=0;
    for(LL i=1;i<=n;i++){
        sum+=t[i]/x;
    }
    return sum;
}

int main(){
    cin>>n>>k;
    LL left,right;
    left=1;
    int max=-1;
    for(LL i=1;i<=n;i++){ //找max
        cin>>t[i];
        if(t[i]>max)max=t[i];
    }

    right=max;
    int mid;

    while(left<right){
        mid=(right+left+1)/2;
        if(calc(mid)>=k){
            left=mid;
        }
        else{
            right=mid-1;
        }
    }

    if(calc(right)>=k){
        cout<<right;
    }
    else{
        cout<<0;
    }
}