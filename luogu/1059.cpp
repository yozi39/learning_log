#include<bits/stdc++.h>
#include<cstdlib>
#define MAXN 1005
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,cnt=0;
    cin>>N;
    int num[MAXN]={0};
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        num[tmp]++;
        cnt++;
        if(num[tmp] >1)cnt--;
    }
    cout<<cnt<<'\n';
    for(int i=0;i<MAXN;i++){
        if(num[i]>=1)cout<<i<<' ';
    }
}