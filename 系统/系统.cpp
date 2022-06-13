#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define N 100
/*用户信息*/
typedef struct date1
{int yy;
int mm;
int dd;
}DATE1;
struct zhuk
{char name[20];
char sfz[20];
char xingb[3];
int room;
DATE1 ruz;
}ZHUK;
/*退房记录*/
struct tuif
{int yyy;
int mmm;
int ddd;
int zb;
}TUIF;
/*管理员信息*/
struct guan
{char name[20];
char sfz[20];
char user[20];
char key[20];
}GUAN;
/*高层及老板信息*/
struct gaolao
{char name[20];
char sfz[20];
char guser[20];
char gkey[20];
}GAOLAO;
/*函数声明*/
void ruzhu(zhuk z[N],tuif t[N]);
void tuifang(zhuk z[N],tuif t[N]);
void guanli(zhuk z[N],guan g[N],gaolao u[N],tuif t[N]);
void xianchang(zhuk z[N],tuif t[N]);
void wangluo(zhuk z[N],tuif t[N]);
int duqu(zhuk z[N],tuif t[N]);
int fanghao(zhuk z[N],int x);
int denglu(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int a);
int gshu(guan g[N]);
int gceng(gaolao u[N]);
void yulan(zhuk z[N],guan g[N],gaolao u[N],tuif t[N]);
void tfpai(zhuk d[N],tuif p[N],int n,int (*compare)(int a,int b));
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
void aglx(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n);
void agcx(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int m);
void glcy(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n);
void gccy(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int m);
int tfr(tuif t[N]);
void modeset(int w,int h);
/*房间*/
int ro[6][12]={{20,20,30,30,10,10,10,10,30,30,20,20},{20,20,30,30,10,10,10,10,30,30,20,20},{30,30,10,10,20,20,20,20,10,10,30,30},
{30,30,10,10,20,20,20,20,10,10,30,30},{10,10,20,20,30,30,30,30,20,20,10,10},{10,10,20,20,30,30,30,30,20,20,10,10}};
int guanc[1000]={0};
int gaoc[1000]={0};
int tfs[1000]={0};
int cx=0;
/*主函数*/
FILE *fp,*fw,*fr,*ft;
int m_jdgl()
{int i,x,q,j;cx++;
system("color B0");
struct zhuk z[N];
struct guan g[N];
struct gaolao u[N];
struct tuif t[N];
system("cls");
/*modeset(700,400);*/printf("\n");
for(j=0;j<3;j++)
{printf("\t\t\t\t\t");for(i=0;i<10;i++)   printf("-- ");
printf("酒 店 住 户 信 息 管 理 ");
for(i=0;i<10;i++)   printf(" --");
printf("\n");printf("\n");
}
printf("\n\t\t\t\t\t\t\t\t\t     1.登记入住\n");
printf("\n\t\t\t\t\t\t\t\t\t     2.登记退房\n");
printf("\n\t\t\t\t\t\t\t\t\t     3.管理员\n");
printf("\n\t\t\t\t\t\t\t\t\t     4.返回主页\n");
/*if(cx==1)
	{printf("\n\t\t\t\t\t\t\t\t\t\b\b\b（ 全屏 → Enter → 输入选择后按回车 ）");getch();}*/
ta:fflush(stdin);printf("\n\t\t\t\t\t\t\t\t\t     ");scanf("%d",&x);
if(x==1)  ruzhu(z,t);
else if(x==2) tuifang(z,t);
else if(x==3)  
{q=denglu(z,g,u,t,1);
if(q==1)  guanli(z,g,u,t);
else  if(q==2)
{system("cls");printf("\n\t\t——————————————————— 你 还 有 0 次 输 入 的 机 会 ，失 误 过 多 冻 结 账 号 —————————————————————————————");
printf("\n\n\t\t\t\t\t\t账户已冻结，请找到 更 高 层 的 管 理 者 或者你的 老 板 更改密码！");Sleep(10000);m_jdgl();}
else 
{system("cls");printf("\n\t\t——————————————————— 你 还 有 0 次 输 入 的 机 会 ，失 误 过 多 冻 结 账 号 —————————————————————————————");
printf("\n\n\t\t\t\t\t\t账户已冻结，请找到 同 级 的 高 层 管 理 者 或者你的 老 板 更改密码！");Sleep(10000);m_jdgl();}
}
else if(x==4)  return 1;
else {printf("\n\t\t\t\t\t\t\t\t\t     不要调皮，再给你一次机会：");goto ta;}
return 0;
}
/**//*
void modeset(int w,int h) //屏幕缓冲区和窗口大小 --by:CSDN 
{
	SMALL_RECT rc = {1,1, w, h};//窗口大小 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = {w, h+300};//屏幕缓冲区大小 
	SetConsoleScreenBufferSize(hOut,size);
	SetConsoleWindowInfo(hOut ,1 ,&rc);
	system("cls");
}*/

/*入住*/
void ruzhu(zhuk z[N],tuif t[N])
{int x;
system("cls");
printf("\n\t\t—————————————————————————————— 登 记 入 住 ———————————————————————————————————————");
printf("\n\n\n\t\t\t\t\t\t\t\t\t     1.现场办理\n\n\t\t\t\t\t\t\t\t\t     2.网络已办理\n\n\t\t\t\t\t\t\t\t\t     3.返回\n");
tb: fflush(stdin);printf("\n\t\t\t\t\t\t\t\t\t     ");scanf("%d",&x);
if(x==1)  xianchang(z,t);
else if(x==2) wangluo(z,t);
else if(x==3) {system("cls");m_jdgl();}
else {printf("\n\n\t\t\t\t\t\t\t\t\t不要调皮，再给你一次机会：");goto tb;}
}

