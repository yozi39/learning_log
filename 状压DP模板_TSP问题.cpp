//1171
//tsp问题要完全图,访问每一个城市一次并且回到原点
#include<bits/stdc++.h>
using namespace std;

const int N=21;

int n;
int f[(1<<N)][N];
int edge[N][N];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>edge[i][j];
        }
    }

    memset(f,0x3f,sizeof f);
    f[1][0] = 0;

    for(int st = 1;st<=(1<<n)-1;st++){
        for(int i=0;i<n;i++){
            if((st>>i) & 1){        
                for(int j=0;j<n;j++){
                    if((st>>j) & 1){
                        f[st][i] = min(f[st][i] ,
                        f[st^(1<<i)][j]+edge[j][i]);
                    }
                }   
            }
        }
    }
    
    int ret = 0x3f3f3f3f;
    for(int i = 1;i<n;i++){
        ret = min(ret,f[(1<<n)-1][i]+edge[i][0]);
    }
    cout<<ret;
}