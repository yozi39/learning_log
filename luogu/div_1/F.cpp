#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int ans[n+1];
    for(int i=1;i<=n;i++){
        cin>>ans[i];
    }
    int change[m+1][2];
    for(int i=1;i<=m;i++){
        cin>>change[i][0]>>change[i][1];
    }
    int ans_o[n+1];
    for(int i=1;i<=q;i++){
        for(int j=1;j<=n;j++)
            ans_o[j]=ans[j];
        int tmp,ques;
        cin>>tmp>>ques;
        for(int j=1;j<tmp;j++)
            ans_o[change[j][0]]=change[j][1];
        cout<<ans_o[ques]<<'\n';
    }
}