#include<stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(){
#ifdef _WIN32
    /* 将控制台输入/输出编码设置为 UTF-8，避免中文乱码 */
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int t;
    double m;
    printf("输入要存的时间:\n");
    if (scanf("%d", &t) != 1) {
        printf("无效的时间输入。\n");
        return 1;
    }
    printf("输入目前的金额：\n");
    if (scanf("%lf", &m) != 1) {
        printf("无效的金额输入。\n");
        return 1;
    }
    if (t <= 0) {
        printf("存期应为正整数。\n");
        return 1;
    }
    double rate = 0.002/7;
    double monthly_add = 300.0;
    int deposit_interval = 30; /* 每30天转入一次 */
    for (int i = 1; i <= t; ++i) {
        /* 如果到了转入日，先转入本金（认为转入当天也能参与当天利息） */
        if (i % deposit_interval == 0) {
            m += monthly_add;
            printf("第%d日转入：%.2lf 元\n", i, monthly_add);
        }
        /* 每日按利率复利 */
        m *= (1.0 + rate);
        printf("第%d日后的金额为：%.2lf\n", i, m);
    }
    printf("净赚：%.2lf", m - (300.0 * ((t / deposit_interval)+1)));
    return 0;
}