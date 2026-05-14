#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,m;
int a[N];
long long pre[N];
deque<int> q;

int main(){
    cin>>n>>m;
    pre[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    long long ans=-0x3f3f3f3f,sum=0;
    q.push_back(0);
    for(int i=1;i<=n;i++){
        while(q.size() && q.front()<i-m)q.pop_front();
        ans=max(ans,pre[i]-pre[q.front()]);
        while(q.size() && pre[i]<pre[q.back()])q.pop_back();
        q.push_back(i);
    }

    cout<<ans;
}