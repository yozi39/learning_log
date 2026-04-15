#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string type[n+1][2];
    for(int i=1;i<n+1;i++){
        cin>>type[i][0]>>type[i][1];
    }
    int pos=1;//0 && 0 = -  1&&1=-;
    int command;
    string face;
    for(int i=0;i<m;i++){
        cin>>face>>command;
        if(face == type[pos][0]){
            pos-=command;
            if(pos<1)pos+=n;
        }
        else{
            pos+=command;
            if(pos>n)pos-=n;
        }
    }
    cout<<type[pos][1];
}