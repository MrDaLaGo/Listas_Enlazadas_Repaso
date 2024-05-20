//
//  listaEnlazadaSimple.c
//  listaEnlazadaSimple


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazadaSimple.h"

int crearVacia(ListaEnlazadaRef raiz){
 // Comprobar si la raíz ya está inicializada
    if (*raiz != NULL) {
        return -1; // Devolver -1 si la lista ya está inicializada
    }

    // Inicializar la raíz a NULL para crear una lista vacía
    *raiz = NULL;

    return 0; // Devolver 0 para indicar éxito
}
int estaVacia(ListaEnlazada raiz){
	if (*raiz == NULL) {
        return 1; // Devolver 1 si la lista está vacía
    }

    return 0; // Devolver 0 si la lista no está vacía
}

tipoNodoRef creaNodo(tipoInfoRef info){
	tipoNodoRef nuevoNodo = (tipoNodoRef)malloc(sizeof(tipoNodo));
	if (nuevoNodo != NULL) {
		nuevoNodo->info = *info;
		nuevoNodo->sig = NULL;
	}
	return nuevoNodo;

}

int insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info){
    // Crear un nuevo nodo
	tipoNodoRef nuevoNodo = creaNodo(info);
	if (nuevoNodo == NULL) {
		return -1; // Devolver -1 si no se pudo crear el nodo
	}

	// Si la lista está vacía, insertar al comienzo
	if (*raiz == NULL) {
		*raiz = nuevoNodo;
		return 0; // Devolver 0 para indicar éxito
	}

	// Si la posición es NULL, insertar al final
	if (pos == NULL) {
		tipoNodoRef aux = *raiz;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevoNodo;
		return 0; // Devolver 0 para indicar éxito
	}

	// Insertar después de la posición indicada
	nuevoNodo->sig = pos->sig;
	pos->sig = nuevoNodo;

	return 0; // Devolver 0 para indicar éxito
}

int insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info){
	// Crear un nuevo nodo
	tipoNodoRef nuevoNodo = (tipoNodoRef) malloc(sizeof(tipoNodo));
	if (nuevoNodo == NULL) {
		return -1; // Devolver -1 si la asignación de memoria falló
	}
	
	// Inicializar el nuevo nodo
	nuevoNodo->info = *info;
	nuevoNodo->sig = pos;
	
	// Si la lista está vacía, hacer que el nuevo nodo sea la raíz
	if (*raiz == NULL) {
		*raiz = nuevoNodo;
		return 0; // Devolver 0 para indicar éxito
	}
	
	// Buscar el nodo anterior a 'pos'
	tipoNodoRef anterior = *raiz;
	while (anterior->sig != pos && anterior->sig != NULL) {
		anterior = anterior->sig;
	}
	
	// Si no se encontró 'pos', liberar el nuevo nodo y devolver -2
	if (anterior->sig != pos) {
		free(nuevoNodo);
		return -2;
	}
	
	// Insertar el nuevo nodo antes de 'pos'
	anterior->sig = nuevoNodo;
	
	return 0; // Devolver 0 para indicar éxito
}

int insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info){
	// Crear un nuevo nodo
	tipoNodoRef nuevoNodo = creaNodo(info);
	if (nuevoNodo == NULL) {
		return -1; // Devolver -1 si no se pudo crear el nodo
	}

	// Insertar el nuevo nodo al comienzo de la lista
	nuevoNodo->sig = *raiz;
	*raiz = nuevoNodo;

	return 0; // Devolver 0 para indicar éxito
}

int insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info){
	// Crear un nuevo nodo
	tipoNodoRef nuevoNodo = creaNodo(info);
	if (nuevoNodo == NULL) {
		return -1; // Devolver -1 si no se pudo crear el nodo
	}

	// Si la lista está vacía, insertar al comienzo
	if (*raiz == NULL) {
		*raiz = nuevoNodo;
		return 0; // Devolver 0 para indicar éxito
	}

	// Insertar el nuevo nodo al final de la lista
	tipoNodoRef aux = *raiz;
	while (aux->sig != NULL) {
		aux = aux->sig;
	}
	aux->sig = nuevoNodo;

	return 0; // Devolver 0 para indicar éxito
}

int insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info){
	if (*raiz == NULL && indice != 0) {
		return -1; // Devolver -1 si la lista está vacía y el índice no es 0
	}

	tipoNodoRef aux = *raiz;
	tipoNodoRef anterior = NULL;
	int i = 0;

	while (aux != NULL && i++ < indice) {
		anterior = aux;
		aux = aux->sig;
	}

	if (i != indice) {
		return -2; // Devolver -2 si no se encontró la posición
	}

	tipoNodoRef nuevoNodo = creaNodo(info);
	if (nuevoNodo == NULL) {
		return -3; // Devolver -3 si no se pudo crear el nuevo nodo
	}

	if (anterior == NULL) {
		nuevoNodo->sig = *raiz;
		*raiz = nuevoNodo;
	} else {
		nuevoNodo->sig = aux;
		anterior->sig = nuevoNodo;
	}

	return 0; // Devolver 0 para indicar éxito
}