void xianchang(zhuk z[N],tuif t[N])
{int n,i,m,x,fa,y;
system("cls");printf("\n");
n=duqu(z,t);
if((fp=fopen("yonghu.txt","a+"))==NULL)     /********************************/
{printf("no\n");exit(0);}
printf("\n\t\t—————————————————————————————— 现 场 办 理 ———————————————————————————————————————");
printf("\n\n\n\t\t\t\t\t\t\t\t\t    几个人入住：");
tjk:scanf("%d",&m);
if(!(m>=1))  {printf("\n\n\t\t\t\t\t\t\t\t\t不要调皮，再给你一次机会：");getchar();goto tjk;}
printf("\n\n\t\t\t\t\t\t\t\t\t     1.单人间\n\n\t\t\t\t\t\t\t\t\t     2.双人间\n\n\t\t\t\t\t\t\t\t\t     3.三人间\n");
tc: fflush(stdin);printf("\n\t\t\t\t\t\t\t\t\t     ");scanf("%d",&x);
if(x!=1&&x!=2&&x!=3)  {printf("\n\n\t\t\t\t\t\t\t\t\t不要调皮，再给你一次机会：");getchar();goto tc;}
system("cls");printf("\n");
fa=fanghao(z,x);

for(i=0;i<m;i++)
{system("cls");printf("\n\t\t—————————————————————————————— 信 息 录 入 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t 第%d位",i+1);
printf("\n\n\t\t\t\t\t\t\t\t\t 姓名：");fflush(stdin);
scanf("%s",z[n+i].name);
printf("\n\t\t\t\t\t\t\t\t\t 性别：");fflush(stdin);
scanf("%s",z[n+i].xingb); 
td:printf("\n\t\t\t\t\t\t\t\t\t 身份证号码(X用大写字母)：");fflush(stdin);
scanf("%s",z[n+i].sfz);
if(strlen(z[n+i].sfz)!=18)  {printf("\n\t\t\t\t\t\t\t\t\t 输入有误，请重新输入\n");goto td;}
kkl:printf("\n\t\t\t\t\t\t\t\t\t 信息是否无误？\n\n\t\t\t\t\t\t\t\t\t 1.姓名有误\t\t2.身份证号码有误\n\n\t\t\t\t\t\t\t\t\t 3.性别有误\t\t4.无误\n");
ppp:fflush(stdin);printf("\n\t\t\t\t\t\t\t\t\t ");scanf("%d",&y);
if(y<=0||y>4) {printf("不要调皮，再给你一次机会：");goto ppp;}
if(y==1)  {printf("\n\n\t\t\t\t\t\t\t\t\t 姓名：");fflush(stdin);scanf("%s",z[n+i].name);}
else if(y==2)  
{tddd:printf("\n\t\t\t\t\t\t\t\t\t 身份证号码(X用大写字母)：");fflush(stdin);scanf("%s",z[n+i].sfz);
if(strlen(z[n+i].sfz)!=18)  {printf("\n\t\t\t\t\t\t\t\t\t 输入有误，请重新输入\n");goto tddd;}
}
else if(y==3)  {printf("\n\t\t\t\t\t\t\t\t\t 性别：");fflush(stdin);scanf("%s",z[n+i].xingb); }
else   goto iiok;
goto kkl;
iiok:fprintf(fp,"%10s\t",z[n+i].name);
fprintf(fp,"%20s\t",z[n+i].sfz);
fprintf(fp,"%2s\t",z[n+i].xingb);
z[n+i].room=fa;fprintf(fp,"%4d\t",z[n+i].room);
tfs[n+i]=1;

printf("\n\t\t\t\t\t\t\t\t\t 入住时间（年月日以.隔开：1991.6.20）：");fflush(stdin);
scanf("%4d.%2d.%2d",&z[n+i].ruz.yy,&z[n+i].ruz.mm,&z[n+i].ruz.dd);
fprintf(fp,"%4d\t%2d\t%2d\n",z[n+i].ruz.yy,z[n+i].ruz.mm,z[n+i].ruz.dd);
}
system("cls");
for(i=3;i>0;i--)
{printf("\n\t\t—————————————————————————————— 信 息 录 入 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t登 记 成 功 ！欢 迎 入 住 ！%d秒后返回主页！",i);Sleep(2000);
}

fclose(fp);

m_jdgl();
}

void wangluo(zhuk z[N],tuif t[N])
{int n,j,x=0;
char a[20];
n=duqu(z,t);
tkk:system("cls");
printf("\n\t\t—————————————————————————————— 网 络 已 办 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t\b\b\b 输入身份证号码(X用大写字母):");
fflush(stdin);gets_s(a);
if(strlen(a)!=18)  
{x++;
if(x==3)  {system("cls");printf("\n\t\t\t\t\t\t\t\t\t\b\b\b 请稍后再输入！\n");Sleep(1000);ruzhu(z,t);}
printf("\n\t\t\t\t\t\t\t\t\t\b\b\b 输入有误，请重新输入\n");Sleep(700);goto tkk;}
for(j=0;j<n;j++)
if(strcmp(z[j].sfz,a)==0&&tfs[j]==1)  
{system("cls");
printf("\n\t\t—————————————————————————————— 网 络 已 办 ———————————————————————————————————————");
if(strcmp(z[j].xingb,"男"))
   {printf("\n\n\t\t\t\t\t\t\t%d 的 %s 先生，欢 迎 入 住 ！",z[j].room,z[j].name);break;}
else  {printf("\n\n\t\t\t\t\t\t\t %d 的 %s 女士，欢 迎 入 住 ！",z[j].room,z[j].name);break;}
}
if(j>=n)  
{system("cls");printf("\n\t\t—————————————————————————————— 网 络 已 办 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t查  无  此  人  ！");
}
printf("\t");
system("pause");
m_jdgl();
}

/*空房查找*/
int fanghao(zhuk z[N],int x)
{int i,fa,j,y,v,a[72],m;
m=0;
printf("\n\t\t—————————————————————————————— 房 号 选 择 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t     房号:  1    2    3    4    5    6    7    8    9   10   11   12\n");

for(i=5;i>=0;i--)
{printf("\n\n\t\t\t\t\t\t     第%d层:",i+1);
for(j=0;j<12;j++)
{if(ro[i][j]-x*10==0) printf("口   ");
else   printf("     ");
}

printf("\n");
}
printf("\n\t\t———————————————————————————————————————————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t     ");
if(x==1) printf("空单人间：\n");
else if(x==2)  printf("空双人间：\n");
else  printf("空三人间：\n");
for(i=5;i>=0;i--)
{printf("\n\t\t\t\t\t\t     第%d层:",i+1);
for(j=0;j<12;j++)
if(ro[i][j]-x*10==0) 
{printf("\t%d\t",(i+1)*100+(j+1));a[m++]=(i+1)*100+(j+1);}
printf("\n");
}
printf("\n\t\t———————————————————————————————————————————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t     是否查看其他房间？\t\t1.是\t\t2.否\t\t3.返回主页面\n");
bhj:fflush(stdin);printf("\n\t\t\t\t\t\t     ");scanf("%d",&y);
if(y==1) 
{printf("\n\t\t\t\t\t\t     1.单人间\n\n\t\t\t\t\t\t     2.双人间\n\n\t\t\t\t\t\t     3.三人间\n");
bhm:fflush(stdin);printf("\n\t\t\t\t\t\t     ");scanf("%d",&v);
if(v<=0||v>3) {printf("\n\n\t\t\t\t\t\t\t\t\t不要调皮，再给你一次机会：");goto bhm;}
system("cls");
fa=fanghao(z,v);
}
else if(y==2)
{printf("\n\t\t\t\t\t\t     输入房间号：");
bvv:scanf("%d",&fa);
for(i=0;i<m;i++)
if(a[i]==fa)
{if(x==1)  ro[fa/100-1][fa%100-1]=11;
if(x==2)  ro[fa/100-1][fa%100-1]=21;
if(x==3)  ro[fa/100-1][fa%100-1]=31;
break;}
if(i>=m)  {printf("\n\n\t\t\t\t\t\t     房间号输入有误，请重新输入：");goto bvv;}
}
else if(y==3) m_jdgl();
else   {printf("\n\n\t\t\t\t\t\t\t\t\t不要调皮，再给你一次机会：");getchar();goto bhj;}
return fa;
}
/*退房*/
void tuifang(zhuk z[N],tuif t[N])
{int n,j,p,f,x=0,m;
char a[20];
f=0;Sleep(200);
n=duqu(z,t);
m=tfr(t);
tff:system("cls");
printf("\n\t\t—————————————————————————————— 登 记 退 房 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t\b\b\b 输入身份证号码(X用大写字母):");
fflush(stdin);scanf("%s",a);
if(strlen(a)!=18)  
{x++;if(x==3) {system("cls");printf("\n\t\t\t\t\t\t\t\t\t\b\b\b 请稍后再输入！");Sleep(1000);m_jdgl();}
printf("\n\t\t\t\t\t\t\t\t\t\b\b\b 输入有误，请重新输入\n");Sleep(700);goto tff;}
for(j=0;j<n;j++)
{if(strcmp(z[j].sfz,a)==0&&tfs[j]==1)   {f=1;break;}}
if(f==1)
{printf("\n\t\t\t\t\t\t\t\t\t\b\b\b 退房年月日（年月日以.隔开：1991.6.20）："); fflush(stdin);
scanf("%4d.%2d.%2d",&t[m+1].yyy,&t[m+1].mmm,&t[m+1].ddd);
t[m+1].zb=j;
p=z[j].room;
ro[p/100-1][p%100-1]=ro[p/100-1][p%100-1]-1;
tfs[j]=0;
if((ft=fopen("tuifang.txt","a+"))==NULL)           /********************************/
{printf("no\n");exit(0);}
fprintf(ft,"%4d\t%2d\t%2d\t%6d\n",t[m+1].yyy,t[m+1].mmm,t[m+1].ddd,t[m+1].zb);
fclose(ft);

printf("\n\t\t—————————————————————————————— 登 记 退 房 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t退 房 成 功 ！欢 迎 下 次 再 来 ！");
}
else {system("cls");printf("\n\t\t—————————————————————————————— 登 记 退 房 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   查  无  此  人  ！");}
Sleep(1500);
m_jdgl();
}

