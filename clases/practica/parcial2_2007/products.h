
#ifndef __PROD
#define __PROD
typedef struct{
    int codigo; // de Producto (1 a 1000) Validar
    char descripcion[50];// (máximo 50 caracteres) Validar
    int importe;// Validar
    int cantidad;// Validar
    int activo;// (0 para activo – 1 para NO activo)
} Prod;

#endif

Prod *p_new();
int p_add(LinkedList* list);
void p_printHeader();
void p_printProd(Prod* p);
void p_printList(LinkedList* list);
int p_saveData(LinkedList* list);
int p_loadData(LinkedList* list);
int p_edit(LinkedList* list);
int p_remove_logic(LinkedList* list);
int p_remove_fisic(LinkedList* list);
int p_sort(void *v1, void *v2);
int p_sortByCode(void *v1, void *v2);
int p_sortByDescription(void *v1, void *v2);
int p_sortByImporte(void *v1, void *v2);
int p_sortByCantidad(void *v1, void *v2);
