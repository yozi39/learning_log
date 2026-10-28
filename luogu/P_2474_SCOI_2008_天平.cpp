#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 50 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,a,b;
vector<PII> edge[N];
int dmin[N][N],dmax[N][N];

int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            char ch;cin>>ch;
            if(i == j || ch == '=')dmin[i][j] = dmax[i][j] = 0;
            else if(ch == '+')dmin[i][j] = 1,dmax[i][j] = 2;
            else if(ch == '-')dmin[i][j] = -2,dmax[i][j] = -1;
            else dmin[i][j] = -2,dmax[i][j] = 2;
        }

    for(int k = 1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dmin[i][j] = max(dmin[i][j],dmin[i][k] + dmin[k][j]);
                dmax[i][j] = min(dmax[i][j],dmax[i][k] + dmax[k][j]);
            }
        }
    }
    
    int c1,c2,c3;c1=c2=c3=0;
    for(int i=1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(i == a || j == a || i == b || j == b)continue;

            if(dmin[a][i] > dmax[j][b] || dmin[a][j] > dmax[i][b])c1++;
            else if(dmax[a][i] < dmin[j][b] || dmax[a][j] < dmin[i][b])c3++;
            else if(dmin[a][i] == dmax[a][i] && dmin[j][b] == dmax[j][b] && dmin[a][i] == dmax[j][b])c2++;
            else if(dmin[a][j] == dmax[a][j] && dmin[i][b] == dmax[i][b] && dmin[a][j] == dmax[i][b])c2++;
        }
    }

    cout<<c1<<' '<<c2<<' '<<c3;
}