int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos){
	if (*raiz == NULL) {
		return -1; // Devolver -1 si la lista está vacía
	}

	tipoNodoRef aux = *raiz;
	tipoNodoRef anterior = NULL;

	while (aux != pos && aux != NULL) {
		anterior = aux;
		aux = aux->sig;
	}

	if (aux == NULL) {
		return -2; // Devolver -2 si no se encontró el nodo
	}

	if (anterior == NULL) {
		*raiz = aux->sig;
	} else {
		anterior->sig = aux->sig;
	}

	free(aux);

	return 0; // Devolver 0 para indicar éxito
}

int eliminarNodoComienzo(ListaEnlazadaRef raiz){
	if (*raiz == NULL) {
		return -1; // Devolver -1 si la lista está vacía
	}

	tipoNodoRef aux = *raiz;
	*raiz = aux->sig;
	free(aux);

	return 0; // Devolver 0 para indicar éxito
}

int eliminarNodoFinal(ListaEnlazadaRef raiz){
	if (*raiz == NULL) {
		return -1; // Devolver -1 si la lista está vacía
	}

	tipoNodoRef aux = *raiz;
	tipoNodoRef anterior = NULL;

	while (aux->sig != NULL) {
		anterior = aux;
		aux = aux->sig;
	}

	if (anterior == NULL) {
		*raiz = NULL;
	} else {
		anterior->sig = NULL;
	}

	free(aux);

	return 0; // Devolver 0 para indicar éxito
}

int eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice){
	if (*raiz == NULL) {
		return -1; // Devolver -1 si la lista está vacía
	}

	tipoNodoRef aux = *raiz;
	tipoNodoRef anterior = NULL;
	int i = 0;

	while (aux != NULL && i < indice) {
		anterior = aux;
		aux = aux->sig;
		i++;
	}

	if (i != indice) {
		return -2; // Devolver -2 si no se encontró la posición
	}

	if (anterior == NULL) {
		*raiz = aux->sig;
	} else {
		anterior->sig = aux->sig;
	}

	free(aux);

	return 0; // Devolver 0 para indicar éxito
}

int liberarListaEnlazada(ListaEnlazadaRef raiz){
	tipoNodoRef aux = *raiz;
	tipoNodoRef aBorrar;
	while (aux != NULL) {
		aBorrar = aux;
		aux = aux->sig;
		free(aBorrar);
	}
	*raiz = NULL;
	return 0;
}

tipoInfo devolverInfoPosicionIndice(ListaEnlazada raiz, int indice){
	tipoNodoRef aux = raiz;
	int i = 0;
	while (aux != NULL && i++ < indice) {
		aux = aux->sig;
	}
	if (aux != NULL) {
		return aux->info;
	}
	return -1;
}

int insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info){
	tipoNodoRef aux = *raiz;
	tipoNodoRef anterior = NULL;
	tipoNodoRef nuevoNodo = creaNodo(info);
	if (nuevoNodo == NULL) {
		return -1;
	}
	while (aux != NULL && aux->info < *info) {
		anterior = aux;
		aux = aux->sig;
	}
	if (anterior == NULL) {
		nuevoNodo->sig = *raiz;
		*raiz = nuevoNodo;
	} else {
		nuevoNodo->sig = aux;
		anterior->sig = nuevoNodo;
	}
	return 0;
}

int mostrarListaEnlazada(ListaEnlazada raiz){
	tipoNodoRef aImprimir;
	int res = 0,i = 0;
	
	printf("\n\n");
	printf("%-14s%-10s\n","  Posición", "Valor");
	printf("%-14s%-10s\n","  ==========", "======");


	aImprimir = raiz;
	while (aImprimir != NULL) {
		printf("\t%3d)\t%7d\n",i++, aImprimir->info);
		aImprimir = aImprimir->sig;
	}
	return res;
}


int crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos){
	int i;
	tipoInfo temp;
	
	if (estaVacia(*raiz)) {
		srandom(time(NULL));
		for (i = 0; i < numNodos; i++) {
            temp = random()%10000;
            insertarDespuesDeNodo(raiz, NULL, &temp);
            //insertarAntesDeNodo(raiz, NULL, &temp);
            //insertarNodoFinal(raiz, &temp);
			//insertarNodoComienzo(raiz, &temp);
		}
		return 0;
	}
	return -1;
}


