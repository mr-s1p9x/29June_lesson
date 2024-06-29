#include <iostream>
#include <string>
using namespace std;

class Student {
    char* name;
    int age;
    friend class Test;   // Объявление дружественного класса

    class Vuz {  // Вложенный класс
        string Name;
    public:
        Vuz() : Name("Politex") {}  // Использование списков инициализации для простоты

        Vuz(const char* N) : Name(N) {}

        void Show() const {  // Добавление const к методу Show
            cout << Name << endl;
        }
    };

    Vuz vloj;  // Экземпляр вложенного класса

public:
    Student() : name(nullptr), age(0) {}  // Использование списков инициализации

    Student(const char* Name, int Age, const char* vuz) : age(Age), vloj(vuz) {
        name = new char[strlen(Name) + 1];
        strcpy(name, Name);
    }

    ~Student() {
        delete[] name;
        cout << "Destruct\n";
    }
};

class Test {
public:
    void Output_student(const Student& obj) {  // Использование ссылки на константу
        cout << "Name: " << obj.name << endl;
        cout << "Age: " << obj.age << endl;
        cout << "Vuz: ";
        obj.vloj.Show();
    }
};

int main() {
    Student obj1("Oleg", 21, "ITstep");
    Test obj;
    obj.Output_student(obj1);


    return 0;
}
