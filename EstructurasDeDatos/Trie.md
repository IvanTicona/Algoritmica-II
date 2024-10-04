# Trie Data Structure

- Prefijo: Todas las letras con las que empieza una palabra.
- Trie: Estructura de datos que permite almacenar un conjunto de palabras y realizar búsquedas de palabras en tiempo lineal.
- Operaciones:
  - Insertar una palabra.
  - Buscar una palabra.
  - Buscar prefijo.

```
struc node {
  char currentCharacter;
  bool isWord;
  struct node *children[27];
  node(){
    isWord = false;
  }
}*trie;
```

Tipos de complejidad en algoritmos:
- Tiempo: Cantidad de operaciones que realiza un algoritmo.
- Espacio: Cantidad de memoria que utiliza un algoritmo.
