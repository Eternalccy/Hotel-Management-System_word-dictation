#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"dll.h"
#define N 100
/*�û���Ϣ*/
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
/*�˷���¼*/
struct tuif
{int yyy;
int mmm;
int ddd;
}TUIF;
/*����Ա��Ϣ*/
struct guan
{char name[20];
char sfz[20];
char user[20];
char key[20];
}GUAN;
/*�߲㼰�ϰ���Ϣ*/
struct gaolao
{char name[20];
char sfz[20];
char guser[20];
char gkey[20];
}GAOLAO;
/*��������*/
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
/*����*/
int ro[6][12]={{20,20,30,30,10,10,10,10,30,30,20,20},{20,20,30,30,10,10,10,10,30,30,20,20},{30,30,10,10,20,20,20,20,10,10,30,30},
{30,30,10,10,20,20,20,20,10,10,30,30},{10,10,20,20,30,30,30,30,20,20,10,10},{10,10,20,20,30,30,30,30,20,20,10,10}};
int guanc[1000]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int gaoc[1000]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int tfs[1000]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

/*������*/
FILE *fp,*fw,*fr,*ft;
int main()
{int i,x,q,j;
struct zhuk z[N];
struct guan g[N];
struct gaolao u[N];
struct tuif t[N];
system("cls");
for(j=0;j<3;j++)
{for(i=0;i<10;i++)   printf("-- ");
printf("�� �� ס �� �� Ϣ �� �� ");
for(i=0;i<10;i++)   printf(" --");
printf("\n");
}
printf("\n1.�Ǽ���ס\n2.�Ǽ��˷�\n3.����Ա\n");
ta:scanf("%d",&x);
if(x==1)  ruzhu(z,t);
else if(x==2) tuifang(z,t);
else if(x==3)  
{q=denglu(g,u,1);
if(q==1)  guanli(z,g,u,t);
else 
{system("cls");printf("���������Σ��˻��Ѷ��ᣬ���ҵ����߲�����߻�������ϰ�������룡");Sleep(3000);main();}
}
else {printf("��Ҫ��Ƥ���ٸ���һ�λ��᣺");getchar();goto ta;}
getchar();
}
/*��ס*/
void ruzhu(zhuk z[N],tuif t[N])
{int x;
system("cls");printf("\n");
printf("1.�ֳ�����\n2.�����Ѱ���\n3.����\n");
tb:scanf("%d",&x);
if(x==1)  xianchang(z,t);
else if(x==2) wangluo(z,t);
else if(x==3) {system("cls");main();}
else {printf("��Ҫ��Ƥ���ٸ���һ�λ��᣺");getchar();goto tb;}
}