/*用户读取文件数据,人数,房间*/
int duqu(zhuk z[N],tuif t[N])
{int n,p,m,i;
int static x=0;
if((fp=fopen("yonghu.txt","r"))==NULL)           /********************************/
{printf("no\n");exit(0);}
n=0;
while(!feof(fp))
{fscanf(fp,"%10s\t",z[n].name);
fscanf(fp,"%20s\t",z[n].sfz);
fscanf(fp,"%2s\t",z[n].xingb);
fscanf(fp,"%4d\t",&z[n].room);
fscanf(fp,"%4d\t%2d\t%2d\n",&z[n].ruz.yy,&z[n].ruz.mm,&z[n].ruz.dd);
n++;
}
fclose(fp);
m=tfr(t);
for(i=m;i<n;i++)
{p=z[i].room;
 if(x==0) 
{tfs[i]=1;
if(ro[p/100-1][p%100-1]==10)   ro[p/100-1][p%100-1]=11;
if(ro[p/100-1][p%100-1]==20)   ro[p/100-1][p%100-1]=21;
if(ro[p/100-1][p%100-1]==30)   ro[p/100-1][p%100-1]=31;
}
 else 
 {if(tfs[i]==1)
 {if(ro[p/100-1][p%100-1]==10)   ro[p/100-1][p%100-1]=11;
if(ro[p/100-1][p%100-1]==20)   ro[p/100-1][p%100-1]=21;
if(ro[p/100-1][p%100-1]==30)   ro[p/100-1][p%100-1]=31;}
 }
}
x++;
return n;
}
/*退房数据，人数*/
int tfr(tuif t[N])
{int m,i;
m=0;
if((ft=fopen("tuifang.txt","r"))==NULL)             /********************************/
{printf("no\n");exit(0);}
while(!feof(ft))
{fscanf(ft,"%4d\t",&t[m].yyy);
fscanf(ft,"%2d\t",&t[m].mmm);
fscanf(ft,"%2d\n",&t[m].ddd);
fscanf(ft,"%6d\n",&t[m].zb);
m++;
}
fclose(ft);
for(i=0;i<m;i++) 
tfs[i]=0;
return m;
}

/*登录*/
int denglu(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int x)
{int i,n,m,j,k,f=0,hj=0,ml=0;
char a[20],b[20];
char f2[8]={"iamboss"};
n=gshu(g);
m=gceng(u);
for(j=5;j>0&&(5-ml)!=0;j--)
{system("cls");
printf("\n\t\t——————————————————— 你 还 有 %d 次 输 入 的 机 会 ，失 误 过 多 冻 结 账 号 —————————————————————————————",5-ml);
printf("\n\n\t\t\t\t\t\t\t\t\t 输入账号：");   fflush(stdin);scanf("%s",a);
printf("\n\t\t\t\t\t\t\t\t\t 输入密码：");   fflush(stdin);scanf("%s",b);
if(x==1)
{for(i=0;i<n;i++)
  if(strcmp(g[i].user,a)==0)
   {if(gaoc[i]==5)  goto mk;
    if(strcmp(g[i].key,b)==0)     {guanc[i]=0;return 1;}
	else    {guanc[i]=guanc[i]+1;ml=guanc[i];goto yk;}
   }
for(k=0;k<m;k++)
  if(strcmp(u[k].guser,a)==0)
   {if(hj==5)   
  {printf("\n\t\t——————————————————— 你 还 有 %d 次 输 入 的 机 会 ，失 误 过 多 冻 结 账 号 —————————————————————————————",5-ml);
   system("cls");printf("\n\n\t\t\t\t\t\t\t\t\t 请稍后再输入！");Sleep(2000);m_jdgl();}
    if(gaoc[k]==5)  goto vk;
    if(strcmp(u[k].gkey,b)==0)     {guanc[k]=0;return 1;}
	else    
	{if(strcmp(u[k].guser,f2)==0)    {hj++;ml=hj;f=1;goto yh;}
	 gaoc[k]=gaoc[k]+1;ml=gaoc[k];goto yk;
	 }
   }
if(i>=n||k>=m)   
  if(i>=n)  {printf("\n\n\t\t\t\t\t\t\t\t    别做梦了，你还不是管理员~");Sleep(2000);m_jdgl();}
  else {printf("\n\n\t\t\t\t\t\t\t\t    别做梦了，你还不是高层管理员~");Sleep(2000);m_jdgl();}
}
else
{for(k=0;k<m;k++)
  if(strcmp(u[k].guser,a)==0)
   {if(hj==5)   
  {system("cls");printf("\n\t\t——————————————————— 你 还 有 %d 次 输 入 的 机 会 ，失 误 过 多 冻 结 账 号 —————————————————————————————",5-hj);
printf("\n\n\t\t\t\t\t\t\t\t\t 请稍后再输入！");Sleep(2000);m_jdgl();}
    if(gaoc[k]==5)  goto vk;
    if(strcmp(u[k].gkey,b)==0)     {guanc[k]=0;return 1;}
	else  
	{if(strcmp(u[k].guser,f2)==0)    {hj++;ml=hj;f=1;goto yh;}
	 gaoc[k]=gaoc[k]+1;ml=gaoc[k];goto yk;
	 }
   }
if(k>=m)  {printf("\n\n\t\t\t\t\t\t\t\t    别做梦了，你还不是高层管理员~");Sleep(2000);guanli(z,g,u,t);}
}
yk:if(i<n||k<m)
{printf("\n\n\t\t\t\t\t\t\t\t    账号或密码有误，请重新输入！");Sleep(2000);system("cls");}
yh:if(f==1)
{f=0;printf("\n\n\t\t\t\t\t\t\t\t    账号或密码有误，请重新输入！");Sleep(2000);system("cls");}
}
if(strcmp(u[k].guser,f2)==0)
   if(hj==5)   
   {system("cls");printf("\n\t\t——————————————————— 你 还 有 %d 次 输 入 的 机 会 ，失 误 过 多 冻 结 账 号 —————————————————————————————",5-hj);
printf("\n\n\t\t\t\t\t\t\t\t\t 请稍后再输入！");Sleep(2000);m_jdgl();}
mk:return 2;
vk:return 3;
}
/*管理员数据*/
int gshu(guan g[N])
{int i,n;
if((fw=fopen("guan.txt","r"))==NULL)             /********************************/
{printf("no\n");exit(0);}
i=0;
while(!feof(fw))
{fscanf(fw,"%10s\t",g[i].name);
fscanf(fw,"%20s\t",g[i].sfz);
fscanf(fw,"%20s\t",g[i].user);
fscanf(fw,"%20s\n",g[i].key);
i++;
}
n=i;
fclose(fw);
return n;
}
/*高层管理员数据*/
int gceng(gaolao u[N])
{int i,n;
if((fr=fopen("gaoji.txt","r"))==NULL)            /********************************/
{printf("no\n");exit(0);}
i=0;
while(!feof(fr))
{fscanf(fr,"%10s\t",u[i].name);
fscanf(fr,"%20s\t",u[i].sfz);
fscanf(fr,"%20s\t",u[i].guser);
fscanf(fr,"%20s\n",u[i].gkey);
i++;
}
n=i;
fclose(fr);
return n;
}


