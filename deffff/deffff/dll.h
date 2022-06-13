#ifndef AXLPLUGIN_H  
#define AXLPLUGIN_H  
/**/  
#ifdef _WINDOWS  
#define DLL_DECLARE __declspec(dllexport)  
#else  
#define DLL_DECLARE  
#endif  
void main();
void ruzhu(zhuk z[N],tuif t[N]);
void tuifang(zhuk z[N],tuif t[N]);
void guanli(zhuk z[N],guan g[N],gaolao u[N],tuif t[N]);
void xianchang(zhuk z[N],tuif t[N]);
void wangluo(zhuk z[N],tuif t[N]);
int duqu(zhuk z[N],tuif t[N]);
int fanghao(zhuk z[N],int x);
int denglu(guan g[N],gaolao u[N],int a);
int gshu(guan g[N]);
int gceng(gaolao u[N]);
void yulan(zhuk z[N],guan g[N],gaolao u[N],tuif t[N]);
void tfpai(zhuk d[N],tuif t[N],int n,int (*compare)(int a,int b));
void fjpai(zhuk d[N],int n,int (*compare)(int a,int b));
int sheng(int a,int b);
int jiang(int a,int b);
void change(int *x,int *y);
void czxin(zhuk z[N],guan g[N],gaolao u[N],tuif t[N]);
void gaoj(zhuk z[N],guan g[N],gaolao u[N],tuif t[N]);
void zgm(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n);
void zgcm(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n);
void jxg(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n);
void jxgc(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n);
void bossq(zhuk z[N],guan g[N],gaolao u[N],tuif t[N]);
void aglx(guan g[N],gaolao u[N],int n);
void agcx(guan g[N],gaolao u[N],int m);
void glcy(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n);
void gccy(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int m);
int tfr(tuif t[N]);
/* 把所有的函数声明都列在这里 */  
#endif  