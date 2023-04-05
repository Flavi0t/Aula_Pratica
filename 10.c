#include <stdio.h>

void mdc(int a, int b, int *s, int *t)
{
  int s1, t1;
  if (b == 0) 
  {
    *s = 1;
    *t = 0;
    return;
  }

  mdc(b, a % b, &s1, &t1);
  *s = t1;
  *t = s1 - (a / b) * t1;
}

int inverso(int a, int b, int *inv)
{
  int s, t;
  mdc(a, b, &s, &t);
  if (s < 0) 
  {
    s += b;
  }
  if (a * s + b * t == 1) 
  {
    *inv = s;
    return 1;
  } 
  else 
  {
    return 0;
  }
}

int teorema_chines_resto(int n, int a[], int r[])
{
  int m[n];
  int i, j;

  for (i = 0; i < n; i++)
  {
    m[i] = a[i];
    for (j = 0; j < i; j++)
    {
      int s, t;
      mdc(a[i], a[j], &s, &t);
      if (s != 1) {
        return -1;
      }
    }
  }

  int M = 1;
  for (i = 0; i < n; i++)
  {
    M *= m[i];
  }

  int x = 0;
  
  for (i = 0; i < n; i++) 
  {
    int Mi = M / m[i];
    int xi;
    inverso(Mi, m[i], &xi);
    x += r[i] * Mi * xi;
  }

  x = x % M;
  
  if (x < 0)
  {
    x += M;
  }

  return x;
}

int main() 
{
  int n, i;
  scanf("%d", &n);

  int a[n], r[n];
  
  for (i = 0; i < n; i++) 
  {
    scanf("%d %d", &a[i], &r[i]);
  }

  int x = teorema_chines_resto(n, a, r);
  if (x == -1) 
  {
    printf("Os modulos nao sao coprimos. Nao e possivel aplicar o Teorema Chines do Resto.\n");
  } 
  else
  {
    printf("%d\n", x);
  }

  return 0;
}
