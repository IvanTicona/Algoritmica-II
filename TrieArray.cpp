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