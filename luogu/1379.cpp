#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

LL ret;
string A,B;
queue<string> q[2];
unordered_map<string,int> dist[2];

bool extend(int a,int b){
    int sz = q[a].size();

    while(sz--){
        auto f = q[a].front();q[a].pop();

        int pos = 0;
        while(f[pos] != '0')pos++;

        int x = pos/3,y=pos%3;

        for(int k=0;k<4;k++){
            int nx = x+dx[k],
                ny = y+dy[k];
            if(nx<0 || nx>=3 || ny<0 || ny>=3)continue;
            string t = f;
            int npos = nx*3+ny;
            swap(t[pos],t[npos]);

            if(dist[a].count(t)) continue;

            dist[a][t] = dist[a][f]+1;
            q[a].push(t);

            if(dist[b].count(t)){
                ret = dist[a][t]+dist[b][t];
                return true;
            }
        }
    }
    return false;
}

void bfs(){
    q[1].push(B),dist[1][B]=0;
    q[0].push(A),dist[0][A]=0;

    while(q[1].size() && q[0].size()){

        bool flag=false;
        if(q[1].size() < q[0].size()) flag = extend(1,0);
        else flag = extend(0,1);
        if(flag)return;
    }
}

int main(){
    cin>>A;
    B = "123804765";

    bfs();

    if(A==B){
        cout<<0;
        return 0;
    }
    cout<<ret;
}