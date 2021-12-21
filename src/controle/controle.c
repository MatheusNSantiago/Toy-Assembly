#if !defined(MACRO)
#define MACRO

#include "controle.h"
#include <stdio.h>

long int registrador[32];
long int memoria[1000];

void MOV(int RX, long int inteiro)
{
    registrador[RX] = inteiro;
}

void init_flow(Linha instrucoes[], int N)
{
    int linha = 0;
    for (linha; linha < N; linha++)
    {
        int jmp = decode(instrucoes[linha]); //roda a instrução

        /* caso uma instrução de operação lógica nos redirecionar para outra linha */
        if (jmp != 0)
            linha = jmp - 1; // vá para linha
    }
}

int decode(Linha i)
{
    if (funcoes_iguais(i.comando, "MOV"))
    {
        int RX, RY;
        long int inteiro;

        if (sscanf(i.comando, "MOV R%i %li", &RX, &inteiro) == 2)
        {
            MOV(RX, inteiro);
        }

        if (sscanf(i.comando, "MOV R%i R%i", &RX, &RY) == 2)
            MOV(RX, registrador[RY]);
    }
    if (funcoes_iguais(i.comando, "ADD"))
    {
        int RX, RY, RZ;

        sscanf(i.comando, "ADD R%i R%i R%i", &RX, &RY, &RZ);
        ADD(RX, RY, RZ);
    }
    if (funcoes_iguais(i.comando, "SUB"))
    {
        int RX, RY, RZ;

        sscanf(i.comando, "SUB R%i R%i R%i", &RX, &RY, &RZ);
        SUB(RX, RY, RZ);
    }
    if (funcoes_iguais(i.comando, "MUL"))
    {
        int RX, RY, RZ;

        sscanf(i.comando, "MUL R%i R%i R%i", &RX, &RY, &RZ);
        MUL(RX, RY, RZ);
    }
    if (funcoes_iguais(i.comando, "DIV"))
    {
        int RX, RY, RZ;

        sscanf(i.comando, "DIV R%i R%i R%i", &RX, &RY, &RZ);
        DIV(RX, RY, RZ);
    }
    if (funcoes_iguais(i.comando, "MOD"))
    {
        int RX, RY, RZ;

        sscanf(i.comando, "MOD R%i R%i R%i", &RX, &RY, &RZ);
        MOD(RX, RY, RZ);
    }
    if (funcoes_iguais(i.comando, "BEQ"))
    {
        int RX, RY, ENDERECO;

        sscanf(i.comando, "BEQ R%i R%i %i", &RX, &RY, &ENDERECO);

        return BEQ(RX, RY, ENDERECO);
    }
    if (funcoes_iguais(i.comando, "BLT"))
    {
        int RX, RY, ENDERECO;

        sscanf(i.comando, "BLT R%i R%i %i", &RX, &RY, &ENDERECO);
        return BLT(RX, RY, ENDERECO);
    }
    if (funcoes_iguais(i.comando, "JMP"))
    {
        int ENDERECO;

        sscanf(i.comando, "JMP %i", &ENDERECO);
        return JMP(ENDERECO);
    }
    if (funcoes_iguais(i.comando, "LOAD"))
    {
        int RX, RY;
        sscanf(i.comando, "LOAD R%i R%i", &RX, &RY);
        LOAD(RX, RY);
    }
    if (funcoes_iguais(i.comando, "STORE"))
    {
        int RX, RY;
        sscanf(i.comando, "LOAD R%i R%i", &RX, &RY);
        STORE(RX, RY);
    }
    if (funcoes_iguais(i.comando, "PRINT"))
    {
        int RX;
        sscanf(i.comando, "PRINT R%i", &RX);
        PRINT(RX);
    }
    if (funcoes_iguais(i.comando, "EXIT"))
    {
        EXIT();
    }

    return 0;
}

int funcoes_iguais(char *comando, char *func)
{
    char f[5];

    for (int i = 0; i < 5; i++)
    {
        // Se for espaço ou \0, quer dizer que esse é o fim do segmento
        if (comando[i] == ' ' || comando[i] == '\0')
            break;

        f[i] = comando[i];
    }

    return (strcmp(f, func) == 0);
}

#endif // MACRO
