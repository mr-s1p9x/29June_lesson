#include <iostream>
#include <string>
using namespace std;

class Cond {
    string name;
public:
    Cond(const string& N = "Midea") : name(N) {}  // Упрощение конструкторов с использованием списка инициализации

    Cond(const Cond& obj) : name(obj.name) {}  // Использование списка инициализации в копирующем конструкторе

    void Show() const {
        cout << name << endl;
    }
};

class Engine {
    double w;
public:
    Engine(double d = 10000) : w(d) {}  // Упрощение конструкторов

    void Show() const {
        cout << "Engine w = " << w << endl;
    }
};

class Car {
    Cond *obj;  // Указатель на объект Cond
    int year;
    Engine a;   // Встраиваемый объект Engine
public:
    Car(Cond *x, double d, int y) : obj(x), a(d), year(y) {}  // Использование списка инициализации для всех полей

    void Show() {
        cout << year << endl;
        obj->Show();
        a.Show();
    }

    ~Car() {
        cout << "Destruct\n";
    }
};

int main() {
    Cond obj("Samsung");
    Car *ptr = new Car(&obj, 20000, 2018);
    ptr->Show();
    delete ptr;

    cout << "\n---- obj2 -------------------\n";
    Car new_obj(&obj, 12000, 1999);
    new_obj.Show();
}
