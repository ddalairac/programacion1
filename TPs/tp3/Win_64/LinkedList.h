/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement); // sobre escribe el elementeo de la lista con el que esta pasando
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this); // lo deja como el new, reset de los datos
int ll_deleteLinkedList(LinkedList* this); // lo saca de la lista y libera la memoria
int ll_indexOf(LinkedList* this, void* pElement); // si el elemento esta en la lista devuelve cual es el indice
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index); // devuelve la referencia y lo saca de la lista
int ll_contains(LinkedList* this, void* pElement); // dice si esta o no en la lista
int ll_containsAll(LinkedList* this,LinkedList* this2); // si un linked list esta incluido en el otro
LinkedList* ll_subList(LinkedList* this,int from,int to); // devuelve una copia de un segmento de la lista
LinkedList* ll_clone(LinkedList* this); // devuelve un linkedlists igual
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