/*管理员板块*/
void guanli(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int x,q,y,k,jk,bn,m=0;
char b[20],a[20],f[20];
char f2[6]={"bxxzj"};
bn=gceng(u);
system("cls");
printf("\n\t\t——————————————————————————————— 管 理 员 ————————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.所有顾客信息预览\n\n\t\t\t\t\t\t\t\t\t   2.查找顾客信息\n\n\t\t\t\t\t\t\t\t\t   3.高层管理员\n\n\t\t\t\t\t\t\t\t\t   4.BOSS权限\n\n\t\t\t\t\t\t\t\t\t   5.返回\n");
te: fflush(stdin);printf("\n\t\t\t\t\t\t\t\t\t   ");scanf("%d",&x);
if(x==1)  yulan(z,g,u,t);
else if(x==2)  czxin(z,g,u,t);
else if(x==3)  
{q=denglu(z,g,u,t,2);
if(q==1)  gaoj(z,g,u,t);
else 
{system("cls");
printf("\n\t\t——————————————————— 你 还 有 0 次 输 入 的 机 会 ，失 误 过 多 冻 结 账 号 —————————————————————————————");
printf("\n\n\t\t\t\t\t\t账户已冻结，请找到 同 级 的 高 层 管 理 者 或者你的 老 板 更改密码！");Sleep(10000);guanli(z,g,u,t);}
}	
else if(x==4)  
{opp:system("cls");printf("\n\t\t—————————————————————————————— BOSS  专 区 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t输入BOSS专用账号：");   fflush(stdin);scanf("%s",a);
printf("\n\t\t\t\t\t\t\t\t\t输入BOSS专用密码：");   fflush(stdin);scanf("%s",b);
if(strcmp(a,u[0].guser)==0&&strcmp(b,u[0].gkey)==0)  bossq(z,g,u,t);
else 
{m++;
if(m==3)  
{system("cls");
printf("\n\t\t—————————————————————————————— BOSS  验 证 ———————————————————————————————————————");

printf("\n\n\t\t\t\t\t\t\t\t\t你是BOSS吗？\t\t1.是的\t\t2.不是\n");

gbh:printf("\n\t\t\t\t\t\t\t\t\t");scanf("%d",&y);fflush(stdin);
if(y<=0||y>2) {printf("\n\n\t\t\t\t\t\t\t\t\t不要调皮，再给你一次机会：");goto gbh;}
else  
{system("cls");printf("\n\t\t—————————————————————————————— BOSS  验 证 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t你是BOSS吗？\t\t1.是的\t\t2.不是\n");}
if(y==1)
{printf("\n\n\t\t\t\t\t\t\t\t\tBOSS的身上的存款是多少？（写具体金额）\n\n\t\t\t\t\t\t\t\t\t回答：");
scanf("%d",&k);
if(k!=0)  {system("cls");printf("\n\t\t—————————————————————————————— BOSS  验 证 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t      回答错误！");Sleep(1500);guanli(z,g,u,t);}
   else
   {printf("\n\n\t\t\t\t\t\t\t\t\tBOSS办公室保险箱密码？\n\n\t\t\t\t\t\t\t\t\t回答：");
    scanf("%s",f);
    if(strcmp(f,f2))  {system("cls");printf("\n\t\t—————————————————————————————— BOSS  验 证 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t      回答错误！");Sleep(1500);guanli(z,g,u,t);}
	else
       {printf("\n\n\t\t\t\t\t\t\t\t\tBOSS最喜欢的数字是多少？\n\n\t\t\t\t\t\t\t\t\t回答：");
        scanf("%d",&jk);
        if(jk!=1006)  {system("cls");printf("\n\t\t—————————————————————————————— BOSS  验 证 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t      回答错误！");Sleep(1500);guanli(z,g,u,t);}
		else  bossq(z,g,u,t);
        } 
   }
}
else if(y==2)  guanli(z,g,u,t);
else {printf("\n\n\t\t\t\t\t\t\t\t\t不要调皮，再给你一次机会：");goto gbh;}
}
printf("\n\n\t\t\t\t\t\t\t\t\t账号或密码有误，请重新输入！");Sleep(1500);goto opp;
}
}
else if(x==5)  m_jdgl();
else {printf("\n\n\t\t\t\t\t\t\t\t\t不要调皮，再给你一次机会：");goto te;}
}

