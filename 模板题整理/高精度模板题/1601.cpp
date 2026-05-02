#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+10;

int a[MAXN],b[MAXN],c[MAXN]={0};
string s1,s2;
int l1,l2,l3;

void ADD(int c[],int a[],int b[]){
    for(int i=0;i<l3;i++){
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if(c[l3])l3++;
}

int main(){
    cin>>s1>>s2;
    l1=s1.size();l2=s2.size();l3=max(l1,l2);
    for(int i=0;i<=l1-1;i++){
        a[l1-1-i]=s1[i]-'0';
    }
    for(int i=0;i<=l2-1;i++){
        b[l2-1-i]=s2[i]-'0';
    }
    ADD(c,a,b);
    for(int i=l3-1;i>=0;i--)cout<<c[i];
    return 0;
}