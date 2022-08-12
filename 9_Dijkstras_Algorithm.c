#include<stdio.h>
#include<stdlib.h>

void dijkstras(int n,int cost[10][10],int sv,int dist[10])
{
int i,v,count=1,visited[10],min;
for (i=1;i<=n;i++){
visited[i]=0;
dist[i]=cost[sv][i];
}
visited[sv]=1;
dist[sv]=0;
while (count<=n){
min=999;
for (i=1;i<=n;i++){
if (visited[i]==0 && dist[i]<min){
min =dist[i];
v=i;
}
}
visited[v]=1;
count++;
for (i=1;i<=n;i++){
if (dist[i] > dist[v] + cost[v][i])
dist[i]=dist[v]+cost[v][i];
}
}
}

int main(){         // weight of an edge if 999 means infinity : vertices are not connected
int n,sv,i,j,dist[10],cost[10][10];
printf("Enter the number of vertices:");
scanf("%d",&n);
printf("Enter the cost of matrix:\n");
for (i=1;i<=n;i++){
for (j=1;j<=n;j++){
scanf("%d",&cost[i][j]);
if (cost[i][j]==0)
cost[i][j]=999;
}
}
printf("Enter the source vertex:");
scanf("%d",&sv);
dijkstras(n,cost,sv,dist);
printf("\nShortest path from %d is\n",sv);
for(i=1;i<=n;i++)
if(i!=sv)
printf("%d -> %d = %d\n",sv,i,dist[i]);
return 0;
}
