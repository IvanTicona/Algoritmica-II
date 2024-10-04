#include <bits/stdc++.h>

using namespace std;

struct node{
	char currentCharacter;
	bool endOfWord;
	node *children[27];
	int count;

	node(){ //Constructor
		endOfWord = false;
		for (int i = 0; i < 27; i++){
			children[i] = NULL;
		}
		count = 0;
	}
};

// bool isNumber, isCreated;

void insert(node *trie, string word){
	node *currentNode = trie;
	for (int i = 0; i < word.size(); i++){
		int index = word[i] - 'a';
		if (currentNode->children[index] == NULL){
			// isCreated=true;
			currentNode->children[index] = new node();
		}
		currentNode = currentNode->children[index];
		// if(currentNode->endOfWord){
		// 	isNumber=true;
		// }
		currentNode->currentCharacter = word[i];
		currentNode->count++;
	}
	// if(isCreated && !isNumber){
		currentNode->endOfWord = true;
	// }
}

int countPrefix(node *trie, string prefix){
	node *currentNode = trie;
	for (int i = 0; i < prefix.size(); i++){
		int index = prefix[i] - 'a';
		if (currentNode->children[index] == NULL){
			return 0;
		}
		currentNode = currentNode->children[index];
	}
	return currentNode->count;
}

bool search(node *trie, string word){
	node *currentNode = trie;
	for (int i = 0; i < word.size(); i++){
		int index = word[i] - 'a';
		if (currentNode->children[index] == NULL){
			return false;
		}
		currentNode = currentNode->children[index];
	}
	return currentNode->endOfWord;
}

int main(){

	int wordsNumber;
	cin >> wordsNumber;

	node *trie = new node();

	while (wordsNumber--){
		string word;
		cin >> word;
		// isNumber = isCreated = false;
		insert(trie, word);
		// cout<<isNumber<<" "<<isCreated<<endl;
	}

	int q; cin>>q;
	while(q--){
		string prefix;
		cin>>prefix;
		cout<<countPrefix(trie, prefix)<<endl;
	}

	return 0;
}