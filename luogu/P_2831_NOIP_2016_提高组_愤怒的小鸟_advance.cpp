#include<bits/stdc++.h>
using namespace std;

const int N=18;
const double eps = 1e-7;

int n,m;
double x[N],y[N];
int f[1<<N];
int g[N][N];

bool zero(double x){
    return fabs(x)<=eps;//漏了一个fabs,括号要套x;
}

int main(){
    int T;cin>>T;
    while(T--){
        cin>>n>>m;
        memset(f,0x3f,sizeof f);
        memset(g,0,sizeof g);

        for(int i=0;i<n;i++)cin>>x[i]>>y[i];

        for(int i=0;i<n;i++){
            
            g[i][i] |= 1<<i;
            for(int j=i+1;j<n;j++){
                double x1=x[i],y1=y[i];
                double x2=x[j],y2=y[j];
                if(zero(x1-x2))continue;//漏了
                
                double a = (y1*x2-y2*x1)/(x1*x1*x2-x2*x2*x1);
                if(a>-eps)continue;
                double b = y1/x1 - a*x1;

                for(int k=0;k<n;k++){
                    if(zero(a*x[k]*x[k] + b*x[k] - y[k]))
                        g[i][j] |= 1<<k;
                }
            }
        }

        f[0] = 0;
        for(int s = 0;s<(1<<n);s++){
            int i = 0;
            for(int j = 0;j<n;j++){
                if(!((s>>j)&1)){
                    i = j;
                    break;//少了break就会一直遍历到最后一个0;
                }
            }

            for(int j = i;j<n;j++){//当时忘记遍历只覆盖自己一个的情况
                f[s | g[i][j]] = min(f[s | g[i][j]],f[s]+1);
            }
        }
        cout<<f[(1<<n)-1]<<'\n';
    }
}