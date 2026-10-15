#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=15;

int n,nn[N];
LL f[N][10];

//收获,这里要维护一个flag去防止前导0错误导致wind提前判断,导致错误
LL dfs(int pos,bool limit,int prev,bool flag){
    if(!pos) return 1;
    if(!limit && ~f[pos][prev] && flag)return f[pos][prev];

    int up = limit ? nn[pos] : 9;//漏了最大上线

    LL ret = 0;
    for(int i=0;i<=up;i++){
        if(abs(i-prev)<2 && flag)continue;

        ret += dfs(pos-1,limit? i==nn[pos]:0,i,flag || (i!=0));
    }

    return (!limit && flag)? f[pos][prev] = ret:ret;
}

LL calc(LL x){
    memset(f,-1,sizeof f);
    n=0;//又忘记清理了!!!
    bool flag = false;
    while(x){
        nn[++n] = x%10;
        x /= 10;
    }

    return dfs(n,1,-2,flag);
}

int main(){
    LL a,b;
    while(cin>>a>>b){
        cout<<calc(b)-calc(a-1)<<'\n';
    }
}