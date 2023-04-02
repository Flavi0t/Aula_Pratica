#include <stdio.h>

int main()
{
    int num1, num2, mdc = 1, mmc = 1;
    int fator = 2;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    while (num1 > 1 || num2 > 1)
    {
        if (num1 % fator == 0 && num2 % fator == 0)
        {
            mdc *= fator;
            mmc *= fator;
            num1 /= fator;
            num2 /= fator;
        }
        else if (num1 % fator == 0)
        {
            mmc *= fator;
            num1 /= fator;
        }
        else if (num2 % fator == 0)
        {
            mmc *= fator;
            num2 /= fator;
        }
        else
        {
            fator++;
        }
    }

    printf("MDC: %d\n", mdc);
    printf("MMC: %d\n", mmc);

    return 0;
}