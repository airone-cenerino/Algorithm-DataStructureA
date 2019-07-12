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

#define maxN 10000000
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
  int m = (r + l) / 2;
  if (r <= l)
    return;
  sort(a, l, m);
  sort(a, m + 1, r);
  merge(a, l, m, r);
}

int main(int argc, char *argv[])
{
    int i, N;
    scanf("%d", &N);
    int *a = malloc(N * sizeof(int));

    srand(1);
    for (i=0;  i<N; i++)
      scanf("%d", &a[i]);

    sort(a, 0, N - 1);

    for (i = 0; i < N; i++)
        printf("%d\n", a[i]);

    return 0;
}