/*所有顾客信息预览，排序*/
void yulan(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int i,n,x,j,m,k,cv,bu[N];
struct zhuk d[N],f[N];
struct tuif p[N];
system("cls");
n=duqu(z,t);
m=tfr(t);
for(i=0;i<n;i++) bu[i]=1;
printf("\n\t\t————————————————————————————  顾 客 信 息 预 览  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t     1.按入住时间升序\t\t\t\t2.按入住时间降序\n\n\t\t\t\t\t\t     3.按退房时间升序\t\t\t\t4.按退房时间降序\n\n\t\t\t\t\t\t     5.按房号升序\t\t\t\t6.按房号降序\n\n\t\t\t\t\t\t     7.返回\t\t\t\t\t8.返回主页面\n");
th: fflush(stdin);printf("\n\n\t\t\t\t\t\t     ");scanf("%d",&x);
if(x<=0||x>8) {printf("\n\n\t\t\t\t\t\t     不要调皮，再给你一次机会：");getchar();goto th;}
else {system("cls");printf("\n\t\t————————————————————————————  顾 客 信 息 预 览  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t     1.按入住时间升序\t\t\t\t2.按入住时间降序\n\n\t\t\t\t\t\t     3.按退房时间升序\t\t\t\t4.按退房时间降序\n\n\t\t\t\t\t\t     5.按房号升序\t\t\t\t6.按房号降序\n\n\t\t\t\t\t\t     7.返回\t\t\t\t\t8.返回主页面\n");
}
tf:if(x==1)
{for(i=0;i<n;i++)   bu[i]=1;
for(i=0;i<m;i++)   
for(j=0;j<n;j++)
if(t[i].zb==j)
bu[j]=0;

printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t\t\t\t   姓名\t\t     身份证号码        性别\t房间号\t\b入住年\t 月\t日\t\b退房年\t 月\t日\n");
for(i=0;i<n;i++)
{printf("\n\t\t\t\t\t   %-10s\t",z[i].name);printf("%20s\t",z[i].sfz);printf("%2s\t",z[i].xingb);printf("%4d\t",z[i].room);
printf("%4d\t",z[i].ruz.yy);printf("%2d\t",z[i].ruz.mm);printf("%2d\t",z[i].ruz.dd);
if(bu[i]==0)
{for(cv=0;cv<m;cv++)
if(i==t[cv].zb)
{printf("%4d\t",t[cv].yyy);printf("%2d\t",t[cv].mmm);printf("%2d\n",t[cv].ddd);}
}
else  printf("\n");
if((i+1)%10==0)  
{printf("\t\t                                                                                                                                      %d人",i+1);
printf("\n\t\t          ——————————————————————————————————————————————————————————————————\n");
}
}
printf("\t\t                                                                                                                                                %d人",n);
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t共交易：%d人\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   入住时间升序\n\n\t\t交易成功：%d人\n\n\t\t交易中：%d\n\n",n,m,n-m);
}

else if(x==2)
{for(i=0;i<n;i++)   bu[i]=1;
for(i=0;i<m;i++)   
for(j=0;j<n;j++)
if(t[i].zb==j)
bu[j]=0;
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t\t\t\t   姓名\t\t     身份证号码        性别\t房间号\t\b入住年\t 月\t日\t\b退房年\t 月\t日\n");
for(i=n-1;i>=0;i--)
{printf("\n\t\t\t\t\t   %-10s\t",z[i].name);printf("%20s\t",z[i].sfz);printf("%2s\t",z[i].xingb);printf("%4d\t",z[i].room);
printf("%4d\t",z[i].ruz.yy);printf("%2d\t",z[i].ruz.mm);printf("%2d\t",z[i].ruz.dd);
if(bu[i]==0)
{for(cv=0;cv<m;cv++)
if(i==t[cv].zb)
{printf("%4d\t",t[cv].yyy);printf("%2d\t",t[cv].mmm);printf("%2d\n",t[cv].ddd);}
}
else  printf("\n");
if((i+1)%10==0)  {printf("\t\t                                                                                                                                      %d人",n-i-1);
printf("\n\t\t          ——————————————————————————————————————————————————————————————————\n");
}}
printf("\t\t                                                                                                                                                %d人",n);
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t共交易：%d人\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   入住时间降序\n\n\t\t交易成功：%d人\n\n\t\t交易中：%d\n\n",n,m,n-m);
}
else if(x==3||x==4)
{k=0;
int mmc=0;
struct zhuk d[N],f[N];
struct tuif p[N];
m=tfr(t);
for(i=0;i<n;i++)   bu[i]=1;
for(j=0;j<m;j++)   p[j]=t[j];
for(j=0;j<m;j++)    
for(i=0;i<n;i++)   
if(t[j].zb==i)    {d[j]=z[i];p[j].zb=j;bu[i]=0;break;}
for(i=0;i<n;i++)   if(bu[i]==1)    f[k++]=z[i];
if(x==3)   tfpai(d,p,m,sheng);
else tfpai(d,p,m,jiang);	
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t\t\t\t   姓名\t\t     身份证号码        性别\t房间号\t\b入住年\t 月\t日\t\b退房年\t 月\t日\n");

for(i=0;i<m;i++)
{printf("\n\t\t\t\t\t   %-10s\t",d[i].name);printf("%20s\t",d[i].sfz);printf("%2s\t",d[i].xingb);printf("%4d\t",d[i].room);
printf("%4d\t",d[i].ruz.yy);printf("%2d\t",d[i].ruz.mm);printf("%2d\t",d[i].ruz.dd);
printf("%4d\t",p[i].yyy);printf("%2d\t",p[i].mmm);printf("%2d\n",p[i].ddd);
if((i+1)%10==0)  {printf("\t\t                                                                                                                                      %d人",i+1);
printf("\n\t\t          ——————————————————————————————————————————————————————————————————\n");
}}
for(i=0;i<k;i++) 
{printf("\n\t\t\t\t\t   %-10s\t",f[i].name);printf("%20s\t",f[i].sfz);printf("%2s\t",f[i].xingb);printf("%4d\t",f[i].room);
printf("%4d\t",f[i].ruz.yy);printf("%2d\t",f[i].ruz.mm);printf("%2d\n",f[i].ruz.dd);
if((m+i+1)%10==0)  {printf("\t\t                                                                                                                                      %d人",m+i+1);
printf("\n\t\t          ——————————————————————————————————————————————————————————————————\n");
}}
printf("\t\t                                                                                                                                                %d人",n);
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
if(x==3) printf("\n\t\t共交易：%d人\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   退房时间升序\n\n\t\t交易成功：%d人\n\n\t\t交易中：%d\n\n",n,m,n-m);
else printf("\n\t\t共交易：%d人\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   退房时间降序\n\n\t\t交易成功：%d人\n\n\t\t交易中：%d\n\n",n,m,n-m);

}

else if(x==5||x==6)
{int a,b,j,mmc;
if(x==5) 
{mmc=0;
for(i=0;i<n;i++)   bu[i]=1;
for(i=0;i<m;i++)   
for(j=0;j<n;j++)
if(t[i].zb==j)
bu[j]=0;
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t\t\t\t   姓名\t\t     身份证号码        性别\t房间号\t\b入住年\t 月\t日\t\b退房年\t 月\t日\n");

  for(a=0;a<6;a++)
    for(b=0;b<12;b++)
      for(j=0;j<n;j++)
	   if(((a+1)*100+b+1)==z[j].room)
      {printf("\n\t\t\t\t\t   %-10s\t",z[j].name);printf("%20s\t",z[j].sfz);printf("%2s\t",z[j].xingb);printf("%4d\t",z[j].room);
       printf("%4d\t",z[j].ruz.yy);printf("%2d\t",z[j].ruz.mm);printf("%2d\t",z[j].ruz.dd);
         if(bu[j]==0)
            {for(cv=0;cv<m;cv++)
             if(j==t[cv].zb)
             {printf("%4d\t",t[cv].yyy);printf("%2d\t",t[cv].mmm);printf("%2d\n",t[cv].ddd);}
             }
         else  printf("\n"); mmc++;
		 if((mmc+1)%10==0)  {printf("\t\t                                                                                                                                      %d人",mmc+1);
printf("\n\t\t          ——————————————————————————————————————————————————————————————————\n");
}      }
printf("\t\t                                                                                                                                                %d人",n);
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t共交易：%d人\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       房号升序\n\n\t\t交易成功：%d人\n\n\t\t交易中：%d\n\n",n,m,n-m);
}
else
{mmc=0;
for(i=0;i<n;i++)   bu[i]=1;
for(i=0;i<m;i++)   
for(j=0;j<n;j++)
if(t[i].zb==j)
bu[j]=0;
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t\t\t\t   姓名\t\t     身份证号码        性别\t房间号\t\b入住年\t 月\t日\t\b退房年\t 月\t日\n");

  for(a=5;a>=0;a--)
    for(b=11;b>=0;b--)
	for(j=0;j<n;j++)
      if(((a+1)*100+b+1)==z[j].room)
      {printf("\n\t\t\t\t\t   %-10s\t",z[j].name);printf("%20s\t",z[j].sfz);printf("%2s\t",z[j].xingb);printf("%4d\t",z[j].room);
       printf("%4d\t",z[j].ruz.yy);printf("%2d\t",z[j].ruz.mm);printf("%2d\t",z[j].ruz.dd);
         if(bu[j]==0)
            {for(cv=0;cv<m;cv++)
             if(j==t[cv].zb)
             {printf("%4d\t",t[cv].yyy);printf("%2d\t",t[cv].mmm);printf("%2d\n",t[cv].ddd);}
             }
         else  printf("\n"); mmc++;
		 if((mmc+1)%10==0)  {printf("\t\t                                                                                                                                      %d人",mmc+1);
printf("\n\t\t          ——————————————————————————————————————————————————————————————————");
}      }
printf("\t\t                                                                                                                                                %d人",n);
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t共交易：%d人\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       房号降序\n\n\t\t交易成功：%d人\n\n\t\t交易中：%d\n\n",n,m,n-m);
}
}
else if(x==7)  guanli(z,g,u,t);
else if(x==8)  m_jdgl();
else {printf("\n\t\t不要调皮，再给你一次机会：");Sleep(700);system("cls");goto th;}
top:fflush(stdin);printf("\n\t\t");scanf("%d",&x);
if(x<=0||x>8) {printf("\n\t\t不要调皮，再给你一次机会：");goto top;}
if(x==7)  guanli(z,g,u,t);
else if(x==8)  m_jdgl();
else  {system("cls");printf("\n\t\t————————————————————————————  顾 客 信 息 预 览  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t     1.按入住时间升序\t\t\t\t2.按入住时间降序\n\n\t\t\t\t\t\t     3.按退房时间升序\t\t\t\t4.按退房时间降序\n\n\t\t\t\t\t\t     5.按房号升序\t\t\t\t6.按房号降序\n\n\t\t\t\t\t\t     7.返回\t\t\t\t\t8.返回主页面\n"); goto tf;}

}
/*退房排序*/
void tfpai(zhuk d[N],tuif p[N],int n,int (*compare)(int a,int b))
{int i,j,x,y;
struct zhuk o[N];
struct tuif k[N];
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{x=p[i].yyy*10000+p[i].mmm*100+p[i].ddd;
y=p[j].yyy*10000+p[j].mmm*100+p[j].ddd;
if((*compare)(x,y)) {k[i]=p[i];p[i]=p[j];p[j]=k[i];o[i]=d[i];d[i]=d[j];d[j]=o[i];}
}
}

