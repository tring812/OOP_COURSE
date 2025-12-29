#include <bits/stdc++.h>

using namespace std;

struct ds{
    char ID[9];
    char Name[21];
    char Role[11];
    int salary;
    int bonus;
    int income;
};

int main(){
    int n;
    cin >> n;
    ds a[100];
    int min_salary = 1e9;
    for(int i = 0;i < n;++i){
        cin >> a[i].ID;
        cin.getline(a[i].Name, 21);
        cin.getline(a[i].Role, 11);
        cin >> a[i].salary >> a[i].bonus;
        a[i].income = a[i].salary + a[i].bonus;
        min_salary = min(a[i].salary, min_salary);
    }
    //a
    long long sum = 0;
    for(int i = 0;i < n;++i){
        sum += a[i].income;
    }
    cout << "Tong thuc lanh thang cua cong ty: " << sum << '\n';
    //b
    cout << "Danh sach nhan vien co muc luong thap nhat: " << '\n';
    for(int i = 0;i < n;++i){
        if(a[i].salary == min_salary){
            cout << i + 1 << ". " << a[i].ID << " " << a[i].Name << " " << a[i].Role << " " << a[i].salary << '\n';
        }
    }
    //c
    cout << "Danh sach nhan vien co muc thuong >= 1200000: " << '\n';
    for(int i = 0;i < n;++i){
        if(a[i].bonus >= 1200000){
            cout << i + 1 << ". " << a[i].ID << " " << a[i].Name << " " << a[i].Role << " " << a[i].bonus << '\n';
        }
    }
    //d
    
}