/*
ID: singh.p2
PROG: beads
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

int sum(void);
char s[351]={0},st[351]={0};
int n=0;
int main(void)
{
    int i=0,j=0,max=-1,t=0;

    freopen("beads.in","rt",stdin);
    scanf("%d",&n);
    scanf("%s",&s);
    fclose(stdin);
    for (i=0;i<=n-1;i++)
    {
        for (j=i+1;j<=n-1;j++) st[j-i-1]=s[j];
        for (j=i;j>=0;j--) st[j+n-i-1]=s[j];
        t=sum();
        if (max<t) max=t;
        t=0;
        memset(st,'\0',sizeof(st));
    }
    if (max==2*n) max=max/2;
    freopen("beads.out","wt",stdout);
    printf("%d\n",max);
    fclose(stdout);
    return 0;
}

int sum(void)
{
    int i=0,k=0;
    char flag={0};
    if (st[0]=='r') flag='r';
    else if (st[0]=='b') flag='b';
    else if (st[0]=='w')
    {
        while (st[i]=='w') i=i+1;
        if (i==n) flag='w';
        else flag=st[i];
    }
    i=0;
    while ((st[i]==flag)||(st[i]=='w')) {k=k+1;st[i]=flag;i=i+1;}
    flag='\0';
    if (st[n-1]=='r') flag='r';
    else if (st[n-1]=='b') flag='b';
    else if (st[n-1]=='w')
    {
        i=n-1;
        while (st[i]=='w') i=i-1;
        if (i==-1) flag='w';
        else flag=st[i];
    }
    i=n-1;
    while ((st[i]==flag)||(st[i]=='w')) {k=k+1;st[i]=flag;i=i-1;}
    return k;
}
