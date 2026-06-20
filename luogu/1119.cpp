#include<bits/stdc++.h>
using namespace std;

const int N = 205;
const int INF = 0x3f3f3f3f;

int n,m;
int t[N],f[N][N];

struct P1119{
    int x,y,z;
}comd[50005];

int pos;

int main(){
    cin >> n >> m;

    memset(f,0x3f,sizeof f);
    for(int i=0;i<n;i++){
        cin >> t[i];
        f[i][i]=0;
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        f[a][b]=f[b][a]=min(f[a][b],c);
    }

    int T;
    cin >> T;

    for(int i=1;i<=T;i++){
        cin >> comd[i].x >> comd[i].y >> comd[i].z;
    }

    int now = 0; // 当前已经开放到哪个城市

    for(int q=1;q<=T;q++){
        int x = comd[q].x;
        int y = comd[q].y;
        int z = comd[q].z;

        // 把所有修复时间 <= z 的城市加入 Floyd
        while(now < n && t[now] <= z){
            int k = now;

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }

            now++;
        }

        if(t[x] > z || t[y] > z || f[x][y] == INF){
            cout << -1 << '\n';
        }
        else{
            cout << f[x][y] << '\n';
        }
    }
}


































// #include<bits/stdc++.h>
// using namespace std;
// const int N=205;

// int n,m;
// int t[N],f[N][N];

// struct P1119
// {
//     int x,y,z;
// }comd[50005];
// int pos;

// int main(){
//     cin>>n>>m;
//     memset(f,0x3f,sizeof f);
//     for(int i=0;i<n;i++){
//         cin>>t[i];
//         f[i][i]=0;
//     }
//     for(int i=0;i<m;i++){
//         int a,b,c;cin>>a>>b>>c;
//         f[a][b]=f[b][a]=min(f[a][b],c);
//     }
//     int T;cin>>T;
//     while(T--){
//         cin>>comd[++pos].x>>comd[pos].y>>comd[pos].z;
//     }
//     int mpos=1;
//     for(int k=0;k<n;k++){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//             }
//         }
//         while (pos >= mpos && comd[mpos].z==k+1)
//         {
//             if(t[comd[mpos].y] > k || f[comd[mpos].x][comd[mpos].y]==0x3f3f3f3f){
//                 cout<<-1<<'\n';
//             }
//             else{
//                 cout<<f[comd[mpos].x][comd[mpos].y]<<'\n';
//             }
//             mpos++;
//         }
//     }
// }   