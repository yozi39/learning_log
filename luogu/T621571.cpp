#include<bits/stdc++.h>
using namespace std;

typedef struct student
{
    int chinese,math,english,total,No;
}student;

int cmp(student a,student b){
    if(a.total!=b.total){
        return a.total>b.total;
    }
    if(a.chinese != b.chinese){
        return a.chinese>b.chinese;
    }
    return a.No<b.No;
}

int main(){
    int n,cnt=1;
    cin>>n;
    student stu[n+1];
    for(int i=1;i<=n;i++){
        cin>>stu[i].chinese>>stu[i].math>>stu[i].english;
        stu[i].total=stu[i].chinese+stu[i].math+stu[i].english;
        stu[i].No=cnt++;
    }
    sort(stu+1,stu+1+n,cmp);
    for(int i=1;i<6;i++){
        cout<<stu[i].No<<' '<<stu[i].total<<'\n';
    }
}
    
