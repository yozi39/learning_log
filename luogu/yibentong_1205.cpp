/*
    递归基础
*/
#include<bits/stdc++.h>
using namespace std;
//x 盘子的a个 借助y到达z
void dfs(int a,char x,char y,char z){

    if(a==0)return;
    dfs(a-1,x,z,y);
    printf("%c->%d->%c\n",x,a,z);
    dfs(a-1,y,x,z);
}

int main(){
    int a;
    char x,y,z;
    cin>>a>>x>>y>>z;
    dfs(a,x,z,y);
}