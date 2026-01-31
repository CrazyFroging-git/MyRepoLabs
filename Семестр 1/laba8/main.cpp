#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Stop{
    int price;
    string name;
    Stop* next;
};

void printAll(Stop* head){
    int count = 0;
    Stop* p = head->next;
    while (p != nullptr){
        count++;
        cout << count << ". " << p->name <<": "<< p->price << "   ";
        p = p->next;    
    }
    cout << endl;
}

void print_oneElement(Stop* head, string name){
    Stop* p = head->next;
    int count = 0;
    while (p->next != nullptr){
        if (p->name == name){
            if (p->next == nullptr){
                count++;
                cout << "-------------------------" << endl;
                cout << "Название остановки-"<< endl << p->name << endl << "Эта остановка конечная" << endl;
                cout << "-------------------------" << endl;
            }
            else{
                count++;
                cout << "-------------------------" << endl;
                cout << "Название остановки-"<< p->name << endl << "Следующая остановка-"<< p->next->name << endl << "Цена до следующей остановки:"<< p->price << endl;
                cout << "-------------------------" << endl;
            }
            break;
        }
        p = p->next;    
    }
    if (count == 0){
        cout << "Такой остановки нет"<< endl;
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
void add1(Stop* head,int value, string name){
    Stop* z = make(value, name);
    Stop* p = head;
    while (p->next != nullptr){
        p = p->next;    
    }
    z->next = p->next;
    p->next = z;
}
// встраивается новый элемент value в конец
void add_back(Stop* head, int value, string name){
        Stop* z = make(value, name);
    Stop* p = head;
    while (p->next != nullptr){
        p = p->next;    
    }
    z->next = p->next;
    p->next = z;
    p->next->name = z->name;
    
    //p->tmp_price = z->tmp_price;
}
/*
Красная: Ялтинская улица, Королевские ворота, Площадь василевского, Пролетарская улица //37
Синяя: Рыбная деревня, Улица грига, Королевские ворота //40
Фиолетовая: Гостиница Калининград, Улица Черняховского, Улица Горького, Улица Ген. Лейт. Озерова //7
*/
void memory_clear(Stop* head){
    Stop* p = head;
    while (p != nullptr) {
        Stop* tmp = p->next;
        p->next = p->next->next;
        delete tmp; 
    }
}



int main(){
    int bufer1;
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string btr;
    string name;
    int pr;
    int button;
    Stop headR;
    headR.next = nullptr;
    Stop headB;
    headB.next = nullptr;
    Stop headV;
    headV.next = nullptr;
// заполнение веток начальными значениями
    // Красная ветка
    add_back(&headR, 20, "yalta");
    add_back(&headR, 40, "king");
    add_back(&headR, 18, "square");
    add_back(&headR, 12, "proletars");
    //Синяя ветка
    add_back(&headB, 21, "fish");
    add_back(&headB, 15, "greeg");
    add_back(&headB, 12, "king");
    //Фиолетовая ветка
    add_back(&headV, 24, "Hotel");
    add_back(&headV, 14, "chernakh");
    add_back(&headV, 13, "gorkogo");
    add_back(&headV, 89, "ozerova");


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
        cout << "4. Просмотр элементов остановки" << endl;
        cin >> bufer1;
        while ((typeid(bufer1).name()) != "int"){
            cout << "Введите корректное число" << endl;
            cin >> bufer1;
        button = bufer1;
        }
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
            cout << "Введите название остановки: ";
            cin >> name;
            cout << "Введите цену от прошлой остановки до этой: ";
            cin >> pr;
            cout << endl;
            switch (flag){
            case 1:
                add1(&headR, pr, name);
                break;
            case 2:
                add1(&headB, pr, name);
                break;
            case 3:
                add1(&headV, pr, name);
                break;
            }
            cout << "-------------------------" << endl;
            break;
        // просмотр конкретного элемента
        case 4:
            cout << "Введите название остановки, элементы котороый вы хотите просмотреть" << endl;
            cin >> btr;
            switch (flag){
            case 1:
                print_oneElement(&headR, btr);
                break;
            case 2:
                print_oneElement(&headB, btr);
                break;
            case 3:
                print_oneElement(&headV, btr);
                break;
            default:
                cout << "Ветка не выбрана, сначала выберите ветку" << endl;
                break;
            }
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