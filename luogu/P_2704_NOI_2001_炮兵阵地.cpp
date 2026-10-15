#include<bits/stdc++.h>
using namespace std;

const int N=105,M=11;

int n,m;
int mp[N];
int f[2][1<<M][1<<M];
vector<int> way[N],sta;

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            char ch;cin>>ch;
            if(ch=='P')mp[i]|=(1<<j);
        }
    }

    for(int st=0;st<(1<<m);st++){
        if(st&(st>>1))continue;
        if(st&(st>>2))continue;

        sta.push_back(st);
    }

    way[0].push_back(0);

    for(int i=1;i<=n;i++){
        for(auto st:sta){
            if((st&mp[i])!=st)continue;

            way[i].push_back(st);
        }
    }

    memset(f,-1,sizeof f);
    f[0][0][0]=0;

    for(int i=1;i<=n;i++){
        int cur=i&1;
        int pre=cur^1;

        memset(f[cur],-1,sizeof f[cur]);

        for(auto x:way[i]){
            for(auto y:way[i-1]){
                if(x&y)continue;

                for(auto z:sta){
                    if(f[pre][y][z]==-1)continue;
                    if(x&z)continue;

                    f[cur][x][y]=max(
                        f[cur][x][y],
                        f[pre][y][z]+__builtin_popcount(x)
                    );
                }
            }
        }
    }

    int ret=0;
    int cur=n&1;

    for(auto x:way[n]){
        for(auto y:way[n-1]){
            ret=max(ret,f[cur][x][y]);
        }
    }

    cout<<ret;
}