#UTN

## programacion1

### Tipos de datos
**int** numeros enteros = 10; <br>
**float** decimal = 3.1681;  <br>
**char** letra = 'a';  <br>
**char** nombre **[20]**;  <br>
    

### Funciones nativas
**printf**("Hello world!\n");  <br>
printf("mas de una variable %d, %d y %d \n", num1, num2, num1+num2);  <br>

**scanf**("%d", &numero);
scanf("%s", nombre);  <br>
scanf("%c", &confirm);   <br>
confirm = **getchar()**;  *(idem ejemplo anterior)*  <br>
.          getch(); (no espera enter y NO te muestra el caracter)  <br>
.          getche(); (no espera enter y te muestra el caracter)  <br>

**fflush** (stdin); (limpia el buffer, para asegurarte que no quedo nada viejo)  <br>
**strcpy** (origen,destino); (para copiar strings)  <br>


### Castear int a float
promedio = **(float)** (num1+num2)/2;   <br>

### Visualizacion de variables
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