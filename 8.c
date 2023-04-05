#include <stdio.h>

int mdc(int a, int b, int *s, int *t) 
{
  if (b == 0) 
  {
    *s = 1;
    *t = 0;
    return a;
  }

  int s1, t1;
  int d = mdc(b, a % b, &s1, &t1);
  *s = t1;
  *t = s1 - (a / b) * t1;

  return d;
}

int inverso(int a, int b) 
{
  int s, t;
  int d = mdc(a, b, &s, &t);
  if (d != 1) 
  {
    return -1;
  } else 
  {
    return (s % b + b) % b;
  }
}

int congruencia(int a, int b, int m) 
{
  int inv = inverso(a, m);
  if (inv == -1) 
  {
    return -1;
  } 
  else 
  {
    return (b * inv) % m;
  }
}

int main() 
{
  int a, b, m;
  printf("Digite três números inteiros (a, b, m): ");
  scanf("%d %d %d", &a, &b, &m);

  int solucao = congruencia(a, b, m);

  if (solucao == -1) 
  {
    printf("Nao existe solucao para a congruencia %d x ≡ %d mod %d.\n", a, b, m);
  } 
  else 
  {
    printf("A solucao para a congruencia %d x ≡ %d mod %d eh %d.\n", a, b, m, solucao);
  }

  return 0;
}