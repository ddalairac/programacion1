#ifndef dominio_H_INCLUDED
#define dominio_H_INCLUDED
typedef struct{
    int id;
    char dominio[7];
    int anio;
    char tipo[2];
}Dominio;

Dominio* d_new();
Dominio* d_newParametros(char* idStr,char* dominioStr,char* anioStr, char* tipoStr);
int d_setId(Dominio* this,int id);
int d_getId(Dominio* this,int* id);
int d_setDominio(Dominio* this,char* dominio);
int d_getDominio(Dominio* this,char* dominio);
int d_setAnio(Dominio* this,int anio);
int d_getAnio(Dominio* this,int* anio);
int d_setTipo(Dominio* this,char* tipo);
int d_getTipo(Dominio* this,char* tipo);
void d_printHeader();
void d_printDominio(Dominio* dom);
void d_printList(LinkedList* list);
int d_loadFromText(char* path , LinkedList* list);
int d_sortByDominio(void* elem1, void* elem2);
void* d_defineType(void* element);

#endif // dominio_H_INCLUDED