int sheng(int a,int b)
{return a>b;}

int jiang(int a,int b)
{return a<b;}

void change(int *x,int *y)
{int t;t=*x;*x=*y;*y=t;}

/*调出顾客信息*/
void czxin(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int n,x,i,m,f,mmc,ttc;
char a[30];
system("cls");
n=duqu(z,t);
printf("\n\t\t————————————————————————————  查 找 顾 客 信 息  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.身份证查找\n\n\t\t\t\t\t\t\t\t\t   2.姓名查找\n\n\t\t\t\t\t\t\t\t\t   3.返回\n\n\t\t\t\t\t\t\t\t\t   4.返回主页面\n");
printf("\n\t\t\t\t\t\t\t\t\t   ");tgcc:scanf("%d",&x);fflush(stdin);
if(x<=0||x>4) {printf("\n\t\t\t\t\t\t\t\t\t   不要调皮，再给你一次机会：");goto tgcc;}
else   {system("cls");printf("\n\t\t————————————————————————————  查 找 顾 客 信 息  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.身份证查找\n\n\t\t\t\t\t\t\t\t\t   2.姓名查找\n\n\t\t\t\t\t\t\t\t\t   3.返回\n\n\t\t\t\t\t\t\t\t\t   4.返回主页面\n");}
tj:m=0;f=0;mmc=0;
if(x==1)      {printf("\n\t\t\t\t\t\t\t\t   输入需要查找顾客的身份证(X用大写字母)："); fflush(stdin);gets_s(a);}
else if(x==2) {printf("\n\n\t\t\t\t\t\t\t\t        输入需要查找顾客的姓名："); fflush(stdin);gets_s(a);}
else if(x==3)  guanli(z,g,u,t);
else if(x==4)  m_jdgl();
else {printf("\n\t\t\t\t\t\t\t\t\t   不要调皮，再给你一次机会：");goto tgcc;}
for(i=0;i<n;i++)
if((x==1&&strcmp(z[i].sfz,a)==0)||(x==2&&strcmp(z[i].name,a)==0)) f++;
if(f==0)
{if(x==1) {system("cls");printf("\n\t\t————————————————————————————  查 找 顾 客 信 息  —————————————————————————————————————");
if(strlen(a)!=18) {printf("\n\n\t\t\t\t\t\t\t\t\t   身份证输入有误！");Sleep(2000);czxin(z,g,u,t);}
else {printf("\n\n\t\t\t\t\t\t\t\t\t      查无此人！");Sleep(2000);czxin(z,g,u,t);}
}
if(x==2) {system("cls"); printf("\n\t\t————————————————————————————  查 找 顾 客 信 息  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t      查无此人！");Sleep(2000);czxin(z,g,u,t);}
}
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t\t\t\t   姓名\t\t     身份证号码        性别\t房间号\t\b入住年\t 月\t日\t\b退房年\t 月\t日\n");
for(i=0;i<n;i++)
{
if((x==1&&strcmp(z[i].sfz,a)==0)||(x==2&&strcmp(z[i].name,a)==0))
{printf("\n\t\t\t\t\t   %-10s\t",z[i].name);printf("%20s\t",z[i].sfz);printf("%2s\t",z[i].xingb);printf("%4d\t",z[i].room);
printf("%4d\t",z[i].ruz.yy);printf("%2d\t",z[i].ruz.mm);printf("%2d\t",z[i].ruz.dd);
if(tfs[i]==0)
{printf("%4d\t",t[i].yyy);printf("%2d\t",t[i].mmm);printf("%2d\n",t[i].ddd);}
else  printf("\n");
mmc=m+1;m++;ttc=1;
}
else ttc=0;
if(m%10==0&&ttc==1)  
{printf("\t\t                                                                                                                                      %d人",m);
printf("\n\t\t          ——————————————————————————————————————————————————————————————————\n");
}
}printf("\t\t                                                                                                                                                %d人",m);
printf("\n\t\t————————————————————————————————————————————————————————————————————————————\n");
if(x==1)  printf("\n\t\t共：%d个人\n",m);
else  printf("\n\t\t共：%d次\n",m);
vbn:printf("\n\n\t\t\t\t\t\t\t\t\t   ");scanf("%d",&x);fflush(stdin);
if(x<=0||x>4) {printf("\n\t\t\t\t\t\t\t\t\t   不要调皮，再给你一次机会：");goto vbn;}
if(x==3)  guanli(z,g,u,t);
else if(x==4)  m_jdgl();
else  {system("cls");printf("\n\t\t————————————————————————————  查 找 顾 客 信 息  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.身份证查找\n\n\t\t\t\t\t\t\t\t\t   2.姓名查找\n\n\t\t\t\t\t\t\t\t\t   3.返回\n\n\t\t\t\t\t\t\t\t\t   4.返回主页面\n");goto tj;}
}

