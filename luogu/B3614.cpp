#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int n;
        stack<unsigned long long> a;
        cin>>n;
        string command;
        for(int i=1;i<=n;i++){
            cin>>command;
            if(command=="push"){
                unsigned long long tmp;
                cin>>tmp;
                a.push(tmp);
            }
            if(command=="query"){
                if(a.empty())cout<<"Anguei!"<<'\n';
                else{
                    cout<<a.top()<<'\n';
                }
            }
            if(command=="size"){
                cout<<a.size()<<'\n';
            }
            if(command=="pop"){
                if(a.empty())cout<<"Empty"<<'\n';
                else{
                    a.pop();
                }
            }
        }
    }
}//数值很大所以要用 unsigned long long