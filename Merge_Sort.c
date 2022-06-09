/* C program to sort a given set of elements using merge sort method and find the time required to sort elements.*/

#include <stdio.h>
#include <stdlib.h>
//lb = lower bound(left index), ub = upper bound,(right index),A,B,C,R are the array
int count = 0;
void Merge(int A[],int lb,int mid, int ub){
int i, j, k, R[1000];
i=lb;
j=mid+1;
k=lb;
while(i<=mid && j<=ub){
if(A[i] < A[j]){
    R[k++] = A[i++];
    count++;
}
else{
    R[k++] = A[j++];
    count++;
}
}
while(i<=mid){
    R[k++] = A[i++];
    count++;
}
while(j<=ub){
    R[k++] = A[j++];
    count++;
}

for(i=lb; i<=ub; i++)
A[i]=R[i];
}

void MergeSort(int A[],int lb, int ub){
    int mid;
    if(lb<ub){
    mid = (lb+ub)/2;
    MergeSort(A,lb,mid);
    MergeSort(A,mid+1,ub);
    Merge(A,lb,mid,ub);
   }
}

int main(){
int n,i,j,c1,c2,c3,A[1000],B[1000],C[1000];
printf("Enter the no. of elements to be sorted: ");
scanf("%d",&n);
printf("\n Read elements\n");
for(i=0; i<n; i++)
scanf("%d",&A[i]);
count = 0;
MergeSort(A,0,n-1);
printf("\n Sorted elements are:\n");
for(i=0; i<n; i++)
printf("%d\t",A[i]);
printf("\n");
printf("\nNo. of count is %d\n",count);
printf("\nSIZE\tAssending\tDescending\tRandom\n");
for(i = 8; i < 1000; i = i * 2){
    for(j = 0; j < i; j++){
        A[j] = j;
        B[j] =i-j;
        C[j] =rand() % i;
    }
    count = 0;
    MergeSort(A, 0, i-1);
    c1 = count;
    count = 0;
    MergeSort(B, 0, i-1);
    c2 = count;
    count = 0;
    MergeSort(C, 0, i-1);
    c3 = count;
    printf("\n");
    printf("%d \t%d\t\t%d\t\t%d\n",i,c1,c2,c3);
}
return 0;
printf("\n");
}


