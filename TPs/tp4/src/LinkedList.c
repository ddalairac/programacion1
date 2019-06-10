#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL){
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this){
    int returnAux = -1;
    if(this != NULL){
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex){
    Node* pNode = NULL;
    int i;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < this->size){
        pNode = this->pFirstNode;
        for(i = 0; i < nodeIndex; i++){
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex){
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int returnAux = -1;

    Node* pNewNode = (Node*) malloc(sizeof(Node));
    Node* pAuxNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= this->size && pNewNode != NULL){

        pNewNode->pElement = pElement;
        pNewNode->pNextNode = NULL;
        returnAux = 0;
        this->size++;

        /** No hay items en la lista*/
        if(nodeIndex == 0 && this->size == 0){
            this->pFirstNode = pNewNode;
            //free(this->pFirstNode->pNextNode);
        }else{
            /** cambiar primer item de la lista */
            if(nodeIndex == 0 && this->size!=0){
                pAuxNode = getNode(this, 0); /** Guardo el link anterior */
                this->pFirstNode = pNewNode;
                this->pFirstNode->pNextNode = pAuxNode;
            }else{
                /** cambiar ultimo item de la lista */
                if(nodeIndex == this->size){
                    pAuxNode = getNode(this, nodeIndex-1);  /** Guardo el link anterior */
                    pAuxNode->pNextNode = pNewNode;
                    //free(pNewNode->pNextNode = NULL);
                }else{
                    pAuxNode = getNode(this, nodeIndex-1);  /** Guardo el link anterior */
                    pAuxNode->pNextNode = pNewNode;
                    pAuxNode->pNextNode->pNextNode = pAuxNode;
                }
            }
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement){
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;

    if(this != NULL){
        returnAux = addNode(this, this->size, pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index){
    void* returnNode = NULL;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < this->size){
        auxNode = getNode(this, index);
        if(auxNode->pElement != NULL){
            returnNode = auxNode->pElement;
        }
    }

    return returnNode;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement){
    int response = -1;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < this->size){
        auxNode = getNode(this, index);
        auxNode->pElement = pElement;
        response = 0;
    }

    return response;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index){
    int returnAux = -1;

//    Node* node;
//    Node* nextNode;
//    Node* prevNode;

    Node* prevNode;
    Node* pDelNode;

    if(this != NULL && index >= 0 && index < this->size && this->size > 0){

        pDelNode = getNode(this, index);

        if(index == 0){
            this->pFirstNode = pDelNode->pElement;

        } else {
            prevNode = getNode(this, index -1);
            prevNode->pElement = pDelNode->pElement;
        }
        free(pDelNode);
        this->size--;
        returnAux = 0;
    }

//       if(index == 0 && this->size > 2){
//            /**
//                Si el nodo a eliminar es el primero y la lista tiene mas de 2 elementos,
//                el elemento 1 tomara la posicion del elemento 0, y se reducira el tamaño.
//            **/
//                node = getNode(this, 1);
//                this->pFirstNode->pNextNode = node->pNextNode;
//                this->pFirstNode->pElement = node->pElement;
//                this->size--;
//                returnAux = 0;
//       }else{
//           if(index==0 && this->size==1){
//                /**
//                    Si el nodo a eliminar es el primero y la ll tiene tamaño 1,
//                    el pFirstNode de la ll es el eliminado, y se reduce el tamaño
//                    de la lista
//                **/
//                this->pFirstNode=NULL;
//                this->size--;
//                returnAux = 0;
//           }else{
//               /**
//                    Si el elemento a eliminar es el siguiente al pFirstNode,
//                    se establece al nodo en el indice 2 como pNextNode de
//                    pFirstNode, y se reduce el tamaño de la lista.
//               **/
//                if(index==1){
//                    node=getNode(this, index);
//                    nextNode=getNode(this, index+1);
//                    this->pFirstNode->pNextNode=nextNode;
//                    this->size--;
//                    node=NULL;
//                    returnAux = 0;
//               }else{
//                   /**
//                        Si el elemento a eliminar es cualquier otro,
//                        el nodo anterior al deseado apuntara al siguiente,
//                        y se seteara como NULL al nodo a eliminar.
//                        Se recude el tamaño de la lista en 1.
//                   **/
//                    node=getNode(this, index);
//                    nextNode=getNode(this, index+1);
//                    prevNode=getNode(this, index-1);
//                    prevNode->pNextNode=nextNode;
//                    this->size--;
//                    node=NULL;
//                    returnAux = 0;
//               }
//           }
//        }
//    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement){
    int returnAux = -1;
    int nodeIndex = index;
    LinkedList* thisAux = this;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < this->size){
        thisAux = (LinkedList *)malloc(sizeof(LinkedList) * this->size);
        if(thisAux != NULL){
            thisAux = this;
            if(nodeIndex == 0){
                this->pFirstNode = pElement;
            } else {
                (this->pFirstNode+(nodeIndex-1))->pNextNode = pElement;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

