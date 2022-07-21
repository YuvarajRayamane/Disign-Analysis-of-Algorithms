#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count;

void swap (int *a, int *b)
{
  int t;
  t = *a;
  *a = *b;
  *b = t;
}


int partition (int A[], int lb, int ub)
{
  int i, j, pivot;
  pivot = A[lb];
  i = lb + 1;
  j = ub;
  while (1)
    {
      while (pivot >= A[i] && i <= ub){
          i++;
          count++;
      }
      while (pivot < A[j] && j > lb){
          j--;
          count++;
      }
      if (i < j){
          swap (&A[i], &A[j]);
      }
      else
	{
	  swap (&A[lb], &A[j]);
	  return j;
	}
    }
}

void quicksort (int A[], int lb, int ub)
{
  if (lb < ub)
    {
      int p = partition (A, lb, ub);
      quicksort (A, lb, p - 1);
      quicksort (A, p + 1, ub);
    }
}




int main ()
{
  int n, i,j, c1, c2, c3,A[1000], B[1000], C[1000];
  printf ("Read no. of elements: ");
  scanf ("%d", &n);
  printf ("\nread elements\n");
  for (i = 0; i < n; i++)
    scanf ("%d", &A[i]);
    count = 0;
  quicksort (A, 0, n - 1);
  printf ("\n sorted elements are\n");
  for (i = 0; i < n; i++)
    printf ("%d\t", A[i]);
    
    printf("\n No. of count is = %d",count);
    printf("\n SIZE\tAscending\tTime\tDecending\tTime\tRandom\tTime\n");
    for(i=8; i<1000; i=i*2){
        int ln = 2 * i * log(i) / log(2);
        for(j=0; j<i; j++){
            A[j] = j;
            B[j] = i - j;
            C[j] = rand() % i;
        }
        count = 0;
        quicksort(A,0,i-1);
        c1 = count;
        count = 0;
        quicksort(B,0,i-1);
        c2 = count;
        count = 0;
        quicksort(C,0,i-1);
        c3 = count;
        printf("\n%d\t %d\t\t%d\t %d\t\t%d\t %d\t %d\n",i,c1,i*i,c2,i*i,c3,ln);
        
    }
  return 0;
}
