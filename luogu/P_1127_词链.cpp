//和P1341简直一模一样,唯一的不同点就是要用id去和string打通关系
//之后还原回去
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e3 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n=26,m;
string str[N];
vector<int> ret;
int in[N],out[N];
vector<PII> edge[30];

void dfs(int x){
    while (edge[x].size())
    {
        int y = edge[x].back().first,id = edge[x].back().second;
        edge[x].pop_back();
        dfs(y);
        ret.push_back(id);
    }
}

int main(){
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>str[i];
        int a= str[i].front()-'a',b = str[i].back()-'a';
        edge[a].push_back({b,i});
        in[b]++,out[a]++;
    }
    int s = -1,c = 0;
    for(int i=0;i<n;i++){
        if(abs(in[i]-out[i])>1){
            cout<<"***"<<qp;
            return 0;
        }
        if(in[i] != out[i])c++;
        if(out[i] - in[i] == 1){
            s = i;
        }

        if(s==-1 && out[i])s = i;
    }

    if(c>2){
        cout<<"***"<<qp;
        return 0;
    }

    for(int i=0;i<n;i++)sort(edge[i].begin(),edge[i].end(),[](PII& a,PII& b){
        return str[a.second] > str[b.second];
    });

    dfs(s);

    if(ret.size() != m){
        cout<<"***"<<qp;
        return 0;
    } else {
        for(int i=m-1;i>=1;i--){
            cout<<str[ret[i]]<<'.';
        }
        cout<<str[ret[0]];
    }
}