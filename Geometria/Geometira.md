# Geometria Computacional

Poligono convexo mas pequenio que englobe todos los puntos

Suma de puntos
P(x1, y1) + Q(x2, y2) = R(x1 + x2, y1 + y2)

Resta de puntos
P(x1, y1) - Q(x2, y2) = R(x1 - x2, y1 - y2)

Producto un Punto por un escalar
a * P(x, y) = R(a * x, a * y)

Division de un Punto por un escalar
P(x, y) / a = R(x / a, y / a)

V = AB = (B - A)
Con las operaciones entre puntos podemos tener dos interpretaciones
Por ejemplo si multiplicamos un punto por un escalar, podemos interpretar estamos extendiendo el vector o estamos moviendo el punto

h = atan2(y, x) = sqrt(x^2 + y^2)

Hallar el vector unitario = Va / ||Va||
||Va|| = sqrt(x^2 + y^2)

Producto Vectorial
A = (x1, y1) B = (x2, y2)
A x B = x1 * y2 - x2 * y1
Product punto
A . B = x1 * x2 + y1 * y2

Para saber si dos vectores son perpendiculares
A x B = 0

Para saber si dos vectores son paralelos
A x B = 0

Para saber si un punto esta a la derecha de un vector
A x B > 0

Interseccion de rectas

P = (x, y) = A + AB * t

t = CB*CA / CD*BA


```
struct Point{
    double x, y;

    Point(){}
    Point(double a, double b){
      x = a;
      y = b;
    }
    
    Point operator-(const Point &p, const Point &q){
        return Point(p.x - q.x, p.y - q.y);
    }

    Point operator+(const Point &p, const Point &q){
        return Point(p.x + q.x, p.y + q.y);
    }

    Point operator*(const Point &p, double k){
        return Point(p.x * k, p.y * k);
    }   

    double cross(const Point &p) const{
        return x * p.y - y * p.x;
    }
    double dot(const Point &p) const{
        return x * p.x + y * p.y;
    }
    double norm() const{
        return sqrt(x * x + y * y);
    }
    bool operator<(const Point &p) const{
        return x < p.x || (x == p.x && y < p.y);
    }
}
```

```
double cross(const Vector &a, const Vector &b){
    return a.x * b.y - a.y * b.x;
}

Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D){
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}
```

Punto Segmento 

Para que un punto este en un segmento, el producto punto entre el vector que se forma
entre el punto y el inicio del segmento y el vector que se forma entre el punto y el 
final del segmento debe ser igual a 0

```
bool pointInSegment(const Point &A, const Point &B, const Point &P){
    return abs(area(A, B, P)) < EPS &&
              P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
              P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y);
}
```

Interseccion de Segmentos

Para que dos segmentos se intersequen, el producto cruz entre los vectores que se forman
entre los puntos de los segmentos debe ser diferente de 0

```
bool intersects(const Point &A, const Point &B, const Point &C, const Point &D){
    double A1 = area(C, D, A);
    double A2 = area(C, D, B);
    double A3 = area(A, B, C);
    double A4 = area(A, B, D);

    if(((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) && 
       ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))){
        return true;
    }

    else if(A1 == 0 && onSegment(C, D, A)) return true;
    else if(A2 == 0 && onSegment(C, D, B)) return true;
    else if(A3 == 0 && onSegment(A, B, C)) return true;
    else if(A4 == 0 && onSegment(A, B, D)) return true;

    else return false;
}
```


Poligonos convexos y no convexos

```
bool isConvex(const vector<Point> &P){
    int n = P.size(), left = false, right = false;

    for(int i = 0; i < n; i++){
        double A = area(P[i], P[(i + 1) % n], P[(i + 2) % n]);
        if(A > 0) left++;
        else if(A < 0) right++;
    }

    return left == 0 || right == 0;
}
```


Area de Poligonos

```
double area(const vector<Point> &P){
    double result = 0.0;
    for(int i = 0; i < P.size(); i++){
        result += P[i].cross(P[(i + 1) % P.size()]);
    }
    return abs(result) / 2.0;
}
```

Convex Hull

