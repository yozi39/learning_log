#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=100 && n>=1){
        for(int i=1;i<=n;i++){
            cout<<"line"<<i<<"：hello world!"<<'\n';
        }
    }
    else cout<<"line："<<n<<" is wrong!"<<'\n';
}