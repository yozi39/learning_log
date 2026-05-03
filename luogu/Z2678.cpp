//harvest!!! 二分用于求限制条件下的max 和 min;
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int stone[N];
int l,n,m;

int check(int x){//看会删掉哪些在x为期望最小的时候
    int sum=0,last=0;
    for(int i=1;i<=n+1;i++){
        if((stone[i]-last)<x){
            sum++;
        }
        else{
            last=stone[i];//如果假装被删除了那么用last接住防止和删除的比较
        }
    }
    return sum;
}

int main(){
    cin>>l>>n>>m;
    stone[n+1]=l;
    for(int i=1;i<=n;i++){
        cin>>stone[i];
    }

    int left=0,right=l;//二分找合适x
    while(left<right){
        int mid=(left+right+1)/2;
        if(check(mid)<=m){
            left=mid;
        }
        else{
            right=mid-1;
        }
    }
    cout<<left;
}