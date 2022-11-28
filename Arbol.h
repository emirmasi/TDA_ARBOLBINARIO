#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodoA
{
    void *info;
    unsigned tamInfo;
    struct s_nodoA *izq,*der;
}t_nodoA;

typedef t_nodoA *t_Arbol;

void crearArbol(t_Arbol *a);
int insertarEnArbol(t_Arbol *a,const void *d,unsigned tam,int(*cmp)(const void *,const void *));
void mostrarPreOrden(t_Arbol *a,void(*mostrar)(const void *));
void mostrarPosOrden(t_Arbol *a,void(*mostrar)(const void *));
void mostrarEnOrden(t_Arbol *a,void(*mostrar)(const void *));

unsigned cantNodos(const t_Arbol *a);
unsigned cantHojas(const t_Arbol *a);
unsigned cantRamas(const t_Arbol *a);

#endif // ARBOL_H_INCLUDED
