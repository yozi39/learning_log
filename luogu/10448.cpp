#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n,m;
int ans[N];//st[N];排列枚举
//应该用start控制只能往后选的组合枚举

void dfs(int x,int start){

    if(x>m){
        for(int i=1;i<=m;i++){
            printf("%d ",ans[i]);
        }
        cout<<'\n';
        return;
    }

    else{
        for(int i=start;i<=n;i++){//start好处当1 5 ? 时候
            ans[x]=i;           //start因为dfs(3,6)直接退出循环并且不进入输出分支
            dfs(x+1,i+1);
        }
    }
}

int main(){
    cin>>n>>m;
    dfs(1,1);
    return 0;
}