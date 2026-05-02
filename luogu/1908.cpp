#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int a[N],tmp[N];
long long sum=0;
//归并貌似是merge???
void dfs(int f,int e){
    int mid=(e+f)/2;

    if(f>=e) return;//原本的mid<1搞混的mid不是长度而是他的中间值 (╬▔皿▔)╯

    dfs(f,mid);
    dfs(mid+1,e);

    int cur1=f,cur2=mid+1,i=f;

    while(cur1<=mid && cur2<=e){
        if(a[cur1]<=a[cur2]){
            tmp[i++]=a[cur1++];
        }
        else{
            sum+=(mid-cur1+1);
            tmp[i++]=a[cur2++];
        }
    }
    while (cur1<=mid)
    {
        tmp[i++]=a[cur1++];
    }
    while (cur2<=e)
    {
        tmp[i++]=a[cur2++];
    }
    for(int j=f;j<=e;j++){
        a[j]=tmp[j];
    }
    return;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    dfs(1,n);
    cout<<sum;
}