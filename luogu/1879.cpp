#include<bits/stdc++.h>
using namespace std;

const int N=15,MOD=1e8;

int n,m;
int a[N];
int f[N][1<<12];
vector<int> way[N];

int main(){
    cin>>m>>n;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x;cin>>x;
            if(x)a[i]|=(1<<(j-1));
        }

        for(int st=0;st<(1<<n);st++){
            if(st&(st>>1))continue;
            if((st&a[i])!=st)continue;

            way[i].push_back(st);
        }
    }

    way[0].push_back(0);
    f[0][0]=1;

    for(int i=1;i<=m;i++){
        for(auto x:way[i]){
            for(auto y:way[i-1]){
                if(x&y)continue;

                f[i][x]=(f[i][x]+f[i-1][y])%MOD;
            }
        }
    }

    int ret=0;
    for(int st=0;st<(1<<n);st++){
        ret=(ret+f[m][st])%MOD;
    }

    cout<<ret;
}