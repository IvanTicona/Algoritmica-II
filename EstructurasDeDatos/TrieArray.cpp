#include <bits/stdc++.h>

using namespace std;

struct node{
  //Creamos la estructura de un nodo
	char currentCharacter; //Variable para guardar el caracter actual
	bool endOfWord; //Variable para saber si es el final de una palabra
	node *children[26]; //Creamos un arreglo de 27 elementos, ya que el alfabeto tiene 26 letras
  //Constructor para inicializar los valores
	node(){
		endOfWord = false;
		for (int i = 0; i < 27; i++){
			children[i] = NULL;
		}
	}
};

void insert(node *trie, string word){
	node *currentNode = trie; //Creamos un nodo actual
	for (int i = 0; i < word.size(); i++){// Recorremos la palabra
		int index = word[i] - 'a'; //Obtenemos el indice de la letra actual
		if (currentNode->children[index] == NULL){ //Si el nodo actual en la posicion index es nulo
			currentNode->children[index] = new node(); //Creamos un nuevo nodo
		}
		currentNode = currentNode->children[index]; //Nos movemos al siguiente nodo
		currentNode->currentCharacter = word[i]; //Guardamos el caracter actual
	}
  currentNode->endOfWord = true; //Marcamos el final de la palabra
}

bool search(node *trie, string word){
	node *currentNode = trie; //Creamos un nodo actual
	for (int i = 0; i < word.size(); i++){ //Recorremos la palabra
		int index = word[i] - 'a'; //Obtenemos el indice de la letra actual
		if (currentNode->children[index] == NULL){ //Si el nodo actual en la posicion index es nulo
			return false; //Retornamos falso ya que la palabra no existe
		}
		currentNode = currentNode->children[index]; //Nos movemos al siguiente nodo
	}
	return currentNode->endOfWord; //Retornamos si es el final de la palabra
}

void deleteWord(node *trie, string word){
  node *currentNode = trie; //Creamos un nodo actual
  for (int i = 0; i < word.size(); i++){ //Recorremos la palabra
    int index = word[i] - 'a'; //Obtenemos el indice de la letra actual
    if (currentNode->children[index] == NULL){ //Si el nodo actual en la posicion index es nulo
      return; //Retornamos ya que la palabra no existe
    }
    currentNode = currentNode->children[index]; //Nos movemos al siguiente nodo
  }
  currentNode->endOfWord = false; //Marcamos el final de la palabra como falso ya que la eliminamos
}

bool hasChildren(node *currentNode) {
    for (int i = 0; i < 26; i++) { // Verifica si el nodo tiene hijos
        if (currentNode->children[i] != NULL) {
            return true;
        }
    }
    return false;
}

bool deleteWor(node *currentNode, string word, int depth = 0) {
    if (depth == word.size()) { // Si hemos recorrido toda la palabra
        if (!currentNode->endOfWord) {
            return false; // La palabra no existe
        }
        currentNode->endOfWord = false; // Marcamos el final de palabra como falso
        return !hasChildren(currentNode); // Retornamos si no tiene hijos (puede eliminarse)
    }

    int index = word[depth] - 'a'; // Obtenemos el índice de la letra actual
    node *childNode = currentNode->children[index];

    if (childNode == NULL) {
        return false; // La palabra no existe
    }

    // Llamada recursiva al siguiente nivel
    bool shouldDeleteCurrentNode = deleteWor(childNode, word, depth + 1);

    // Si se debe eliminar el nodo hijo, lo eliminamos
    if (shouldDeleteCurrentNode) {
        delete currentNode->children[index]; // Elimina el nodo hijo
        currentNode->children[index] = NULL; // Marca la referencia como nula

        // Retorna true si el nodo actual no tiene hijos y no es el final de otra palabra
        return !hasChildren(currentNode) && !currentNode->endOfWord;
    }

    return false;
}

int main(){

	node *trie = new node(); //Creamos el nodo raiz (nodo fantasma)

  //Palabras de ejemplo
	vector<string> words = {
    "apple",
    "app",
    "apricot",
    "banana",
    "blueberry",
    "cranberry",
    "grape",
    "grapefruit",
    "kiwi",
    "lemon",
    "lime",
    "mango",
    "melon",
    "orange",
    "papaya",
    "peach",
    "pear",
    "pineapple",
    "plum",
    "raspberry",
    "strawberry",
    "watermelon"
  };

  //Insertamos las palabras en el trie
	for(string &word : words){
		insert(trie, word);
	}

  //Buscamos palabras en el trie
  cout<<search(trie, "apple")<<endl; //true
  cout<<search(trie, "adrian")<<endl; //false
  cout<<search(trie, "app")<<endl; //true
  cout<<search(trie, "grapefruit")<<endl; //true
  cout<<search(trie, "dorian")<<endl; //false
  cout<<search(trie, "lemon")<<endl; //true
  cout<<search(trie, "papaya")<<endl; //true
  cout<<search(trie, "paul")<<endl; //false
  cout<<search(trie, "pear")<<endl; //true

  //Eliminamos palabras del trie
  deleteWord(trie, "apple");
  cout<<search(trie, "apple")<<endl; //false
  deleteWord(trie, "app");
  cout<<search(trie, "app")<<endl; //false
  deleteWord(trie, "grapefruit");
  cout<<search(trie, "grapefruit")<<endl; //false
  deleteWord(trie, "kiwi");
  cout<<search(trie, "kiwi")<<endl; //false
  deleteWord(trie, "lemon");
  cout<<search(trie, "lemon")<<endl; //false

	return 0;
}