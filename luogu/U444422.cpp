#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,a[N];
int p=0,h=1;

void push(int x){
    a[++p]=x;
}

void pop(){
    h++;
}

int front(){
    return a[h];
}

int size(){
    return p-h+1;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        switch (num)
        {
        case 1:
            int tmp;
            cin>>tmp;
            push(tmp);
            break;
        case 2:
            if(size()>=1){
                pop();
            }
            else cout<<"ERR_CANNOT_POP"<<'\n';
            break;
        case 3:
            if(size()>=1){
                cout<<front()<<'\n';
            }
            else cout<<"ERR_CANNOT_QUERY"<<'\n';
            break;
        case 4:
            cout<<size()<<'\n';
            break;
        
        default:
            break;
        }
    }
}