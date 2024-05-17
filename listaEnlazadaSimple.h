//
//  listaEnlazadaSimple.h
//  listaEnlazadaSimple


#ifndef LISTA_ENLAZADA_SIMPLE_H
#define LISTA_ENLAZADA_SIMPLE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef int tipoInfo;

typedef tipoInfo *tipoInfoRef;




typedef struct tipoNodo {
	tipoInfo info;				
	struct tipoNodo * sig;
} tipoNodo;
typedef tipoNodo *tipoNodoRef;


typedef tipoNodo * ListaEnlazada;
typedef ListaEnlazada *ListaEnlazadaRef;


/* Funciones independientes del tipo definido como tipoInfo */

int crearVacia(ListaEnlazadaRef raiz);
int estaVacia(ListaEnlazada raiz);
int liberarListaEnlazada(ListaEnlazadaRef raiz);

int insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info);
int insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info);

int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos);
int insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info);
int insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info);
int eliminarNodoComienzo(ListaEnlazadaRef raiz);
int eliminarNodoFinal(ListaEnlazadaRef raiz);
int insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info);
int eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice);




/* Funciones dependientes del tipo definido como tipoInfo */

tipoInfo devolverInfoPosicionIndice(ListaEnlazada raiz, int indice);
int mostrarListaEnlazada(ListaEnlazada raiz);
int crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos);
int insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info);

#endif
