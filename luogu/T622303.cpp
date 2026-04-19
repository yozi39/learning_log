#include<bits/stdc++.h>
using namespace std;

typedef struct stu{
    string name;
    int score;
}stu;

int main(){
    int N;
    cin>>N;
    stu hum[N];
    for(int i=0;i<N;i++)
        cin>>hum[i].name>>hum[i].score;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(hum[i].score<hum[j].score){
                swap(hum[i].score,hum[j].score);
                swap(hum[i].name,hum[j].name);
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<hum[i].name<<' '<<hum[i].score<<'\n';
    }
}