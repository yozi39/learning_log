#include<bits/stdc++.h>
using namespace std;

string path;
int n;

void dfs(int pos){
    if(pos>n){
        cout<<path<<'\n';
    }
    else{
        //no
        path+='N';
        dfs(pos+1);
        path.pop_back();
        //yes
        path+='Y';
        dfs(pos+1);
        path.pop_back();
    }
}

int main(){
    cin>>n;
    dfs(1);
    return 0;
}