# UTN Tecnicatura en Programación

## Materia programacion 1
Tema: 
 - C
 - Programacion funcional
 - Linkedlist

### Notas
https://docs.google.com/document/d/1m2GjBPPb6hR9IA5B0wBil9xXTLlLLlJVCAbSxLPmGRc/edit#heading=h.778g7jvcmve8

<br>
<br>

[funciones natiavas y librerias](http://pablin.com.ar/computer/cursos/c2/manc8.htm)

### Tipos de datos
**int** numeros enteros = 10; <br>
**float** decimal = 3.1681;  <br>
**char** letra = 'a';  <br>
char nombre **[20]**;  <br>
char nombre **[ ] [20]**;   <br>
**eEstruct** estruct  <br>  <br>

***pointer** referencia a la memoria  <br>
(*vec+0) = vec[0]   <br>    

### Funciones nativas
**printf**("Hello world!\n");  <br>
printf("mas de una variable %d, %d y %d \n", num1, num2, num1+num2);  <br>

**scanf**("%d", &numero);<br>
scanf("%s", nombre);  <br>
scanf("%c", &confirm);   <br>
confirm = **getchar()**;  *(idem ejemplo anterior)*  <br>
. . . . . . . getch(); (no espera enter y NO te muestra el caracter)  <br>
. . . . . . . getche(); (no espera enter y te muestra el caracter)  <br>

**fflush** (stdin); (limpia el buffer, para asegurarte que no quedo nada viejo)  <br>
**strcpy** (origen,destino); (para copiar strings)  <br>


### Castear int a float
(float) 2 = 2.0 <br>
atoi( “2”) = 2 <br>
itoa(12345,vec,10); = “1,2,3,4,\0”  <br>
. . . (2: binary, 10: decimal, 16: hexadecimal)
 

### Mascaras / Visualizacion de variables
- %d      decimal
- %f      float
- %.2f    float con 2 decimales (si hay mas redondea)
- %c      character
- %s      array de characters (string)


### Crear funciones
*prototipo de la funcion (si usas mal la funcion da error)*  <br>
int sumar1(int,int);  <br>

*desarrollo de la funcion*  <br>
int sumar1(int x, int y){  <br>
.    int suma;  <br>
.    suma = x + y;  <br>
.    return suma;  <br>
}  <br>

#define TAM 10
Crea la constante TAM de valor 10

### Manejo de Strings
- strcpy(strVec1, strVec2);  <br>
  Sobre escribe strVec1 con los caracteres de strVec2 <br>
- strcat(strVec1, strVec2);  <br>
  Concatena los valores de strVec2 despues del el ultimo caracter de strVec1<br>
- strlwr(vec);  <br>
  Combierte todos los caracteres en minusculas<br>
