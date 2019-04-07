### CLASE 5 Página
Arrays: Carga secuencial. Carga aleatoria. Búsquedas y ordenamiento sobre vectores.
- [Algoritmos de ordenamiento](https://www.utnfravirtual.org.ar/mod/resource/view.php?id=6243)


**char** nombre **[20]**;  <br>

- int vec[ ] = { 21, 23, 54}; <br>
  autocomplete la cantidad<br>

- int vec[3];  <br>
  Si no los iniciativo, muestran la basura de memoria <br>

  El nombre de un vector es un puntero que guarda la primer dirección de memoria del vector

##### Tecnicas de ordenamiento:

- Burbujeo:<br>
Recorre todo el vector, y por cada indice, vuelve hace otro loop desde ese punto hasta el final.
Compara un elemento del vector con su predecesor, en caso de no cumplir la condicion (Ascendente o Descendente) los intercambia<br>

- Insercion:<br>
Recorre todo el vector, y por cada indice, vuelve hace otro loop desde ese punto hasta el principio.
Compara un elemento del vector con su predecesores, en caso de no cumplir la condicion (Ascendente o Descendente) mueve todos los predecesores (que no corresponden) hacia adelante, e inserta el indice comparado en la posicion correcta. <br>