/*高级管理员密码管理*/
void gaoj(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int x,n,m;
system("cls");
n=gshu(g);
m=gceng(u);
printf("\n\t\t—————————————————————————————  高 层 管 理 员  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.找回管理员密码\n\n\t\t\t\t\t\t\t\t\t   2.找回高层管理员密码\n\n\t\t\t\t\t\t\t\t\t   3.加入新的管理员\n\n\t\t\t\t\t\t\t\t\t   4.加入新的高层管理\n\n\t\t\t\t\t\t\t\t\t   5.返回\n\n\t\t\t\t\t\t\t\t\t   6.返回主页面\n");
ty: fflush(stdin);printf("\n\n\t\t\t\t\t\t\t\t\t   ");tyy:scanf("%d",&x);
if(x<=0||x>6) {printf("\n\n\t\t\t\t\t\t\t\t\t   不要调皮，再给你一次机会：");goto tyy;}
else   {system("cls");printf("\n\t\t—————————————————————————————  高 层 管 理 员  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.找回管理员密码\n\n\t\t\t\t\t\t\t\t\t   2.找回高层管理员密码\n\n\t\t\t\t\t\t\t\t\t   3.加入新的管理员\n\n\t\t\t\t\t\t\t\t\t   4.加入新的高层管理\n\n\t\t\t\t\t\t\t\t\t   5.返回\n\n\t\t\t\t\t\t\t\t\t   6.返回主页面\n");}
tz:if(x==1)  zgm(z,g,u,t,n);
else if(x==2) zgcm(z,g,u,t,m);
else if(x==3)  jxg(z,g,u,t,n);
else if(x==4)  jxgc(z,g,u,t,m);
else if(x==5)  guanli(z,g,u,t);
else if(x==6)  m_jdgl();
else {printf("\n\n\t\t\t\t\t\t\t\t\t   不要调皮，再给你一次机会：");goto tyy;}
fflush(stdin);printf("\n\n\t\t\t\t\t\t\t\t\t   ");scanf("%d",&x);scanf("%d",&x);
if(x==5)  guanli(z,g,u,t);
else if(x==6)  m_jdgl();
else  {system("cls");printf("\n\t\t—————————————————————————————  高 层 管 理 员  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.找回管理员密码\n\n\t\t\t\t\t\t\t\t\t   2.找回高层管理员密码\n\n\t\t\t\t\t\t\t\t\t   3.加入新的管理员\n\n\t\t\t\t\t\t\t\t\t   4.加入新的高层管理\n\n\t\t\t\t\t\t\t\t\t   5.返回\n\n\t\t\t\t\t\t\t\t\t   6.返回主页面\n");goto tz;}
}

/*找回管理员密码*/
void zgm(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i,k=0;
char a[30];
if((fw=fopen("guan.txt","r"))==NULL)    /********************************/
{printf("no\n");exit(0);}
system("cls");
printf("\n\t\t————————————————————————————  管 理 员 密 码 找 回  ————————————————————————————————————");
kvs:printf("\n\n\t\t\t\t\t\t\t\t\t 输入管理员账号：");
fflush(stdin);scanf("%s",a);
for(i=0;i<n;i++)
if(strcmp(g[i].user,a)==0)  
{printf("\n\t\t\t\t\t\t\t\t\t 丢失的密码：%s\n\n\t\t\t\t\t\t\t\t\t 按任意键返回...",g[i].key);guanc[i]=0;getch();break;}
if(i==n) 
{k++;
if(k==3) {printf("\n\n\t\t\t\t\t\t\t\t\t      请稍后再输入！");Sleep(2000);gaoj(z,g,u,t);}
printf("\n\t\t\t\t\t\t\t\t\t 账号输入有误！请重新输入！");Sleep(2000);system("cls");
printf("\n\t\t————————————————————————————  管 理 员 密 码 找 回  ————————————————————————————————————");
goto kvs;}
else  gaoj(z,g,u,t);
fclose(fw);
}

/*找回高层管理员密码*/
void zgcm(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i,k=0;
char a[30];
if((fr=fopen("gaoji.txt","r"))==NULL)    /********************************/
{printf("no\n");exit(0);}
system("cls");
printf("\n\t\t———————————————————————————  高 层 管 理 员 密 码 找 回  ———————————————————————————————————");
kts:printf("\n\n\t\t\t\t\t\t\t\t\t\b输入高层管理员账号：");
fflush(stdin);scanf("%s",a);
for(i=0;i<n;i++)
if(strcmp(u[i].guser,a)==0)  
{printf("\n\t\t\t\t\t\t\t\t\t 丢失的密码：%s\n\n\t\t\t\t\t\t\t\t\t 按任意键返回...",u[i].gkey);gaoc[i]=0;getch();break;}
if(i==n) 
{k++;
if(k==3) {printf("\n\n\t\t\t\t\t\t\t\t\t      请稍后再输入！");Sleep(2000);gaoj(z,g,u,t);}
printf("\n\t\t\t\t\t\t\t\t\t 账号输入有误！请重新输入！");Sleep(2000);system("cls");
printf("\n\t\t———————————————————————————  高 层 管 理 员 密 码 找 回  ———————————————————————————————————");
goto kts;}
else gaoj(z,g,u,t);
fclose(fr);
}

/*加入新管理员*/
void jxg(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i,x=0;
char a[30];
if((fw=fopen("guan.txt","a+"))==NULL)    /********************************/
{printf("no\n");exit(0);}
system("cls");
for(i=0;i<1;i++)
{printf("\n\t\t————————————————————————————   新 管 理 信 息 录 入   ————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t\b姓名："); fflush(stdin);
scanf("%s",g[n+i].name);
tgg:printf("\n\t\t\t\t\t\t\t\t\t\b身份证(X用大写字母)："); fflush(stdin);
scanf("%s",a);
if(strlen(a)!=18)    
{x++;
if(x==3) {system("cls");printf("\n\t\t————————————————————————————   新 管 理 信 息 录 入   ————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t             请稍后再输入！");Sleep(2000);gaoj(z,g,u,t);}
printf("\n\t\t\t\t\t\t\t\t\t\b输入有误，请重新输入\n");Sleep(1000);goto tgg;
}
strcpy(g[n+i].sfz,a);
printf("\n\t\t\t\t\t\t\t\t\t\b输入账号："); fflush(stdin);
scanf("%s",g[n+i].user);
printf("\n\t\t\t\t\t\t\t\t\t\b输入密码："); fflush(stdin);
scanf("%s",g[n+i].key);
fprintf(fw,"%-10s\t",g[n+i].name);
fprintf(fw,"%20s\t",g[n+i].sfz);
fprintf(fw,"%20s\t",g[n+i].user);
fprintf(fw,"%20s\n",g[n+i].key);
}
fclose(fw);
printf("\n\t\t\t\t\t\t\t\t\t   恭喜你，成功加入管理员！");Sleep(5000);
gaoj(z,g,u,t);
}

/*加入新高层管理员*/
void jxgc(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i,x=0;
char a[30];
if((fr=fopen("gaoji.txt","a+"))==NULL)     /********************************/
{printf("no\n");exit(0);}
system("cls");
for(i=0;i<1;i++)
{printf("\n\t\t——————————————————————————— 新 高 层 管  理 信 息 录 入 ————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t\b姓名："); fflush(stdin);
scanf("%s",u[n+i].name);
tpp:printf("\n\t\t\t\t\t\t\t\t\t\b身份证(X用大写字母)："); fflush(stdin);
scanf("%s",a);
if(strlen(a)!=18)    
{x++;
if(x==3) {system("cls");printf("\n\t\t————————————————————————————   新 管 理 信 息 录 入   ————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t             请稍后再输入！");Sleep(2000);gaoj(z,g,u,t);}
printf("\n\t\t\t\t\t\t\t\t\t\b输入有误，请重新输入\n");Sleep(1000);goto tpp;
}
strcpy(u[n+i].sfz,a);
printf("\n\t\t\t\t\t\t\t\t\t\b输入账号："); fflush(stdin);
scanf("%s",u[n+i].guser);
printf("\n\t\t\t\t\t\t\t\t\t\b输入密码："); fflush(stdin);
scanf("%s",u[n+i].gkey);
fprintf(fr,"%-10s\t",u[n+i].name);
fprintf(fr,"%20s\t",u[n+i].sfz);
fprintf(fr,"%20s\t",u[n+i].guser);
fprintf(fr,"%20s\n",u[n+i].gkey);
}
fclose(fr);
printf("\n\t\t\t\t\t\t\t\t\t   恭喜你，成功加入高层管理员！");
Sleep(5000);
gaoj(z,g,u,t);
}

