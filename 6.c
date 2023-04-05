#include <stdio.h>

int mdc(int a, int b, int *s, int *t) {
  if (b == 0) {
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

int main() {
  int a, b;
  printf("Digite dois números inteiros: ");
  scanf("%d %d", &a, &b);

  int s, t;
  int d = mdc(a, b, &s, &t);

  printf("Os coeficientes s e t da combinaçao linear mdc(%d, %d) = s * %d + t * %d sao: \n", a, b, a, b);
  printf("s = %d\n", s);
  printf("t = %d\n", t);

  return 0;
}