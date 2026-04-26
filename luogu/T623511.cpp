#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

struct T623511
{
    int year,month,day,id;
    string name;
}name[N];

bool cmp(T623511 a,T623511 b){
    if(a.year==b.year){
        if(a.month == b.month){
            if(a.day == b.day){
                return a.id>b.id;
            }
            else {
                return a.day<b.day;
            }
        }
        else{
            return a.month<b.month;
        }
    }
    else{
        return a.year<b.year;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>name[i].name>>name[i].year>>name[i].month>>name[i].day;
    for(int i=1;i<=n;i++)name[i].id=i;
    sort(name+1,name+1+n,cmp);
    for(int i=1;i<=n;i++)cout<<name[i].name<<'\n';
}