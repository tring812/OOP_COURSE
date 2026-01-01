#include <bits/stdc++.h>
using namespace std;

struct Time{
  int hour;
  int minute;
  int second;
};

void input(Time &a){
  cin >> a.hour >> a.minute >> a.second;
}
Time time_after(Time &a, Time &b){
  Time t;
  int second_sum = a.second + b.second;
  int minute_plus = second_sum / 60;
  t.second = second_sum % 60;

  int minute_sum = a.minute + b.minute + minute_plus;
  int hour_plus = minute_sum / 60;
  t.minute = minute_sum % 60;

  int hour_sum = a.hour + b.hour + hour_plus;
  t.hour = hour_sum % 24;
  return t;
}

int main(){
  Time a, b;
  cout << "Nhap thoi gian hien tai: ";
  input(a);

  cout << "Nhap thoi gian cong them: ";
  input(b);
  Time res = time_after(a, b);
  cout << "Thoi gian sau: ";
  cout << res.hour << ":" << res.minute << ":" << res.second;
}