//P1032
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 10;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

LL ret;
string A,B;
string a[N],b[N];
queue<string> q[2];
unordered_map<string,int> dist[2];
int cnt;

LL extend(int target,int refer,string a[],string b[]){
    int sz = q[target].size();
    while(sz--){
        auto s = q[target].front();q[target].pop();

        for(int i=0;i<cnt;i++){
            int pos=0;
            
            while((pos = s.find(a[i],pos)) != -1){
                string t = s.substr(0,pos)+b[i]+s.substr(pos+a[i].size(),s.size());
                pos++;
                
                if(!dist[target].count(t)){
                    dist[target][t] = dist[target][s] + 1;
                    q[target].push(t);
                }

                if(dist[refer].count(t)){
                    return dist[refer][t]+dist[target][t];
                }
            }
        }
    }

    return 111;
}

LL bfs(){
    if(A==B)return 0;

    q[0].push(A);
    q[1].push(B);
    dist[0][A]=0;
    dist[1][B]=0;
    int step = 0;

    while(q[1].size() && q[0].size()){
        step++;
        if(step>10)return 11;
        
        if(q[0].size()<=q[1].size()) ret = extend(0,1,a,b);
        else ret = extend(1,0,b,a);

        if(ret<=10)return ret;
    }

    return 11;
}

int main(){
    cin>>A>>B;
    while(cin>>a[cnt]>>b[cnt])cnt++;

    ret = bfs();
    if(ret>10)cout<<"NO ANSWER!"<<qp;
    else cout<<ret<<qp;
}