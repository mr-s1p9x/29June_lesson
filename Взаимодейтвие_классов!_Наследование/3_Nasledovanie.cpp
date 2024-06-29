#include <iostream>       // Подключение стандартной библиотеки ввода-вывода
#include <cstring>        // Библиотека для работы со строками стиля C
#include <unistd.h>       // Библиотека для использования функции sleep
using namespace std;      // Использование стандартного пространства имен

class Human {             // Определение базового класса Human
protected:
    char* name;           // Защищенный член для имени
    int age;              // Защищенный член для возраста

public:
    Human() : name(nullptr), age(0) {   // Конструктор по умолчанию
        cout << "Construct Human\n";    // Сообщение о конструировании объекта
    }
    Human(const char* Name, int Age) : age(Age) {   // Конструктор с параметрами
        name = new char[strlen(Name) + 1];          // Выделение памяти под имя
        strcpy(name, Name);                         // Копирование имени
        cout << "Construct Human\n";                // Сообщение о конструировании
    }
    virtual ~Human() {                              // Виртуальный деструктор
        delete[] name;                              // Освобождение памяти имени
        cout << "Destruct Human\n";                 // Сообщение о разрушении
        sleep(1);                                   // Задержка в 1 секунду
    }
    void Output_Human() const {                     // Метод вывода информации о человеке
        cout << "Output Human\nName: " << name << "\nAge: " << age << "\n\n";
    }
};

class Student : public Human {                      // Класс Student, наследующий Human
    char* Univer;                                   // Указатель на строку университета
    double Scholarship;                             // Поле стипендии

public:
    Student() : Human(), Univer(nullptr), Scholarship(0) {   // Конструктор по умолчанию
        cout << "Construct Student\n";                       // Сообщение о конструировании
        age = 12;                                             // Прямое присваивание возраста
    }
    Student(const char* n, int a, const char* U, double S) : Human(n, a), Scholarship(S) {   // Параметризованный конструктор
        Univer = new char[strlen(U) + 1];                                                  // Выделение памяти для университета
        strcpy(Univer, U);                                                                  // Копирование названия университета
        cout << "Construct Student\n";                                                      // Сообщение о конструировании
    }
    ~Student() {                                                                            // Деструктор
        delete[] Univer;                                                                    // Освобождение памяти университета
        cout << "Destruct Student\n";                                                       // Сообщение о разрушении
        sleep(1);                                                                           // Задержка в 1 секунду
    }
    void Output() {                                                                         // Метод вывода информации о студенте
        cout << "Output Student\n";
        Output_Human();                                                                     // Вызов базового метода вывода
        cout << "University: " << Univer << "\nScholarship: " << Scholarship << "\n\n";
    }
};

class Teacher : public Human {                                  // Класс Teacher, наследующий Human
    char* school;                                               // Указатель на строку школы
    char* subject;                                              // Указатель на строку предмета
    double salary;                                              // Зарплата

public:
    Teacher(const char* n, int a, const char* sch, const char* subj, double sal) : Human(n, a), salary(sal) {   // Конструктор
        school = new char[strlen(sch) + 1];                        // Выделение памяти под школу
        strcpy(school, sch);                                        // Копирование названия школы
        subject = new char[strlen(subj) + 1];                       // Выделение памяти под предмет
        strcpy(subject, subj);                                      // Копирование названия предмета
        cout << "Construct Teacher\n";                              // Сообщение о конструировании
    }

    ~Teacher() {                                                    // Деструктор класса Teacher
        delete[] school;                                            // Освобождение памяти, выделенной для школы
        delete[] subject;                                           // Освобождение памяти, выделенной для предмета
        cout << "Destruct Teacher\n";                               // Сообщение о разрушении объекта
    }

    void Output() {                                                 // Метод для вывода информации о преподавателе
        Output_Human();                                             // Вызов метода базового класса для вывода общей информации
        cout << "School: " << school << "\nSubject: " << subject << "\nSalary: " << salary << "\n\n";
    }
};

class Doctor : public Human {                                      // Класс Doctor, наследующий Human
    char* hospital;                                                // Указатель на строку больницы
    char* speciality;                                              // Указатель на строку специальности
    double salary;                                                 // Зарплата

public:
    Doctor (const char* n, int a, const char* hosp, const char* spec, double sal) : Human(n, a), salary(sal) {  // Конструктор
        hospital = new char[strlen(hosp) + 1];                      // Выделение памяти под больницу
        strcpy(hospital, hosp);                                     // Копирование названия больницы
        speciality = new char[strlen(spec) + 1];                    // Выделение памяти под специальность
        strcpy(speciality, spec);                                   // Копирование названия специальности
        cout << "Construct Doctor\n";                               // Сообщение о конструировании
    }

    ~Doctor() {                                                     // Деструктор класса Doctor
        delete[] hospital;                                          // Освобождение памяти, выделенной для больницы
        delete[] speciality;                                        // Освобождение памяти, выделенной для специальности
        cout << "Destruct doctor\n";                                // Сообщение о разрушении объекта
    }

    void Output() {                                                 // Метод для вывода информации о докторе
        Output_Human();                                             // Вызов метода базового класса для вывода общей информации
        cout << "Hospital: " << hospital << "\nSpeciality: " << speciality << "\nSalary: " << salary << "\n\n";
    }
};

int main() {                                                        // Главная функция программы
    Student a("Oleg", 19, "Itstep", 2000);                          // Создание объекта класса Student
    a.Output();                                                     // Вывод информации о студенте

    Teacher tch("Anna", 34, "High School", "Biology", 50000);       // Создание объекта класса Teacher
    tch.Output();                                                   // Вывод информации о преподавателе

    Doctor doc("Denis", 30, "Central Hospital", "Doctor", 70000);   // Создание объекта класса Doctor
    doc.Output();                                                   // Вывод информации о докторе
}
