#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)

const int N=25;

int n,m;
vector<int> edge[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int cnt=0;
    for(int i=0;i<(1<<n);i++){
        int x=i;
        bool ok=true;

        while(x){
            int u=__builtin_ctz(x)+1;

            for(auto v:edge[u]){
                if(i&(1<<(v-1))){
                    ok=false;
                    break;
                }
            }

            if(!ok)break;

            x-=lowbit(x);
        }

        if(ok)cnt++;
    }

    cout<<cnt;
}