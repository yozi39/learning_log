//https://www.luogu.com.cn/problem/UVA529
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
int path[N];

bool dfs(int pos,int depth){
    if(pos>depth) return path[pos-1] == n;

    for(int i=0;i<pos;i++){
        for(int j=i;j<pos;j++){
            int x = path[i] + path[j];

            //当前剪枝
            if(x <= path[pos-1])continue;
            if(x>n)break;
            //预测剪枝
            if(x+depth-pos>n)break;
            if(x*(1<<(depth-pos))<n)continue;
            
            path[pos] = x;
            if(dfs(pos+1,depth)) return true;
        }
    }

    return false;
}

int main(){
    path[0] = 1;
    while(cin>>n,n){
        for(int depth=0;;depth++){
            if(dfs(1,depth)){
                //因为是UVA
                cout<<1;
                for(int i=1;i<=depth;i++){
                    cout<<' '<<path[i];
                }
                cout<<qp;
                break;
            }
        }
    }
}