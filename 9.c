#include <stdio.h>

int mdc(int a, int b, int *s, int *t)
{
  int s1, t1;
  if (b == 0) 
  {
    *s = 1;
    *t = 0;
    return a;
  }

  int d = mdc(b, a % b, &s1, &t1);
  *s = t1;
  *t = s1 - (a / b) * t1;

  return d;
}

int inverso(int a, int b, int *inv) 
{
  int s, t;
  int d = mdc(a, b, &s, &t);
  if (d != 1) 
  {
    return 0;
  } 
  else 
  {
    *inv = (s % b + b) % b;
    return 1;
  }
}

int teorema_chines_resto(int a1, int r1, int a2, int r2, int a3, int r3)
{
  int m1 = a1, m2 = a2, m3 = a3;

  int s1, t1, s2, t2, s3, t3;
  mdc(m1, m2, &s1, &t1);
  mdc(m1, m3, &s2, &t2);
  mdc(m2, m3, &s3, &t3);

  int x;
  inverso(m1 * m2, m3, &x);
  x = r1 * m2 * t1 + r2 * m1 * t2 + r3 * m1 * m2 * x * t3;
  x = x % (m1 * m2 * m3);
  if (x < 0)
  {
    x += m1 * m2 * m3;
  }
  return x;
}

int main()
{
  int a1, r1, a2, r2, a3, r3;
  printf("Digite as três congruências (ai e ri /digite um numero, aperte 'espaco', digite outro numero,aperte 'enter', e repita):\n");
  scanf("%d %d %d %d %d %d", &a1, &r1, &a2, &r2, &a3, &r3);

  int m1 = a1, m2 = a2, m3 = a3;
  int s, t;
  mdc(m1, m2, &s, &t);
  int d1 = mdc(m1, m3, &s, &t);
  int d2 = mdc(m2, m3, &s, &t);

  if (d1 != 1 || d2 != 1) 
  {
    printf("Os modulos nao sao coprimos. Nao eh possivel aplicar o Teorema Chines do Resto.\n");
    return 0;
  }

  int x = teorema_chines_resto(a1, r1, a2, r2, a3, r3);

  printf("A solucao unica das tres congruencias eh %d.\n", x);

  return 0;
}