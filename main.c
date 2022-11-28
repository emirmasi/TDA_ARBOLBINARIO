#include "Arbol.h"
int cmpEnteros(const void *d1,const void *d2);
void mostrarEnteros(const void *d);
int main()
{
    int vec[] = {100,50,150,25,75,125,175};
    int i;
    t_ArbolBinBusq arbol;

    crearArbol(&arbol);
    for(i = 0;i<7;i++)
    {
        insertarEnArbol(&arbol,vec+i,sizeof(int),cmpEnteros);
    }
    mostrarEnOrden(&arbol,mostrarEnteros);
    return 0;
}
int cmpEnteros(const void *d1,const void *d2)
{
    return *(int*)d1- *(int*)d2;
}
void mostrarEnteros(const void *d)
{
    printf("[%d]\t",*(int*)d);
}
