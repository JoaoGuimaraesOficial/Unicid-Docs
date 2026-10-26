#include <stdio.h>

int main()
{
    int v[5];
    int *p = v;

    printf("Digite 5 valoers: \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("Valores digitados: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", *(p + i));
    }
    printf("\n");
    return 0;
}