#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=12;

int h,w;
long long f[N][1<<N];//遍历的时候先去只看竖着的,然后让st去看横着的可行
bool st[1<<N];//标记i是否合法

int main(){
    while (cin>>h>>w,h&&w)
    {
        memset(st,0,sizeof st);
        memset(f,0,sizeof f);

        //预处理合法状态(连续0个数为偶数)
        for(int i=0;i<(1<<w);i++){
            int cnt = 0;
            for(int j = 0;j<w;j++){
                if((i>>j) & 1){
                    if(cnt&1)break;
                    else cnt = 0;
                } else {
                    cnt++;
                }
            }
            if(cnt&1)continue;
            st[i] = 1;
        }


        f[0][0] = 1;
        for(int i=1;i<=h;i++){
            for(int x = 0;x<(1<<w);x++){
                for(int y = 0 ;y<(1<<w);y++){
                    if(!(x&y) && st[x|y]){
                        f[i][x] += f[i-1][y];
                    }
                }
            }
        }
        cout<<f[h][0]<<'\n';
    }
}