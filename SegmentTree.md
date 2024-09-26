# Segment Tree

Problema

7 | 3 | 2 | 1 | 8 | 7 | 6 | 0
    x           y

Hallar la suma de x hasta y
Sumas acumuladas

Uno extra al comienzo para el index x-1
0 | 7 | 10 | 12 | 13 | 21 | 28 | 34 | 34

suma -> v[y] - v[x-1]

Arbol Binario

MONOIDE

1. Conjunto S
2. Asociatividad
3. Neutro

Para implementar un Segment Tree en codigo se necesita la siguiente estructura

```cpp
struct SegmentTree {
    vector<int> st;
    int n;

    SegmentTree(int n) : n(n) {
        st.resize(4*n);
    }

    void build(int id, int l, int r, vector<int> &v) {
        if (l == r) {
            st[id] = v[l];
            return;
        }
        int m = (l+r)/2;
        build(2*id, l, m, v);
        build(2*id+1, m+1, r, v);
        st[id] = st[2*id] + st[2*id+1];
    }

    void build(vector<int> &v) {
        build(1, 0, n-1, v);
    }

    int query(int id, int l, int r, int x, int y) {
        if (x <= l && r <= y) return st[id];
        if (r < x || y < l) return 0;
        int m = (l+r)/2;
        return query(2*id, l, m, x, y) + query(2*id+1, m+1, r, x, y);
    }

    int query(int x, int y) {
        return query(1, 0, n-1, x, y);
    }

    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            st[id] = val;
            return;
        }
        int m = (l+r)/2;
        if (pos <= m) update(2*id, l, m, pos, val);
        else update(2*id+1, m+1, r, pos, val);
        st[id] = st[2*id] + st[2*id+1];
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }
};
```