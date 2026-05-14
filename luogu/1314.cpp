#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int N=2e5+10;
LL n,m,s;
LL y=0;
PII stone[N],range[N];
//找出合适并且min那么就是二分的right=mid模式;

bool cmp(PII a,PII b){
    return a.first<b.first;
}

        // LL check(int l,int r,int W){//给出当前的y
        //     //先完成对于公式的模拟;
        //     LL sum=0,cnt=0;
        //     for(int i=l;i<=r;i++){
        //         if(stone[i].first>=W){
        //             cnt++;
        //             sum+=stone[i].second;
        //         }
        //     }
        //     return cnt*sum;
        // }

        // LL search(int M){
        //     y=0;
        //     for(int i=1;i<=m;i++){
        //         y+=check(range[i].first,range[i].second,M);
        //     }
        //     return y;
        // }

LL cnt[N], sumv[N];
LL cal(int W){
    cnt[0] = 0;
    sumv[0] = 0;

    for(int i=1;i<=n;i++){
        cnt[i] = cnt[i-1];
        sumv[i] = sumv[i-1];

        if(stone[i].first >= W){
            cnt[i]++;
            sumv[i] += stone[i].second;
        }
    }

    LL y = 0;

    for(int i=1;i<=m;i++){
        int l = range[i].first;
        int r = range[i].second;

        LL num = cnt[r] - cnt[l-1];
        LL val = sumv[r] - sumv[l-1];

        y += num * val;
    }

    return y;
}

//可以调整的是W,要求的条件是|s-y|min;找到W就可以调整y让绝对值最大就是y最接近s的数字;
int main(){
    int maxn=0;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>stone[i].first>>stone[i].second;
        maxn=max(maxn,stone[i].first);
    }
    for(int i=1;i<=m;i++){
        cin>>range[i].first>>range[i].second;
    }

    int left=0,right=maxn;
    while(left<right){
        int mid=(left+right)/2;
        if(cal(mid)<=s)right=mid;
        else{
            left=mid+1;
        }
    }

    if(cal(right)==s){
        cout<<0;
        return 0;
    }
    else{
        LL ans=min(abs(s-cal(right)),abs(s-cal(right-1)));
        cout<<ans;
    }
}
/*
1.sort破坏给定区间删掉
2.函数里面没有y=0的初始化导致会变多
3.check 函数会超时   把check函数和search合并变成一个cal函数并前缀和优化;
*/