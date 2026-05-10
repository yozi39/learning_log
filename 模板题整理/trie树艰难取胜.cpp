#include<bits/stdc++.h>
using namespace std;

const int N=3e6+10;
int T;
int n,q;
string s;
int e[N],idx=0;
vector<array<int,75>> tree;//MLE 改进
vector<int> p;

/*出现次数练习一遍虽然与题目无关
int cnt(string& s){
    int cur=0;
    for(auto v:s){
        int path=v-'0';
        if(tree[cur][path]==0)return 0;
        cur=tree[cur][path];
    }
    return e[cur];
}
*/

void insert(string& s){
    int cur=0;
    p[cur]++;

    for(auto v:s){
        int path=v-'0';
        if(tree[cur][path]==0){
            tree.push_back({});
            tree[cur][path]=tree.size()-1;
            //tree[cur][path]=++idx;
            p.push_back(0);
        }
        cur=tree[cur][path];
        p[cur]++;
    }
    e[cur]++;
    return;
}

int find(string& s){
    int cur=0;
    for(auto v:s){
        int path=v-'0';
        if(tree[cur][path]==0)return 0;
        cur=tree[cur][path];
    }
    return p[cur];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    tree.reserve(3000005);

    cin>>T;
    while(T--){
        idx=0;
        p.clear();
        p.push_back(0);
        //memset(p,0,sizeof(p));
        tree.clear();
        tree.push_back({});
        //memset(tree,0,sizeof(tree));
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>s;
            insert(s);
        }
        for(int i=1;i<=q;i++){
            cin>>s;
            cout<<find(s)<<'\n';
        }
    }
}