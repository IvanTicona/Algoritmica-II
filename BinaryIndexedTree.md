# Binary Indexed Tree

### Ideas basicas
1. En lugar de Segment Tree, Binary Indexed Tree (BIT) es más fácil de implementar. Una forma de verlo es que BIT es solo una forma de comprimir Segment Tree. Es extremadamente eficiente en términos de espacio y tiempo. Especialmente útil cuando se necesita actualizar un rango de elementos y consultar un rango de elementos.
2. Funcion $LSOne(x)$ = $x \& -x$. Esta función devuelve el valor de la posición menos significativa que contiene un 1 en la representación binaria de $x$.
3. El Fenwick Tree esta indexado por bits de sus índices. Para obtener el padre de un nodo, se elimina el bit menos significativo de su índice. Para obtener el siguiente nodo, se agrega el bit menos significativo a su índice.
4. Un item $i$ en el BIT es responsable de los elementos $[i-LSOne(i)+1, i]$. Si $f$ es el array de frecuencias, entonces $ft[i]$ almacena la frecuencia acumulativa de ${i-LSOne(i)+1, i-LSOne(i)+2, i-LSOne(i)+3, ... ,i}$ de $f$.

5. Operation $rsq(j)$ $O(log n)$ queremos la frecuencia acumulativa de los elementos de $1$ a $j$. Podemos sumar $ft[j]$ y $ft[padre(j)]$ y seguir sumando hasta que $j = 0$. $Padre(j) = j - LSOne(j)$. Ej: $rsq(6) = ft[6] + ft[4] + ft[0]$
6. Un entero $j$ solo tiene $log(j)$ bits, por lo que $rsq(j)$ es $O(log m)$ donde $m$ es el valor máximo de $j$.
7. Los indices $6$, $4$ y $0$ estan relacionado por su forma binaria $j = 110$, $j' = 100$ y $j'' = 000$.