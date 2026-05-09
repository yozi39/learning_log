#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
deque<int> q,p;
int n,k;
int a[N],maxn[N],minn[N];

void emm(){
    for(int i=1;i<=n;i++){
        while(q.size() && a[q.back()]<=a[i])q.pop_back();
        q.push_back(i);
        if(i-q.front()+1>k)q.pop_front();
        if(i>=k){
            maxn[i-k+1]=a[q.front()];
        }
    }

    for(int i=1;i<=n;i++){
        while(p.size() && a[p.back()]>=a[i])p.pop_back();
        p.push_back(i);
        if(i-p.front()+1>k)p.pop_front();
        if(i>=k){
            minn[i-k+1]=a[p.front()];
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];

    emm();
    
    for(int i=1;i<=n-k+1;i++)cout<<minn[i]<<' ';
    cout<<'\n';
    for(int i=1;i<=n-k+1;i++)cout<<maxn[i]<<' ';

}