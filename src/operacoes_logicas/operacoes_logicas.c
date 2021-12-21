#include "../controle/controle.h"

int BEQ(int RX, int RY, int ENDERECO)
{
    if (registrador[RX] == registrador[RY])
    {

        return ENDERECO;
    }

    return 0;
}

int BLT(int RX, int RY, int ENDERECO)
{
    if (registrador[RX] < registrador[RY])
        return ENDERECO;

    return 0;
}

int JMP(int ENDERECO)
{
    return ENDERECO;
}
