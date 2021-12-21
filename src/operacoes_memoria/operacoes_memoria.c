#include "../controle/controle.h"
#include <stdlib.h>
#include <stdio.h>

void LOAD(int RX, int RY)
{
    registrador[RX] = memoria[RY];
}
void STORE(int RX, int RY)
{
    memoria[RY] = registrador[RX];
}
void PRINT(int RX)
{
    printf("%li\n", registrador[RX]);
}
void EXIT(void)
{
    exit(0);
}
