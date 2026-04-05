#include<stdio.h>
#include<string.h>

int main(){
    int n,m;
    long long result=0;
    scanf("%d %d",&n,&m);
    int num[n+1];
    int color[n+1];
    for(int i=1;i<n+1;i++)scanf("%d",&num[i]);
    for(int i=1;i<n+1;i++)scanf("%d",&color[i]);
    long long count[2][m+1];
    long long sum_id[2][m+1];
    long long sum_num[2][m+1];
    long long sum_idxnum[2][m+1];
    memset(count,0,sizeof(count));
    memset(sum_id,0,sizeof(sum_id));
    memset(sum_idxnum,0,sizeof(sum_idxnum));
    memset(sum_num,0,sizeof(sum_num));
    for(int i=1;i<n+1;i++){
        int temp=i%2;
        int c=color[i];
        long long v=num[i];
        result += sum_idxnum[temp][c];
        result += i * sum_num[temp][c];
        result += v * sum_id[temp][c];
        result += i * v * count[temp][c];
        result %= 10007;
        count[temp][c] += 1;
        sum_id[temp][c] += i;
        sum_num[temp][c] += v;
        sum_idxnum[temp][c] += i*v;
    }
    printf("%lld",result%10007);
}
/*
    debug 边界设置为n+1因为第一个数字是从1开始的
    debug 对于公式拆分开来看可以发现维护的量为四个
    debug int 类型数据太大溢出导致会坏了,所以用longlong 去跑
    debug 扫描了数组只可以知道前面的不知道后面的,所以要将i以z的视角去观测
    然后根据改变之后的公式去相加

    tip 运用二位数组来打表记录而不是用if语句将时间压缩进了O(n)
    tip 1LL*()可以利用算数去强制转换为long long 但是直接使用这种类型会更方便
    tip long long 用%lld占位
*/