#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) \
  {                \
    Item t = A;    \
    A = B;         \
    B = t;         \
  }
#define compexch(A, B) \
  if (less(B, A))      \
  exch(A, B)

#define maxN 1000000
#define min(A, B) (A < B) ? A : B
void merge(Item a[], int l, int m, int r);

Item aux[maxN];

void merge(Item a[], int l, int m, int r)
{ 
  int i, j, k;
  for (i = m+1; i > l; i--) aux[i-1] = a[i-1];
  for (j = m; j < r; j++) aux[r+m-j] = a[j+1];
  for (k = l; k <= r; k++)
  if (less(aux[i], aux[j]))
  a[k] = aux[i++]; else a[k] = aux[j--];
}


void sort(Item a[], int l, int r)
{
  int i, m;
  for (m = 1; m < r-l; m = m+m)
  for (i = l; i <= r-m; i += m+m)
  merge(a, i, i+m-1, min(i+m+m-1, r));

}

int main(int argc, char *argv[])
{
    int i, N;
    clock_t t1, t2;
    char str[100];
    scanf("%d", &N);
    int *a = malloc(N * sizeof(int));
    scanf("%s", str);

    for (i=0;  i<N; i++)
      scanf("%d", &a[i]);

    t1 = clock();
    sort(a, 0, N - 1);
    t2 = clock();
    printf("%6.4fsec\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    scanf("%s", str);
    for (i=0;  i<N; i++)
      scanf("%d", &a[i]);

    t1 = clock();
    sort(a, 0, N - 1);
    t2 = clock();
    printf("%6.4fsec\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

  return 0;
}
