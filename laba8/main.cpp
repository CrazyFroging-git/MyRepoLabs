#include <iostream>
#include <string>
using namespace std;

struct Stop{
    int price;
    string name;
    string next_stop;
    Stop* next;
};

void printAll(Stop* head){
    int count = 0;
    Stop* p = head->next;
    while (p != nullptr){
        count++;
        cout << count << "." << p->name << "   ";
        p = p->next;    
    }
    cout << endl;
}

void print(Stop* head){
    Stop* p = head->next;
    while (p != nullptr){
        cout << p->name << " ";
        p = p->next;    
    }
}
// выделяет кусок памяти для нового элемента value
Stop* make(int value, string name){
    Stop* p = new Stop;
    p->price = value;
    p->name = name;
    return p;
}
// встраивает новый элемент value
void add(Stop* head,int value, string name){
    Stop* z = make(value, name);
    z->next = head->next;
    head->next = z;
}
// встраивается новый элемент value в конец
void add_back(Stop* head,int value, string name){
    Stop* z = make(value, name);
    Stop* p = head;
    while (p->next != nullptr){
        p = p->next;    
    }
    z->next = p->next;
    p->next = z;
}
/*
Красная: Ялтинская улица, Королевские ворота, Площадь василевского, Пролетарская улица //37
Синяя: Рыбная деревня, Улица грига, Королевские ворота //40
Фиолетовая: Гостиница Калининград, Улица Черняховского, Улица Горького, Улица Ген. Лейт. Озерова //7


*/
int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int button;
    Stop headR;
    headR.next = nullptr;
    Stop headB;
    headB.next = nullptr;
    Stop headV;
    headV.next = nullptr;
// заполнение веток начальными значениями
    // Красная ветка
    add_back(&headR, 20, "Ялтинская улица");
    add_back(&headR, 40, "Королевские ворота");
    add_back(&headR, 18, "Площадь василевского");
    add_back(&headR, 12, "Пролетарская улица");
    //Синяя ветка
    add_back(&headB, 21, "Рыбная деревня");
    add_back(&headB, 15, "Улица грига");
    add_back(&headB, 40, "Королевские ворота");
    //Фиолетовая ветка
    add_back(&headV, 24, "Гостиница Калининград");
    add_back(&headV, 14, "Улица Черняховского");
    add_back(&headV, 13, "Улица Горького");
    add_back(&headV, 20, "Улица Ген. Лейт. Озерова");


    unsigned bufer;
    char flag = 0;
    while (true) {
        switch (flag){
        case 1:
            cout << "Текущая ветка красная" << endl;
            break;
        case 2:
            cout << "Текущая ветка синяя" << endl;
            break;
        case 3:
            cout << "Текущая ветка фиолетовая" << endl;
            break;
        default:
            cout << "Текущая ветка не выбрана" << endl;
            break;
        }

        cout << "1. Поменять ветку" << endl;
        cout << "2. Вывод всех существующих остановок" << endl;
        cout << "3. Добавить в текущую ветку остановку" << endl;
        cin >> button;
        switch (button){
    // поменять ветку
        case 1:
            cout << "-------------------------" << endl;
            cout << "Существующие ветки: 1-Красная, 2-Синяя, 3-Фиолетовая" << endl;
            cout << "Введите чиcло для измения ветки" << endl;
            cin >> bufer;
            switch (bufer){
            case 1:
                flag = 1;
                break;
            case 2:
                flag = 2;
                break;
            case 3:
                flag = 3;
                break;
            default:
                cout << "Такой ветки не существует" << endl;
                break;
            }
            cout << "-------------------------" << endl;
            break;
    // вывод всех остановок ветки
        case 2:
            cout << "-------------------------" << endl;
            switch (flag){
            case 1:
                printAll(&headR);
                break;
            case 2:
                printAll(&headB);
                break;
            case 3:
                printAll(&headV);
                break;
            }
            cout << "-------------------------" << endl;
            break;
    // добавить в текущую ветку остановку
        case 3:
            cout << "-------------------------" << endl;
            cout << button << endl;
            cout << "-------------------------" << endl;
            break;
        default:
            cout << "-------------------------" << endl;
            cout << "Такого пункта нет, введите еще раз" << endl;
            cout << "-------------------------" << endl;
            break;
        }
    }
    //123
}