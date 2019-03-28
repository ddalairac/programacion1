# programacion1
1 cuatrimestre UTN



### Tipos de datos
**int** numeros enteros = 10; <br>
**float** decimal = 3.1681;  <br>
**char** letra = 'a';  <br>
**char** nombre **[20]**;  <br>
    

### Funciones nativas
**printf**("Hello world!\n");  <br>
printf("mas de una variable %d, %d y %d \n", num1, num2, num1+num2);  <br>

**scanf**("%d", &numero);
scanf("%s", nombre); 
scanf("%c", &confirm); 
confirm = **getchar()**;  *(idem ejemplo anterior)*
          getch(); (no espera enter y NO te muestra el caracter)
          getche(); (no espera enter y te muestra el caracter)

**fflush** (stdin); (limpia el buffer, para asegurarte que no quedo nada viejo)
**strcpy** (origen,destino); (para copiar strings)


### Castear int a float
promedio = **(float)** (num1+num2)/2; 

### Visualizacion de variables
- %d      decimal
- %f      float
- %.2f    float con 2 decimales (si hay mas redondea)
- %c      character
- %s      array de characters (string)


### Crear funciones
*prototipo de la funcion (si usas mal la funcion da error)*
int sumar1(int,int);

*desarrollo de la funcion*
int sumar1(int x, int y){
    int suma;
    suma = x + y;
    return suma;
}
