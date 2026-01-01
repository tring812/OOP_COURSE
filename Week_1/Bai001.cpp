#include <bits/stdc++.h>
using namespace std;

int t = 1;

struct PhanSo{
  int up;
  int down;
};
typedef PhanSo Ps;

bool valid(Ps a){
  if(a.down == 0) return false;
  return true;
}

void input(Ps &a, int t){
  while(true){
    cin >> a.up >> a.down;
    if(valid(a) == true)  break;
    else{
      cout << "Vui long nhap lai.\n";
      switch(t){
        case 1:
          cout << "Nhap tu, mau phan so thu nhat: "; break;
        case 2:
          cout << "Nhap tu, mau phan so thu hai: "; break;
      } 
    }
  }
}

int gcd(int a, int b){
  while(b != 0){
    int temp = a % b;
    a = b;
    b = temp;
  }
  return abs(a);
}

int lcm(int a, int b){
  return a * b/gcd(a, b);
}

void  optimizeP(Ps &a){
  int ucln = gcd(a.up, a.down);
  a.up /= ucln;
  a.down /= ucln;
  if(a.down < 0){
    a.up *= -1;
    a.down *= -1;
  }
}

Ps sum(Ps a, Ps b){
  Ps Sum;
  int tsc = lcm(a.down, b.down);
  int tich_a = tsc / a.down, tich_b = tsc / b.down;
  Sum.up = (a.up * tich_a) + (b.up * tich_b);
  Sum.down = tsc;
  return Sum;
}

Ps sub(Ps a, Ps b){
  Ps Sub;
  int tsc = lcm(a.down, b.down);
  int tich_a = tsc / a.down, tich_b = tsc / b.down;
  Sub.up = (a.up * tich_a) - (b.up * tich_b);
  Sub.down = tsc;
  return Sub;
}

Ps mul(Ps a, Ps b){
  Ps Mul;
  Mul.up = a.up * b.up;
  Mul.down = a.down * b.down;
  optimizeP(Mul);
  return Mul; 
}

Ps div(Ps a, Ps b){
  Ps Div;
  Div.up = a.up * b.down;
  Div.down = a.down * b.up;
  optimizeP(Div);
  return Div; 
}

int main(){
  Ps a, b;
  cout << "Nhap tu, mau phan so thu nhat: ";
  input(a, t); t++;
  cout << "Nhap tu, mau phan so thu hai: ";
  input(b, t);

  Ps tong = sum(a, b), hieu = sub(a, b), tich = mul(a, b), thuong = div(a, b);
  cout << "Tong 2 phan so = " << tong.up << "/" << tong.down << '\n';
  cout << "Hieu 2 phan so = " << hieu.up << "/" << hieu.down << '\n';
  cout << "Tich 2 phan so = " << tich.up << "/" << tich.down << '\n';
  cout << "Thuong 2 phan so = " << thuong.up << "/" << thuong.down << '\n';
}