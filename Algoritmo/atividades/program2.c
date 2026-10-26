#include <stdio.h>
int main()
{
    int x = 10;
    int *px;
    px = &x;

    printf("Valor de X (direito): %d\n", x);
    printf("Valor de X (via ponteiro): %d\n", *px);

    printf("Endereço de X: %p\n", &x);
    printf("Endereço guardado em px: %p\n", px);
    return 0;
}