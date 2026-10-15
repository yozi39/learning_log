#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=32;

int n,nn[N];
LL x,y;
LL k,b;
LL f[N][N];

LL dfs(int pos,bool limit,int cnt){
    if(!pos) return cnt==k;
    if(!limit && ~f[pos][cnt]) return f[pos][cnt];

    int up=limit?nn[pos]:1;
    up=min(up,1);

    LL ret=0;
    for(int i=0;i<=up;i++){
        if(cnt+i>k)continue;
        ret+=dfs(pos-1,limit&&(i==nn[pos]),cnt+i);
    }

    if(!limit)f[pos][cnt]=ret;
    return ret;
}

LL calc(LL x){
    n=0;
    memset(f,-1,sizeof f);

    while(x){
        nn[++n]=x%b;
        x/=b;
    }

    return dfs(n,1,0);
}

int main(){
    cin>>x>>y;
    cin>>k>>b;

    cout<<calc(y)-calc(x-1);
}