/*BOSS权限*/
void bossq(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int n,m,x;
system("cls");
n=gshu(g);
m=gceng(u);
printf("\n\t\t—————————————————————————————— BOSS  专 限 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.所有管理员信息\n\n\t\t\t\t\t\t\t\t\t   2.所有高层管理员信息\n\n\t\t\t\t\t\t\t\t\t   3.管理员裁员\n\n\t\t\t\t\t\t\t\t\t   4.高层管理员裁员\n\n\t\t\t\t\t\t\t\t\t   5.返回\n\n\t\t\t\t\t\t\t\t\t   6.返回主页\n");
fflush(stdin);printf("\n\n\t\t\t\t\t\t\t\t\t   ");mnn: scanf("%d",&x);
if(x<=0||x>6)  {printf("\n\t\t\t\t\t\t\t\t\t   不要调皮，再给你一次机会：");goto mnn;}
else {system("cls");printf("\n\t\t—————————————————————————————— BOSS  专 限 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.所有管理员信息\n\n\t\t\t\t\t\t\t\t\t   2.所有高层管理员信息\n\n\t\t\t\t\t\t\t\t\t   3.管理员裁员\n\n\t\t\t\t\t\t\t\t\t   4.高层管理员裁员\n\n\t\t\t\t\t\t\t\t\t   5.返回\n\n\t\t\t\t\t\t\t\t\t   6.返回主页\n");
}
mkk:if(x==1) aglx(z,g,u,t,n);
else if(x==2) agcx(z,g,u,t,m);
else if(x==3)  glcy(z,g,u,t,n);
else if(x==4)  gccy(z,g,u,t,m);
else if(x==5)  guanli(z,g,u,t);
else if(x==6)  m_jdgl();
else {printf("\n\t\t\t\t\t\t\t\t\t   不要调皮，再给你一次机会：");Sleep(1000);goto mnn;}
fflush(stdin);printf("\n\n\t\t\t\t\t\t\t\t\t   ");bhui:scanf("%d",&x);
if(x<=0||x>6)  {printf("\n\t\t\t\t\t\t\t\t\t   不要调皮，再给你一次机会：");goto bhui;}
if(x==5)  guanli(z,g,u,t);
else if(x==6)  m_jdgl();
else  {system("cls");printf("\n\t\t—————————————————————————————— BOSS  专 限 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t\t\t\t   1.所有管理员信息\n\n\t\t\t\t\t\t\t\t\t   2.所有高层管理员信息\n\n\t\t\t\t\t\t\t\t\t   3.管理员裁员\n\n\t\t\t\t\t\t\t\t\t   4.高层管理员裁员\n\n\t\t\t\t\t\t\t\t\t   5.返回\n\n\t\t\t\t\t\t\t\t\t   6.返回主页\n");
goto mkk;}
}

/*所有管理员信息*/
void aglx(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i;
system("cls");
printf("\n\t\t—————————————————————————————— 管 理 员 信 息 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t 姓名\t\t\t\b\b身份证号码\t         账号\t\t    密码\n");
for(i=0;i<n;i++)
{printf("\n\t\t\t\t\t\t %-10s\t",g[i].name);
printf("%20s\t",g[i].sfz);
printf("     %-20s\t",g[i].user);
printf("%-20s\n",g[i].key);
}
printf("\n\t\t—————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t共：%d个人\n\t\t按任意键返回... ",n);
getch();bossq(z,g,u,t);
}

/*所有高层管理员信息*/
void agcx(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int m)
{int i;
system("cls");
printf("\n\t\t————————————————————————————  高 层 管 理 员 信 息  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t 姓名\t\t\t\b\b身份证号码\t         账号\t\t    密码\n");
for(i=0;i<m;i++)
{printf("\n\t\t\t\t\t\t %-10s\t",u[i].name);
printf("%20s\t",u[i].sfz);
printf("     %-20s\t",u[i].guser);
printf("%-20s\n",u[i].gkey);
}
printf("\n\t\t—————————————————————————————————————————————————————————————————————————————\n");
printf("\n\t\t共：%d个人\n\t\t按任意键返回... ",m);
getch();bossq(z,g,u,t);
}

/*管理员裁员*/
void glcy(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i,j;
char a[30];
system("cls");
printf("\n\t\t—————————————————————————————— 管 理 员 裁 员 ———————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t     输入所需裁员的个人信息（管理员的姓名、身份证号码、账号）：");
fflush(stdin);scanf("%s",a);
for(i=0;i<n;i++)
if((strcmp(a,g[i].name)==0)||(strcmp(a,g[i].sfz)==0)||(strcmp(a,g[i].user)==0))   break;
if(i>=n)   {printf("\n\n\t\t\t\t\t\t\t\t\t  此人不是管理员！");Sleep(2000);bossq(z,g,u,t);}
else
{for(j=i;j<n-1;j++)  
{guanc[j]=guanc[j+1];
g[j]=g[j+1];
}
guanc[j]=0;
n--;
if((fw=fopen("guan.txt","w"))==NULL)    /********************************/
{printf("no\n");exit(0);}
for(i=0;i<n;i++)
{fprintf(fw,"%-10s\t",g[i].name);
fprintf(fw,"%20s\t",g[i].sfz);
fprintf(fw,"%20s\t",g[i].user);
fprintf(fw,"%20s\n",g[i].key);
}
fclose(fw);
printf("\n\t\t\t\t\t\t\t\t\t       裁员成功！");
Sleep(2000);
bossq(z,g,u,t);
}
}

/*高层管理员裁员*/
void gccy(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int m)
{int i,j;
char a[30];
system("cls");
printf("\n\t\t————————————————————————————  高 层 管 理 员 裁 员  —————————————————————————————————————");
printf("\n\n\t\t\t\t\t\t     输入所需裁员的个人信息（管理员的姓名、身份证号码、账号）：");
fflush(stdin);scanf("%s",a);
for(i=0;i<m;i++)
if((strcmp(a,u[i].name)==0)||(strcmp(a,u[i].sfz)==0)||(strcmp(a,u[i].guser)==0))   break;
if(i>=m)   
{printf("\n\n\t\t\t\t\t\t\t\t\t  此人不是高层管理员！");Sleep(2000);bossq(z,g,u,t);}
else
{for(j=i;j<m-1;j++)  
{gaoc[j]=gaoc[j+1];
u[j]=u[j+1];
}
gaoc[j]=0;
m--;
if((fr=fopen("gaoji.txt","w"))==NULL)     /********************************/
{printf("no\n");exit(0);}
for(i=0;i<m;i++)
{fprintf(fr,"%-10s\t",u[i].name);
fprintf(fr,"%20s\t",u[i].sfz);
fprintf(fr,"%20s\t",u[i].guser);
fprintf(fr,"%20s\n",u[i].gkey);
}
fclose(fr);
printf("\n\t\t\t\t\t\t\t\t\t       裁员成功！");
Sleep(1500);
bossq(z,g,u,t);
}
}
