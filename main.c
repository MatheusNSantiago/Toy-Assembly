#include "src/controle/controle.h"
#include "src/leitura/leitura.h"
#include <stdio.h>


int main()
{
    int N = qnt_linhas();

    Linha instrucoes[N];
    for (int i = 0; i < N; i++){
        fgets(instrucoes[i].comando, 15, stdin);
    }

    init_flow(instrucoes, N);
}
