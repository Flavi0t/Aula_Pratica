#include <stdio.h>

int main()
{
    int num, fator = 2;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    while (num > 1)
    {
        if (num % fator == 0)
        {
            printf("%d ", fator);
            num /= fator;
        }
        else
        {
            fator++;
        }
    }

    printf("\n");

    return 0;
}