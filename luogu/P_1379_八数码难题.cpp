#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

string s,aim="123804765";
unordered_map<string,int> dist;

void bfs(){
    queue<string> q;
    q.push(s);
    dist[s]=0;

    if(s==aim) return;

    while(q.size()){
        auto t=q.front();q.pop();

        int pos=0;
        while(t[pos]!='0'){
            pos++;
        }

        int x=pos/3,y=pos%3;

        for(int k=0;k<4;k++){
            int a=x+dx[k],
                b=y+dy[k];

            if(a>=0 && a<=2 && b>=0 && b<=2){
                string next=t;
                int p=3*a+b;

                swap(next[p],next[pos]);

                if(dist.count(next)) continue;

                dist[next]=dist[t]+1;
                q.push(next);

                if(next==aim) return;
            }
        }
    }
}

int main(){
    cin>>s;

    bfs();

    cout<<dist[aim]<<qp;
}