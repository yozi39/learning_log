//1896
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=10;

int n,k;
LL f[N][N*N][1<<N];
vector<int> st;
int c[1<<N];

int main(){
    cin>>n>>k;

    for(int s=0;s<(1<<n);s++){
        if(s&(s>>1))continue;

        st.push_back(s);
        for(int i=0;i<n;i++){
            if((s>>i)&1)c[s]++;
        }
    }

    f[0][0][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(auto x:st){
                if(j<c[x])continue;

                for(auto y:st){
                    if((x&y)||(x&(y>>1))||(x&(y<<1))){
                        continue;
                    }

                    f[i][j][x]+=f[i-1][j-c[x]][y];
                }
            }
        }
    }

    LL ret=0;
    for(auto x:st)ret+=f[n][k][x];

    cout<<ret;
}


/*
补充知识:枚举子状态

for(int x=0;x<(1<<n);x++){
    for(int y=x;;y = x&(y-1)){
        //这里就是子状态
        if(!y) break;
    }
}
*/