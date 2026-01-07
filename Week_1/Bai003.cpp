#include <bits/stdc++.h>
using namespace std;

struct func{
  double a, b, c;
};
struct func4{
  double a, b, c, d, e;
};

void input(func &f){
  cin >> f.a >> f.b >> f.c;
}

void out(func f){
  cout << f.a << "x^2 + " << f.b << "x + " << f.c << '\n';
}
void out(func4 f){
  cout << f.a << "x^4 + " << f.b << "x^3 + " << f.c << "x^2 + " << f.d << "x + " << f.e << '\n';
}

func sum(func f1, func f2){
  func f3;
  f3.a = f1.a + f2.a;
  f3.b = f1.b + f2.b;
  f3.c = f1.c + f2.c;
  return f3;
}

func sub(func f1, func f2){
  func f3;
  f3.a = f1.a - f2.a;
  f3.b = f1.b - f2.b;
  f3.c = f1.c - f2.c;
  return f3;
}

func4 mul(func f1, func f2){
  func4 f3;
  f3.a = f1.a * f2.a;
  f3.b = (f1.a * f2.b) + (f1.b * f2.a);
  f3.c = (f1.b * f2.b) + (f1.a * f2.c) + (f2.a * f1.c);
  f3.d = (f1.b * f2.c) + (f1.c * f2.b);
  f3.e = f1.c * f2.c;
  return f3;
}

int main(){
  func f1, f2;
  cout << "Nhap he so da thuc thu nhat: "; input(f1);
  cout << "Nhap he so da thuc thu hai: "; input(f2);
  cout << "Tong 2 da thuc: "; out(sum(f1, f2));
  cout << "Hieu 2 da thuc: "; out(sub(f1, f2));
  cout << "Tich 2 da thuc: "; out(mul(f1, f2));
  cout << "Gia tri F1(0): " << f1.c << '\n';
  cout << "Gia tri F2(0): " << f2.c;
}