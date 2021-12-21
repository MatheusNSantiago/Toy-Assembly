#include "../controle/controle.h"
void ADD(int RX, int RY, int RZ)
{
    registrador[RX] = registrador[RY] + registrador[RZ];
}

void SUB(int RX, int RY, int RZ)
{
    registrador[RX] = registrador[RZ] - registrador[RY];
}

void MUL(int RX, int RY, int RZ)
{
    registrador[RX] = registrador[RY] * registrador[RZ];
}

void DIV(int RX, int RY, int RZ)
{
    registrador[RX] = registrador[RY] / registrador[RZ];
}

void MOD(int RX, int RY, int RZ)
{
    registrador[RX] = registrador[RY] % registrador[RZ];
}
