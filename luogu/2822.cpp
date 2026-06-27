#include<iostream>
using namespace std;

const int N=2010;

int n,m,k;
int f[N][N];
int g[N][N];


void get_table(){
    for(int i=0;i<=2000;i++){
        f[i][0]=1;
        for(int j=1;j<=i;j++){
            f[i][j]=(f[i-1][j-1]+f[i-1][j])%k;
            g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+(f[i][j] == 0 ? 1:0);
        }
        g[i][i+1]=g[i][i];
    }
}

int main(){
    int T;scanf("%d%d",&T,&k);
    get_table();
    while(T--){
        scanf("%d%d",&n,&m);
        printf("%d\n",g[n][min(n,m)]);
    }
}