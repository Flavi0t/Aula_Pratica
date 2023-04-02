#include <stdio.h>

int main()
{
    int num1, num2, resto, MDClides;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    while (num2 != 0)
    {
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;
    }

    MDClides = num1;

    printf("MDC = %d\n",MDClides);

    return 0;
}