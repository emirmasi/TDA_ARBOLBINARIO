#include "Arbol.h"

void crearArbol(t_Arbol *a)
{
    *pa = NULL;
}

int insertarEnArbol(t_Arbol *a,const void *d,unsigned tam,int(*cmp)(const void *,const void *))
{
    t_nodoA *nue;
    int res;

    if(*a)
    {
        res = cmp(d,(*a)->info);
        if(res == 0)
            return -1;
        return insertarEnArbol(res<0?&(*a)->izq:&(*a)->der,d,tam,cmp);
    }
    nue = malloc(sizeof(t_nodoA));
    if(!nue)
        return 0;
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,tam);
    nue->tamInfo = tam;
    nue->izq = NULL;
    nue->der = NULL;
    *a = nue;
    return 1;
}
void mostrarPreOrden(t_Arbol *a,void(*mostrar)(const void *))
{
    if(!*a)
        return;
    mostrar((*a)->info);
    mostrarPreOrden(&(*a)->izq,mostrar);
    mostrarPreOrden(&(*a)->der,mostrar);
}
void mostrarPosOrden(t_Arbol *a,void(*mostrar)(const void *))
{
    if(!*a)
        return;
    mostrarPosOrden(&(*a)->izq,mostrar);
    mostrarPosOrden(&(*a)->der,mostrar);
    mostrar((*a)->info);
}
void mostrarEnOrden(t_Arbol *a,void(*mostrar)(const void *))
{
    if(!*a)
        return ;
    mostrarEnOrden(&(*a)->izq,mostrar);
    mostrar((*a)->info);
    mostrarEnOrden(&(*a)->der,mostrar);
}
unsigned cantNodos(t_Arbol *a)
{
    if(!*a)
        return 0;
    return 1 + cantNodos(&(*a)->izq) + cantNodos(&(*a)->der);
}
unsigned cantHojas(const t_Arbol *a)
{
    if(!*a)
        return 0;
    if(!(*a)->izq && !(*a)->der)
        return 1;
    return cantHojas(&(*a)->izq) + cantHojas(&(*a)->der);
}
unsigned cantRamas(const t_Arbol *a)
{
    return cantNodos(*a)-1;
}
unsigned alturaArbol(const t_Arbol *a)
{
    int altIzq,altDer;

    if(!*a)
        return 0;

    altIzq = alturaArbol(&(*a)->izq);
    altDer = alturaArbol(&(*a)->der);

    return (altIzq>altDer?altIzq:altDer)+1;
}