void xianchang(zhuk z[N],tuif t[N])
{int n,i,m,x,fa;
system("cls");printf("\n");
n=duqu(z,t);
if((fp=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//yonghu.txt","a+"))==NULL)     /********************************/
{printf("no\n");exit(0);}
printf("��������ס��");
scanf("%d",&m);
printf("1.���˼�\n2.˫�˼�\n3.���˼�\n");
tc:scanf("%d",&x);
if(x!=1&&x!=2&&x!=3)  {printf("��Ҫ��Ƥ���ٸ���һ�λ��᣺");getchar();goto tc;}
system("cls");printf("\n");
fa=fanghao(z,x);
for(i=0;i<m;i++)
{system("cls");
printf("��%dλ\n",i+1);
printf("������");
scanf("%s",z[n+i].name);    
printf("�Ա�");
scanf("%s",z[n+i].xingb);    
td:printf("���֤����(X�ô�д��ĸ)��");
scanf("%s",z[n+i].sfz);
if(strlen(z[n+i].sfz)!=18)  {printf("������������������\n");Sleep(500);goto td;}
fprintf(fp,"%6s\t",z[n+i].name);
fprintf(fp,"%20s\t",z[n+i].sfz);
fprintf(fp,"%2s\t",z[n+i].xingb);
z[n+i].room=fa;fprintf(fp,"%4d\t",z[n+i].room);
tfs[n+i]=1;
printf("��סʱ�䣺");
scanf("%d��%d��%d��",&z[i].ruz.yy,&z[i].ruz.mm,&z[i].ruz.dd);
fprintf(fp,"%4d\t%2d\t%2d\n",z[i].ruz.yy,z[i].ruz.mm,z[i].ruz.dd);
tfs[i]=1;
}
system("cls");
printf("�Ǽǳɹ�����ӭ��ס��");
fclose(fp);
Sleep(1500);
main();
}

void wangluo(zhuk z[N],tuif t[N])
{int n,j,x=0;
char a[20];
n=duqu(z,t);
tkk:system("cls");
printf("\n");
printf("�������֤����(X�ô�д��ĸ):");
getchar();
gets(a);
if(strlen(a)!=18)  
{x++;
if(x==3)  {system("cls");printf("���Ժ������룡\n");Sleep(1000);ruzhu(z,t);}
printf("������������������\n");Sleep(700);goto tkk;}
for(j=0;j<n;j++)
if(strcmp(z[j].sfz,a)==0&&tfs[j]==1)  
{system("cls");printf("\n%d��%s����ӭ��ס��",z[j].room,z[j].name);break;}
if(j>=n)  printf("���޴��ˣ�");
Sleep(1500);
main();
}

/*�շ�����*/
int fanghao(zhuk z[N],int x)
{int i,fa,j,y,v;
printf("\n");
printf("����:  1    2    3    4    5    6    7    8    9   10   11   12\n");
for(i=5;i>=0;i--)
{printf("��%d��:",i+1);
for(j=0;j<12;j++)
if(ro[i][j]-x*10==0) printf("��   ");
else   printf("     ");
printf("\n");
}
printf("\n\n");
if(x==1) printf("�յ��˼䣺\n");
else if(x==2)  printf("��˫�˼䣺\n");
else  printf("�����˼䣺\n");
for(i=5;i>=0;i--)
{printf("��%d��:",i+1);
for(j=0;j<12;j++)
if(ro[i][j]-x*10==0) printf("\t%d\t",(i+1)*100+(j+1));
printf("\n");
}
printf("\n�Ƿ�鿴�������䣿\t1.��\t2.��\t3.������ҳ��\n");
scanf("%d",&y);
if(y==1) 
{printf("1.���˼�\n2.˫�˼�\n3.���˼�\n");
scanf("%d",&v);
system("cls");
fa=fanghao(z,v);
}
else if(y==2)
{printf("\n���뷿��ţ�");scanf("%d",&fa);
if(x==1)  ro[fa/100-1][fa%100-1]=11;
if(x==2)  ro[fa/100-1][fa%100-1]=21;
if(x==3)  ro[fa/100-1][fa%100-1]=31;
}
else main();
return fa;
}
/*�˷�*/
void tuifang(zhuk z[N],tuif t[N])
{int n,j,p,f,x=0;;
char a[20];
f=0;
n=duqu(z,t);
tff:system("cls");printf("\n");
printf("�������֤����(X�ô�д��ĸ)��");
scanf("%s",a);
if(strlen(a)!=18)  
{x++;if(x==3) {system("cls");printf("���Ժ������룡");Sleep(1000);main();}
printf("������������������\n");Sleep(700);goto tff;}
for(j=0;j<n;j++)
{if(strcmp(z[j].sfz,a)==0&&tfs[j]==1)   {f=1;break;}}
if(f==1)
{printf("�˷������գ�");
scanf("%d��%d��%d��",&t[j].yyy,&t[j].mmm,&t[j].ddd);
p=z[j].room;
ro[p/100-1][p%100-1]=ro[p/100-1][p%100-1]-1;
tfs[j]=0;
system("cls");
printf("�˷��ɹ�����ӭ�´�������");
}
else printf("���޴��ˣ�");
Sleep(1500);
main();
}

/*�û���ȡ�ļ�����,����,����*/
int duqu(zhuk z[N],tuif t[N])
{int n,p,m,i;
int static x=0;
if((fp=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//yonghu.txt","r"))==NULL)           /********************************/
{printf("no\n");exit(0);}
n=0;
while(!feof(fp))
{fscanf(fp,"%6s\t",z[n].name);
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
/*�˷����ݣ�����*/
int tfr(tuif t[N])
{int m,i;
m=0;
if((ft=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//tuifang.txt","r"))==NULL)             /********************************/
{printf("no\n");exit(0);}
while(!feof(ft))
{fscanf(ft,"%4d\t",&t[m].yyy);
fscanf(ft,"%4d\t",&t[m].mmm);
fscanf(ft,"%2d\n",&t[m].ddd);
m++;
}
fclose(ft);
for(i=0;i<m;i++) 
tfs[i]=0;
return m;
}

/*����Ա��¼*/
int denglu(guan g[N],gaolao u[N],int x)
{int i,n,j,m=0;
char a[20],b[20];
char f2[6]={"bxxzj"};
if(x==1)  n=gshu(g);
else  n=gceng(u);
for(j=5;j>0;j--)
{system("cls");
printf("�������㻹��%d������Ļ��ᣬʧ����ඳ���˺š�����\n",j);
printf("�����˺ţ�");   scanf("%s",a);
printf("�������룺");   scanf("%s",b);
for(i=0;i<n;i++)
{if((strcmp(g[i].user,a)==0)||(strcmp(u[i].guser,a)==0))
   {if((gaoc[i]==5&&x==2)||(guanc[i]==5&&x==1))  goto mk;
    if(m==5)   {system("cls");printf("���Ժ������룡");Sleep(1000);main();}
    if((strcmp(g[i].key,b)==0&&x==1)||(strcmp(u[i].gkey,b)==0&&x==2)) 
      {if(x==1) guanc[i]=0;
	   else  gaoc[i]=0;
	   return 1;
      }
	else  
	    {if((strcmp(g[i].user,f2)==0)||(strcmp(u[i].guser,f2)==0))
		           {m++;printf("�˺Ż������������������룡");Sleep(500);system("cls");break;}
		else
		   if(x==1) {guanc[i]=guanc[i]+1;printf("�˺Ż������������������룡");Sleep(500);system("cls");break;}
		   else {gaoc[i]=gaoc[i]+1;printf("�˺Ż������������������룡");Sleep(500);system("cls");break;}
        }
}}
if(i>=n)   
  if(x==1)  {printf("�������ˣ��㻹���ǹ���Ա~");Sleep(1000);main();}
  else {printf("�������ˣ��㻹���Ǹ߲����Ա~");Sleep(1000);main();} 
}
mk:return 0;
}
/*����Ա����*/
int gshu(guan g[N])
{int i,n;
if((fw=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//guan.txt","r"))==NULL)             /********************************/
{printf("no\n");exit(0);}
i=0;
while(!feof(fw))
{fscanf(fw,"%6s\t",g[i].name);
fscanf(fw,"%20s\t",g[i].sfz);
fscanf(fw,"%20s\t",g[i].user);
fscanf(fw,"%20s\n",g[i].key);
i++;
}
n=i;
fclose(fw);
return n;
}
/*�߲����Ա����*/
int gceng(gaolao u[N])
{int i,n;
if((fr=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//gaoji.txt","r"))==NULL)            /********************************/
{printf("no\n");exit(0);}
i=0;
while(!feof(fr))
{fscanf(fr,"%6s\t",u[i].name);
fscanf(fr,"%20s\t",u[i].sfz);
fscanf(fr,"%20s\t",u[i].guser);
fscanf(fr,"%20s\n",u[i].gkey);
i++;
}
n=i;
fclose(fr);
return n;
}


/*����Ա���*/
void guanli(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int x,q,y,k,jk,bn,m=0;
char b[20],a[20],f[20];
char f2[6]={"bxxzj"};
bn=gceng(u);
system("cls");printf("\n");
printf("1.���й˿���ϢԤ��\n2.���ҹ˿���Ϣ\n3.�߲����Ա\n4.BOSSȨ��\n5.����\n");
te:scanf("%d",&x);
if(x==1)  yulan(z,g,u,t);
else if(x==2)  czxin(z,g,u,t);
else if(x==3)  
{q=denglu(g,u,2);
if(q==1)  gaoj(z,g,u,t);
else 
{system("cls");printf("���������Σ��˻��Ѷ��ᣬ���ҵ�ͬ���ĸ߲�����߻�������ϰ�������룡");Sleep(3000);guanli(z,g,u,t);}
}	
else if(x==4)  
{opp:system("cls");
printf("\n����BOSSר���˺ţ�");   scanf("%s",a);
printf("����BOSSר�����룺");   scanf("%s",b);
if(strcmp(a,u[0].guser)==0&&strcmp(b,u[0].gkey)==0)  bossq(z,g,u,t);
else 
{m++;
if(m==3)  
{system("cls");
printf("����BOSS��\t\t1.�ǵ�\t\t2.����\n");
scanf("%d",&y);
if(y==1)
{printf("BOSS�����ϵĴ���Ƕ��٣���д�����\n�ش�");
scanf("%d",&k);
if(k!=0)  {system("cls");printf("�ش����");Sleep(1500);guanli(z,g,u,t);}
   else
   {printf("BOSS�칫�ұ��������룿\n�ش�");
    scanf("%s",f);
    if(strcmp(f,f2))  {system("cls");printf("�ش����");Sleep(1500);guanli(z,g,u,t);}
	else
       {printf("BOSS��ϲ���������Ƕ��٣�\n�ش�");
        scanf("%d",&jk);
        if(jk!=1006)  {system("cls");printf("�ش����");Sleep(1500);guanli(z,g,u,t);}
		else  bossq(z,g,u,t);
        } 
   }
}
else  guanli(z,g,u,t);
}
printf("�˺Ż������������������룡");Sleep(1500);goto opp;
}
}
else if(x==5)  main();
else {printf("��Ҫ��Ƥ���ٸ���һ�λ��᣺");getchar();goto te;}
}

/*���й˿���ϢԤ��������*/
void yulan(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int i,n,x,j,m,k;
struct zhuk d[N],f[N];
struct tuif p[N];
system("cls");printf("\n");
n=duqu(z,t);
k=0;
m=tfr(t);
if((ft=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//tuifang.txt","r"))==NULL)            /********************************/
{printf("no\n");exit(0);}
for(i=0;i<n;i++)   if(tfs[i]==1)  break;
for(;m<i;m++)
{fscanf(ft,"%4d\t",&t[m].yyy);
fscanf(ft,"%4d\t",&t[m].mmm);
fscanf(ft,"%2d\n",&t[m].ddd);
}
fclose(ft);
for(j=0;j<m;j++)   {d[j]=z[j];p[j]=t[j];}
for(i=m;i<n;i++)
{if(tfs[i]==0)    {d[j++]=z[i];p[j++]=t[i];}
else {f[k]=z[i];k++;}
}
printf("1.����סʱ������\t2.����סʱ�併��\n3.���˷�ʱ������\t4.���˷�ʱ�併��\n5.����������\t\t6.�����Ž���\n7.����\t\t\t8.������ҳ��\n");
th:scanf("%d",&x);
tf:if(x==1)
{printf("��������������������������������������������������������������������������������������������\n");
printf(" ����\t      ���֤����\t\b�Ա�\t�����\t\b��ס��\t ��\t��\t\b�˷���\t ��\t��\n");
for(i=0;i<n;i++)
{printf("%-6s\t",z[i].name);printf("%20s\t",z[i].sfz);printf("%2s\t",z[i].xingb);printf("%4d\t",z[i].room);
printf("%4d\t",z[i].ruz.yy);printf("%2d\t",z[i].ruz.mm);printf("%2d\t",z[i].ruz.dd);
if(tfs[i]==0)
{printf("%4d\t",t[i].yyy);printf("%2d\t",t[i].mmm);printf("%2d\n",t[i].ddd);}
else  printf("\n");
}
printf("��������������������������������������������������������������������������������������������\n");
printf("�����ף�%d��\n���׳ɹ���%d��\n�����У�%d\n",n,m,n-m);
}
else if(x==2)
{printf("��������������������������������������������������������������������������������������������\n");
printf(" ����\t      ���֤����\t\b�Ա�\t�����\t\b��ס��\t ��\t��\t\b�˷���\t ��\t��\n");
for(i=n-1;i>=0;i--)
{printf("%-6s\t",z[i].name);printf("%20s\t",z[i].sfz);printf("%2s\t",z[i].xingb);printf("%4d\t",z[i].room);
printf("%4d\t",z[i].ruz.yy);printf("%2d\t",z[i].ruz.mm);printf("%2d\t",z[i].ruz.dd);
if(tfs[i]==0)
{printf("%4d\t",t[i].yyy);printf("%2d\t",t[i].mmm);printf("%2d\n",t[i].ddd);}
else  printf("\n");
}
printf("��������������������������������������������������������������������������������������������\n");
printf("�����ף�%d��\n���׳ɹ���%d��\n�����У�%d\n",n,m,n-m);
}
else if(x==3||x==4)
{if(x==3)   tfpai(d,p,j,sheng);
else tfpai(d,p,j,jiang);	
printf("��������������������������������������������������������������������������������������������\n");
printf(" ����\t      ���֤����\t\b�Ա�\t�����\t\b��ס��\t ��\t��\t\b�˷���\t ��\t��\n");
for(i=0;i<j;i++)
{printf("%-6s\t",d[i].name);printf("%20s\t",d[i].sfz);printf("%2s\t",d[i].xingb);printf("%4d\t",d[i].room);
printf("%4d\t",d[i].ruz.yy);printf("%2d\t",d[i].ruz.mm);printf("%2d\t",d[i].ruz.dd);
printf("%4d\t",p[i].yyy);printf("%2d\t",p[i].mmm);printf("%2d\n",p[i].ddd);
}
for(i=0;i<k;i++) 
{printf("%-6s\t",f[i].name);printf("%20s\t",f[i].sfz);printf("%2s\t",f[i].xingb);printf("%4d\t",f[i].room);
printf("%4d\t",f[i].ruz.yy);printf("%2d\t",f[i].ruz.mm);printf("%2d\n",f[i].ruz.dd);
}
printf("��������������������������������������������������������������������������������������������\n");
printf("�����ף�%d��\n���׳ɹ���%d��\n�����У�%d\n",n,m,n-m);
}
else if(x==5||x==6)
{for(j=0;j<n;j++)   d[j]=z[j];
if(x==5)   fjpai(d,n,sheng);
else fjpai(d,n,jiang);	
printf("��������������������������������������������������������������������������������������������\n");
printf(" ����\t      ���֤����\t\b�Ա�\t�����\t\b��ס��\t ��\t��\t\b�˷���\t ��\t��\n");
for(i=0;i<n;i++)
{printf("%-6s\t",d[i].name);printf("%20s\t",d[i].sfz);printf("%2s\t",d[i].xingb);printf("%4d\t",d[i].room);
printf("%4d\t",d[i].ruz.yy);printf("%2d\t",d[i].ruz.mm);printf("%2d\t",d[i].ruz.dd);
if(tfs[i]==0)
{printf("%4d\t",t[i].yyy);printf("%2d\t",t[i].mmm);printf("%2d\n",t[i].ddd);}
else  printf("\n");
}
printf("��������������������������������������������������������������������������������������������\n");
printf("�����ף�%d��\n���׳ɹ���%d��\n�����У�%d\n",n,m,n-m);
}
else if(x==7)  guanli(z,g,u,t);
else if(x==8)  main();
else {printf("��Ҫ��Ƥ���ٸ���һ�λ��᣺");Sleep(700);system("cls");goto th;}
scanf("%d",&x);
if(x==7)  guanli(z,g,u,t);
else if(x==8)  main();
else  {system("cls");printf("\n");printf("1.����סʱ������\t2.����סʱ�併��\n3.���˷�ʱ������\t4.���˷�ʱ�併��\n5.����������\t\t6.�����Ž���\n7.����\t\t\t8.������ҳ��\n");getchar();goto tf;}

}
/*�˷�����*/
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

/*��������*/
void fjpai(zhuk d[N],int n,int (*compare)(int a,int b))
{int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{if((*compare)(d[i].room,d[j].room))  change(&d[i].room,&d[j].room);}
}

int sheng(int a,int b)
{return a>b;}

int jiang(int a,int b)
{return a<b;}

void change(int *x,int *y)
{int t;t=*x;*x=*y;*y=t;}

/*�����˿���Ϣ*/
void czxin(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int n,x,i,m,f=0;
char a[30];
system("cls");printf("\n");
n=duqu(z,t);
printf("1.���֤����\n2.��������\n3.����\n4.������ҳ��\n");
tg:scanf("%d",&x);
tj:m=0;
if(x==1)  {printf("������Ҫ���ҹ˿͵����֤(X�ô�д��ĸ)��");getchar();gets(a);}
else if(x==2)  {printf("������Ҫ���ҹ˿͵�������");getchar();gets(a);}
else if(x==3)  guanli(z,g,u,t);
else if(x==4)  main();
else {printf("��Ҫ��Ƥ���ٸ���һ�λ��᣺");Sleep(3000);system("cls");goto tg;}
printf("��������������������������������������������������������������������������������������������\n");
for(i=0;i<n;i++)
{if((x==1&&strcmp(z[i].sfz,a)==0)||(x==2&&strcmp(z[i].name,a)==0))
{printf("%6s\t",z[i].name);printf("%20s\t",z[i].sfz);printf("%2s\t",z[i].xingb);printf("%4d\t",z[i].room);
printf("%4d\t",z[i].ruz.yy);printf("%2d\t",z[i].ruz.mm);printf("%2d\t",z[i].ruz.dd);
if(tfs[i]==0)
{printf("%4d\t",t[i].yyy);printf("%2d\t",t[i].mmm);printf("%2d\n",t[i].ddd);}
else  printf("\n");
m++;}
f=1;
}
printf("��������������������������������������������������������������������������������������������\n");
if(x==1)  printf("����%d����\n",m);
else  printf("����%d��\n",m);
if(!(strcmp(z[i].sfz,a)==0)&&x==1&&f==0) {system("cls");printf("���֤��������");Sleep(1000);czxin(z,g,u,t);}
if(!(strcmp(z[i].name,a)==0)&&x==2&&f==0) {system("cls");printf("���޴��ˣ�");Sleep(1000);czxin(z,g,u,t);}
scanf("%d",&x);
if(x==3)  guanli(z,g,u,t);
else if(x==4)  main();
else  {system("cls");printf("\n");printf("1.���֤����\n2.��������\n3.����\n4.������ҳ��\n");goto tj;}
}

/*�߼�����Ա�������*/
void gaoj(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int x,n,m;
system("cls");printf("\n");
n=gshu(g);
m=gceng(u);
printf("1.�һع���Ա����\t2.�һظ߲����Ա����\n3.�����µĹ���Ա\t4.�����µĸ߲����\n5.����\t\t\t6.������ҳ��\n");
ty:scanf("%d",&x);
tz:if(x==1)  zgm(z,g,u,t,n);
else if(x==2) zgcm(z,g,u,t,m);
else if(x==3)  jxg(z,g,u,t,n);
else if(x==4)  jxgc(z,g,u,t,m);
else if(x==5)  guanli(z,g,u,t);
else if(x==6)  main();
else {printf("��Ҫ��Ƥ���ٸ���һ�λ��᣺");Sleep(3000);system("cls");goto ty;}
scanf("%d",&x);
if(x==5)  guanli(z,g,u,t);
else if(x==6)  main();
else  {system("cls");printf("\n");printf("1.�һع���Ա����\t2.�һظ߲����Ա����\n3.�����µĹ���Ա\t4.�����µĸ߲����\n5.����\t\t\t6.������ҳ��\n");goto tz;}
}

/*�һع���Ա����*/
void zgm(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i;
char a[30];
if((fw=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//guan.txt","r"))==NULL)    /********************************/
{printf("no\n");exit(0);}
ks:printf("�����˺ţ�");
scanf("%s",a);
for(i=0;i<n;i++)
if(strcmp(g[i].user,a)==0)  
{printf("��ʧ�����룺%s\n",g[i].key);guanc[i]=0;getchar();break;}
if(i==n) {printf("�˺������������������룡");Sleep(500);system("cls");goto ks;}
else {Sleep(500);gaoj(z,g,u,t);}
fclose(fw);
}

/*�һظ߲����Ա����*/
void zgcm(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i;
char a[30];
if((fr=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//gaoji.txt","r"))==NULL)    /********************************/
{printf("no\n");exit(0);}
ks:printf("�����˺ţ�");
scanf("%s",a);
for(i=0;i<n;i++)
if(strcmp(u[i].guser,a)==0)  
{printf("��ʧ�����룺%s\n",u[i].gkey);gaoc[i]=0;getchar();break;}
if(i==n) {printf("�˺������������������룡");Sleep(500);system("cls");goto ks;}
else {Sleep(500);gaoj(z,g,u,t);}
fclose(fr);
}

/*�����¹���Ա*/
void jxg(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i,x=0;
char a[30];
if((fw=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//guan.txt","a+"))==NULL)    /********************************/
{printf("no\n");exit(0);}
for(i=0;i<1;i++)
{printf("������");
scanf("%s",g[n+i].name);
tgg:printf("���֤(X�ô�д��ĸ)��");
scanf("%s",a);
if(strlen(a)!=18)    
{x++;
if(x==3) {system("cls");printf("���Ժ������룡");Sleep(1000);gaoj(z,g,u,t);}
printf("������������������\n");Sleep(700);goto tgg;
}
strcpy(g[n+i].sfz,a);
printf("�����˺ţ�");
scanf("%s",g[n+i].user);
printf("�������룺");
scanf("%s",g[n+i].key);
fprintf(fw,"%6s\t",g[n+i].name);
fprintf(fw,"%20s\t",g[n+i].sfz);
fprintf(fw,"%20s\t",g[n+i].user);
fprintf(fw,"%20s\n",g[n+i].key);
}
fclose(fw);
printf("��ϲ�㣬�ɹ��������Ա��");
Sleep(700);
gaoj(z,g,u,t);
}

/*�����¸߲����Ա*/
void jxgc(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i,x=0;
char a[30];
if((fr=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//gaoji.txt","a+"))==NULL)     /********************************/
{printf("no\n");exit(0);}
for(i=0;i<1;i++)
{printf("������");
scanf("%s",u[n+i].name);
tpp:printf("���֤(X�ô�д��ĸ)��");
scanf("%s",a);
if(strlen(a)!=18)    
{x++;
if(x==3) {system("cls");printf("���Ժ������룡");Sleep(1000);gaoj(z,g,u,t);}
printf("������������������\n");Sleep(700);goto tpp;
}
strcpy(u[n+i].sfz,a);
printf("�����˺ţ�");
scanf("%s",u[n+i].guser);
printf("�������룺");
scanf("%s",u[n+i].gkey);
fprintf(fr,"%6s\t",u[n+i].name);
fprintf(fr,"%20s\t",u[n+i].sfz);
fprintf(fr,"%20s\t",u[n+i].guser);
fprintf(fr,"%20s\n",u[n+i].gkey);
}
fclose(fr);
printf("��ϲ�㣬�ɹ�����߲����Ա��");
Sleep(700);
gaoj(z,g,u,t);
}

/*BOSSȨ��*/
void bossq(zhuk z[N],guan g[N],gaolao u[N],tuif t[N])
{int n,m,x;
system("cls");
n=gshu(g);
m=gceng(u);
printf("\n1.���й���Ա��Ϣ\t2.���и߲����Ա��Ϣ\n3.����Ա��Ա\t\t4.�߲����Ա��Ա\n5.����\t\t\t6.������ҳ\n");
mnn:scanf("%d",&x);
mkk:if(x==1) aglx(g,u,n);
else if(x==2) agcx(g,u,m);
else if(x==3)  glcy(z,g,u,t,n);
else if(x==4)  gccy(z,g,u,t,m);
else if(x==5)  guanli(z,g,u,t);
else if(x==6)  main();
else {printf("��Ҫ��Ƥ���ٸ���һ�λ��᣺");Sleep(700);system("cls");goto mnn;}
scanf("%d",&x);
if(x==5)  guanli(z,g,u,t);
else if(x==6)  main();
else  {system("cls");printf("\n1.���й���Ա��Ϣ\t2.���и߲����Ա��Ϣ\n3.����Ա��Ա\t\t4.�߲����Ա��Ա\n5.����\t\t\t6.������ҳ\n");getchar();goto mkk;}
}

/*���й���Ա��Ϣ*/
void aglx(guan g[N],gaolao u[N],int n)
{int i;
printf("����������������������������������������������������������������������������\n");
printf(" ����\t      ���֤����\t   �˺�\t\t           ����\n");
for(i=0;i<n;i++)
{printf("%-6s\t",g[i].name);
printf("%20s\t",g[i].sfz);
printf("%-20s\t",g[i].user);
printf("%-20s\n",g[i].key);
}
printf("����������������������������������������������������������������������������\n");
printf("����%d����\n",n);
}

/*���и߲����Ա��Ϣ*/
void agcx(guan g[N],gaolao u[N],int m)
{int i;
printf("����������������������������������������������������������������������������\n");
printf(" ����\t      ���֤����\t   �˺�\t\t           ����\n");
for(i=0;i<m;i++)
{printf("%-6s\t",u[i].name);
printf("%20s\t",u[i].sfz);
printf("%-20s\t",u[i].guser);
printf("%-20s\n",u[i].gkey);
}
printf("����������������������������������������������������������������������������\n");
printf("����%d����\n",m);
}

/*����Ա��Ա*/
void glcy(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int n)
{int i,j;
char a[30];
system("cls");
printf("\n���������Ա�ĸ�����Ϣ�����������֤���롢�˺ţ���");
scanf("%s",a);
for(i=0;i<n;i++)
if((strcmp(a,g[i].name)==0)||(strcmp(a,g[i].sfz)==0)||(strcmp(a,g[i].user)==0))   break;
if(i>=n)   {system("cls");printf("���˲��ǹ���Ա��");Sleep(1500);bossq(z,g,u,t);}
else
{for(j=i;j<n-1;j++)  
{guanc[j]=guanc[j+1];
g[j]=g[j+1];
}
guanc[j]=0;
n--;
if((fw=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//guan.txt","w"))==NULL)    /********************************/
{printf("no\n");exit(0);}
for(i=0;i<n;i++)
{fprintf(fw,"%6s\t",g[i].name);
fprintf(fw,"%20s\t",g[i].sfz);
fprintf(fw,"%20s\t",g[i].user);
fprintf(fw,"%20s\n",g[i].key);
}
fclose(fw);
printf("��Ա�ɹ���");
Sleep(1500);
bossq(z,g,u,t);
}
}

/*�߲����Ա��Ա*/
void gccy(zhuk z[N],guan g[N],gaolao u[N],tuif t[N],int m)
{int i,j;
char a[30];
system("cls");
printf("\n���������Ա�ĸ�����Ϣ�����������֤���롢�˺ţ���");
scanf("%s",a);
for(i=0;i<m;i++)
if((strcmp(a,u[i].name)==0)||(strcmp(a,u[i].sfz)==0)||(strcmp(a,u[i].guser)==0))   break;
if(i>=m)   {system("cls");printf("���˲��Ǹ߲����Ա��");Sleep(1500);bossq(z,g,u,t);}
else
{for(j=i;j<m-1;j++)  
{gaoc[j]=gaoc[j+1];
u[j]=u[j+1];
}
gaoc[j]=0;
m--;
if((fr=fopen("C://Users//Nitro-cy//Desktop//�Ƶ����ϵͳ - ����//ϵͳ//ϵͳ//gaoji.txt","w"))==NULL)     /********************************/
{printf("no\n");exit(0);}
for(i=0;i<m;i++)
{fprintf(fr,"%6s\t",u[i].name);
fprintf(fr,"%20s\t",u[i].sfz);
fprintf(fr,"%20s\t",u[i].guser);
fprintf(fr,"%20s\n",u[i].gkey);
}
fclose(fr);
printf("��Ա�ɹ���");
Sleep(1500);
bossq(z,g,u,t);
}
}