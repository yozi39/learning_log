#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N = 1e5+5;

int k;

int dist[N];
bool st[N];
int bfs(){
    deque<PII> q;
    q.push_back({1,1});

    while (q.size())
    {
        auto t = q.front();q.pop_front();
        int x = t.second,w = t.first;
        if(x==0)return w;

        if(st[x])continue;
        st[x] = true;
        
        q.push_front({w,(x*10)%k});
        q.push_back({w+1,(x+1)%k});
    }
    return -1;
}

int main(){
    cin>>k;

    cout<<bfs();

}