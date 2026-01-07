#include <bits/stdc++.h>
using namespace std;

struct date{
  int day;
  int month;
  int year;
};

void input(date &a){
  cout << "Nhap ngay hien tai: ";
  cin >> a.day >> a.month >> a.year;
}

bool leap(date a){
  int x = a.year;
  if((x % 4 == 0 && x % 100) || x % 400 == 0) return 1;
  return 0;
}

int days(date a){
  if(a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11) return 30;
  if(a.month == 2)  return leap(a)? 29 : 28;
  return 31;
}

void days(date &a, int x){
  while(x--){
    a.day++;
    if(a.day > days(a)){
      a.month++;
      a.day = 1;
      if(a.month > 12){
        a.month = 1;
        a.year++;
      }
    }
  }
}

int main(){
  date a;
  int x;
  input(a);
  cout << "Nhap ngay cong them: ";  cin >> x;
  days(a, x);
  cout << "Ngay sau cung: " << a.day << '/' << a.month << '/' << a.year;
}