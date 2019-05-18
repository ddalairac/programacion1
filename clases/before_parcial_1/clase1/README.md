### CLASE 1 Página
Introducción al lenguaje C, Forma general de un programa, Sentencias de control y bucles, Variables, constantes y operadores.

### Tipos de datos
**int** numeros enteros = 10; <br>
**float** decimal = 3.1681;  <br>
**char** letra = 'a';  <br>


### Visualizacion de variables (mascaras)
- %d      decimal<br>
- %f      float<br>
- %.2f    float con 2 decimales (si hay mas redondea)<br>
- %c      character<br>
- %s      array de characters (string)<br>

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