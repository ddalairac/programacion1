### CLASE 4 Página
Funciones y bibliotecas: Diseño de una función. Recursividad. Biblioteca de funciones propias.
- [Biblioteca Inputs](https://www.utnfravirtual.org.ar/pluginfile.php/10484/mod_folder/content/0/biblioteca_input_v2.pdf?forcedownload=1)<br>

Las funciones pueden recibir datos (parametros), devolver datos (return). Si retornan datos, se declara que tipo de dato retornan.<br>

Hay 4 combinaciones:

- **type** functionName **(parameter)**
- **type** functionName **(void)**
- **void** functionName **(parameter)**
- **void** functionName **(void)**

##### Crear funciones
*prototipo de la funcion (si usas mal la funcion da error)*  <br>
int sumar1(int,int);  <br>

*desarrollo de la funcion*  <br>
int sumar1(int x, int y){  <br>
.    int suma;  <br>
.    suma = x + y;  <br>
.    return suma;  <br>
}  <br>