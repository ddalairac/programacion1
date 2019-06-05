===== Files =====

**fopen()**
FILE* fopen(const char* Path_al_archivo, const char* modo); \\
devuelve un puntero a FILE


| Modo          | Descripcion           | Archivo |
| ------------- | -------------         | ------------- |
| r             | Lectura               | Debe existir |
| w             | Escritura             | Se crea o sobreescribe |
| a             | Escritura al final    | Se crea  |
| r+            | Lectura y Escritura   | Debe existir |
| w+            | Lectura y Escritura   | Se crea o sobreescribe |
| rb+ / r+b     | Lectura y Escritura   | Abre en modo binario para actualizacion |
| rb            | Lectura               | Abre en modo binario |
| wb            | Escritura             | Abre en modo binario |

<code>
pFile = fopen("./banco.txt","w"); 
</code>

**fclose()**
int fclose(FILE* pArchivo); \\

siemple hay que cerrar los archivos, si no, pueden quedar corruptos \\
Si se cierra correctamente devuelve 0 si hay errores -1 \\

<code>
fclose(pFile);
</code>

**fwrite()**
int fwrite(void* origen, size_t tamano, size_t cantidad. FILE* arch); \\

devuelve el numero de datos escritos (cantidad), si el numero devuelto es inferior al ingresado en parametro cantidad, es que hubo un error en la escritura. \\

 * origen: puntero a los datos a escribir
 * tamano: Cantidad de bytes que pretendemos escribir
 * cantidad: Cantidad de elementos del tamano ingresado
 * arch: Puntero a file

<code>
cant = fwrite(text,sizeof(char),len,pFile );
cant = fwrite(&persona,sizeof(ePersona),1,pFile ); 
</code>

**fread()**
int fwrite(void* destino, size_t tamano, size_t cantidad. FILE* arch); \\
devuelve el numero de datos leidos (cantidad)


 * destino: puntero donde se va a dejar el dato leido
 * tamano: Cantidad de bytes que pretendemos escribir
 * cantidad: Cantidad de elementos del tamano ingresado
 * arch: Puntero a file

<code>
cant = fread(text,sizeof(char),len, pFile);
</code>






 exit(0) or exit(EXIT_SUCCESS) \\  
 exit(non-zero) or exit(EXIT_FAILURE) \\