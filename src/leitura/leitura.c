#include <stdio.h>
#include "leitura.h"

int qnt_linhas(void)
{
    int N;
    scanf("%d", &N);

    /* Tira os whitespaces do buffer */
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');

    return N;
}