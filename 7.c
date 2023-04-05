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
  } 
  else 
  {
    return (s % b + b) % b;
  }
}

int main() 
{
  int a, b;
  printf("Digite dois números inteiros: ");
  scanf("%d %d", &a, &b);

  int inv = inverso(a, b);

  if (inv == -1) 
  {
    printf("O numero %d nao tem inverso modulo %d.\n", a, b);
  } 
  else 
  {
    printf("O inverso de %d modulo %d eh %d.\n", a, b, inv);
  }

  return 0;
}