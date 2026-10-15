#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLI;

const int N=22,M=60005,S=1<<20;
const int INF=0x3f3f3f3f;

int n,mid,cnt,ret;
LL a[N];
PLI t[M];
bool vis[S];

void ldfs(int pos,LL sum,int st){
    if(pos>mid){
        t[++cnt]={sum,st};
        return;
    }

    ldfs(pos+1,sum,st);                        // 不选
    ldfs(pos+1,sum+a[pos],st|(1<<pos));       // 放A
    ldfs(pos+1,sum-a[pos],st|(1<<pos));       // 放B
}

void rdfs(int pos,LL sum,int st){
    if(pos>=n){
        PLI l={-sum,-1};
        PLI r={-sum,INF};

        int L=lower_bound(t+1,t+1+cnt,l)-t;
        int R=upper_bound(t+1,t+1+cnt,r)-t;

        for(int i=L;i<R;i++){
            int nst=st|t[i].second;

            if(nst && !vis[nst]){
                vis[nst]=1;
                ret++;
            }
        }
        return;
    }

    rdfs(pos+1,sum,st);                        // 不选
    rdfs(pos+1,sum+a[pos],st|(1<<pos));       // 放A
    rdfs(pos+1,sum-a[pos],st|(1<<pos));       // 放B
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    mid=(n-1)/2;

    ldfs(0,0,0);

    sort(t+1,t+1+cnt);

    rdfs(mid+1,0,0);

    cout<<ret;
}