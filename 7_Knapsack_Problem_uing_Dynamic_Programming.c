#include<stdio.h>
#include<stdlib.h>
// capacity is taken as m
int n, m, w[20], V[20][20],p[20];
int max(int a,int b)
{
if(a>b) 
return a;
else 
return b;
}


void Knapsack()
{
int i,j;
for (i=0;i<=n;i++)
{
for (j=0;j<=m;j++)
{
if (i==0||j==0)
{
V[i][j]=0;
}
else if (j < w[i])
{
V[i][j]=V[i-1][j];
}
else
{
V[i][j]=max(V[i-1][j], V[i-1][j-w[i]]+p[i]);
}
printf("%d\t",V[i][j]);
}
printf("\n");
}
}
void PrintSolution()
{
int i,j;
if (V[n][m]==0)
{printf("Not possible!");
return;
}
printf("Maximum Profit is :%d\n",V[n][m]);
i=n;
j=m;
printf("Objects selected: ");
while (i!=0 && j!=0)
{
if (V[i][j]!=V[i-1][j])
{
printf("\n%d",i);
j=j-w[i];
}
i=i-1;
}
printf("\n");
}


int main()
{
int i;
printf("Enter no. of objects:");
scanf("%d",&n);
printf("Enter weight of %d objects:",n);
for (i=1;i<=n;i++)
scanf("%d",&w[i]);
printf("Enter Profits/values:");
for (i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("Enter capacity:");
scanf("%d",&m);
Knapsack();
PrintSolution();
}
