/*
    两序遍历求第三序的模板
*/
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int n;
int back[N];
int mid[N];
vector<int> a[N];
int st[N];

void dfs(int ml,int mr,int bl,int br){
    
    if(ml>mr){
        return;
    }
    
    int root=back[br];
    cout<<root<<' ';

    int k;
    for(int i=ml;i<=mr;i++){
        if(mid[i]==root){
            k=i;
            break;
        }
    }

    int leftsize=k-ml;

    dfs(ml,k-1,bl,bl+leftsize-1);

    dfs(k+1,mr,bl+leftsize,br-1);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>back[i];
    for(int i=1;i<=n;i++)cin>>mid[i];

    int root=back[n];

    cout<<"Preorder: ";
    dfs(1,n,1,n);
}