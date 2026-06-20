#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,in[N];
vector<int> an[N];

void tuopu(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }

    while(q.size()){
        int x=q.front();q.pop();
        cout<<x<<' ';

        for(auto v:an[x]){
            in[v]--;
            if(in[v] == 0)q.push(v);
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        while(tmp){
            an[i].push_back(tmp);
            in[tmp]++;
            cin>>tmp;
        }
    }

    tuopu();
}