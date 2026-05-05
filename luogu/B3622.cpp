#include<bits/stdc++.h>
using namespace std;

int n;
string path;

void dfs(int pos){
    if(pos>n){//不可以等于,当pos=3还要继续遍历
        cout<<path<<'\n';
        return;
    }
    else{
        path+='N';
        dfs(pos+1);//++pos会改变下标所以老实用+1
        path.pop_back();
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