#include<bits/stdc++.h>
using namespace std;

const int N=16;

int n;
double x[N],y[N];
double f[N][1<<N];

double cal(int a,int b){
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    for(int i=0;i<n;i++)
        for(int st=0;st<(1<<n);st++)
            f[i][st]=1e18;

    // 第一块奶酪直接从原点走过去
    for(int i=0;i<n;i++){
        f[i][1<<i]=sqrt(x[i]*x[i]+y[i]*y[i]);
    }

    // st必须放外面
    for(int st=1;st<(1<<n);st++){
        for(int i=0;i<n;i++){
            if(!((st>>i)&1))continue;

            int pre=st^(1<<i);

            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(!((pre>>j)&1))continue;

                f[i][st]=min(f[i][st],f[j][pre]+cal(j,i));
            }
        }
    }

    double ret=1e18;
    for(int i=0;i<n;i++){
        ret=min(ret,f[i][(1<<n)-1]);
    }

    printf("%.2lf",ret);
}

//收获
//memset去初始化double类型会变成一个很小的值
//因为st数组要放的东西越来越多所以应该是一个从小到大的过程
//初始化的状态没有设计完善,没能观察到题目里从原点出发