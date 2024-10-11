#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables
#define MAX_N 100010

using namespace std; 

// Variables static

int n, a[MAX_N];
//a es el arreglo que vamos a guardar en el segment tree

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct node{ //Los nodos van a guardar valores
    int sum, mult , min, max, gcd;
}segmentTree[MAX_N*2];


//Construccion del segment tree
void init(int inicio, int final, int nodoActual) {

    if( inicio == final ) {
        segmentTree[nodoActual].max = a[inicio];
    } else {
        int mid = (inicio + final) / 2; //calcula la mitad
        int nodoIzquierdo = 2 * nodoActual + 1; // Calcula el nodo izquierdo
        int nodoDerecho   = 2 * nodoActual + 2; // Calcula el nodo derecho

        init(inicio, mid, nodoIzquierdo );
        init(mid+1, final, nodoDerecho);

        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
    } 
}


node query(int inicio, int final, int nodoActual, int izquierda, int derecha ) {

    if(inicio >= izquierda && final <= derecha ){ 
        return segmentTree[nodoActual];
    }
    
    int mid = (inicio + final ) / 2; 
    int nodoIzquierdo = 2 * nodoActual + 1; //Indice del nodo izquierdo
    int nodoDerecho   = 2 * nodoActual + 2; //Indice del nodo derecho

    if(derecha <= mid ) { // Si el rango esta en el subarbol izquierdo
        return query(inicio, mid, nodoIzquierdo, izquierda, derecha); 
    } else if(izquierda > mid) { // Si el rango esta en el subarbol derecho
        return query(mid+1, final, nodoDerecho, izquierda, derecha);
    } else { // Si el rango esta en ambos lados

        node nodeLeft = query(inicio, mid, nodoIzquierdo,izquierda,derecha);
        node nodeRight   = query(mid+1, final, nodoDerecho,izquierda,derecha);

        node result ;
        result.sum = nodeLeft.sum + nodeRight.sum;
        return result;
    }
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio || posicion > final ){ // Fuera de rango
        return ;
    }

    if( inicio == final ) {
        segmentTree[nodoActual].sum = valor;
    } else { 

        int mid = (inicio + final ) / 2;
        int nodoIzquierdo = 2 * nodoActual + 1;
        int nodoDerecho   = 2 * nodoActual + 2;
        // Actualizar por lado izquierdo
        update(inicio, mid, nodoIzquierdo, posicion, valor );
        // Actualizar por lado derecho 
        update(mid+1, final, nodoDerecho, posicion, valor );

        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;

    }
}

int main() {

// }
    input;
    cin>>n;
    // Leer el arreglo origional
    // Arr [ 2, 5, 4, 7, 8, 9, 1, 3]
    // Segment Tree 
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    // Inicializar Segment Tree
    init(0,n-1, 0);

    for(int i = 0; i < 2*n; i++) {
        cout<<"[ "<<segmentTree[i].sum<<" ]";
    }
    cout<<endl;
    int queries;
    cin>> queries;
    for(int i = 0 ;i <queries ; i++) {
        int izquierda, derecha; 
        cin>> izquierda >> derecha; 
        cout<<"El maximo de "<<izquierda<<" y "<< derecha << " es: "<<query(0,n-1,0,izquierda,derecha).max<<endl;
    }

    update(0,n-1,0,5,8);
    cout<<"El maximo de "<<0<<" y "<< 6 << " es: "<<query(0,n-1,0,0,6).max<<endl;




    /* if('max' == consulta) {

    }*/
    return 0;
}
