
FILE* fopen(const char* Path_al_archivo, const char* modo);
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


int fclose(FILE* pArchivo);

siemple hay que cerrar los archivos, si no, pueden quedar corruptos //
Si se cierra correctamente devuelve 0 si hay errores -1