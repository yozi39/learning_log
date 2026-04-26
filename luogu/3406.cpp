#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int Z,M;
int P[N];
int a[N],f[N];

struct P3406
{
    int cost,ic,visa;
}need[N];

int main(){
    cin>>Z>>M;
    for(int i=1;i<=M;i++){
        cin>>P[i];
        f[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=Z-1;i++){
        cin>>need[i].cost>>need[i].visa>>need[i].ic;
    }

    //先看看每个路线要经过几次然后再计算价格;

    int front,back;
    for(int i=1;i<M;i++){
        front=P[i];back=P[i+1];
        if(front>back)swap(front,back);
        f[front]++;
        f[back]--; //不是给站点做记录而是给铁路做记录所以back+1 不对
    }
    for(int i=1;i<=Z-1;i++){
        a[i]=a[i-1]+f[i];
    }

    long long sum=0;
    for(int i=1;i<=Z-1;i++){
        int time=a[i];
        long long no_card = 1LL * time * need[i].cost;
        long long card = 1LL * time * need[i].visa + need[i].ic;
        sum += min(no_card, card);   //优化了用if判断,并且改用long long 防止爆炸
    }
    cout<<sum;
}