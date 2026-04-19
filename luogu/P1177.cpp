#include<bits/stdc++.h>
#include<ctime>
using namespace std;

const int N=1e5+10;

int n,a[N];

int g_rand(int left,int right){
    int r=rand();
    return a[r%(right-left+1)+left];
}

void sort_q(int left,int right){
    if(left >= right) return;
    int p=g_rand(left,right);
    int l=left-1,i=left,r=right+1;
    while(i<r){
        if(a[i] <p)swap(a[++l],a[i++]);
        else if(a[i] == p) i++;
        else swap(a[--r],a[i]);
    }
    sort_q(left,l);
    sort_q(r,right);
}

int main(){
    srand(time(0));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort_q(1,n);
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}