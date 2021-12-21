#if !defined(CONTROLE_H)
#define CONTROLE_H

extern long int registrador[32];
extern long int memoria[1000];


typedef struct linha
{
    char comando[15];
} Linha;

void MOV(int RX, long int inteiro);

void init_flow(Linha instrucoes[], int N);

int decode(Linha i);

int funcoes_iguais(char *comando, char *func);

#endif // CONTROLE_H