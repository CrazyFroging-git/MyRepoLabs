#include <vector>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <iostream>
using namespace std;

void PrintArr(const array<int, 10>& arr){
    for (int i = 0; i < arr.size(); ++i) {
        if (i == arr.size() - 1) {
            cout << arr[i];
        }
        else{
            cout << arr[i] << " ";
        }
    }
}

void PrintVec(const vector<int>& vec){
    cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
        if (i == vec.size() - 1) {
            cout << vec[i];
        }
        else{
            cout << vec[i] << " ";
        }
    }
    cout << "]" << endl;
}
void ValueSort(array<int, 10> arr) {       
    sort(arr.begin(), arr.end());
    cout << "Во время функции:  " << endl;
    for (int x : arr) cout << x << " ";
}

void ReferenceSort(array<int, 10> &arr) {
    sort(arr.begin(), arr.end());
    cout << "Во время функции:  " << endl;
    for (int x : arr) cout << x << " ";
}

void PointerSort(array<int, 10> *arr) {
    sort((*arr).begin(), (*arr).end());
    reverse((*arr).begin(), (*arr).end());
    cout << "Во время функции:  " << endl;
    for (int x : *arr) cout << x << " ";
}

void SearchIndex(const vector<int>& vec, int number){
    cout << "[";
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] == number){
            if (i == vec.size() - 1) {
                cout << i;
            }
            else{
                cout << i << " ";
            }
        }
    }
    cout << "]" << endl;
}

int count_index(const vector<int>& vec, int number){
    int x = 0;
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] == number){
            x++;
        }
    }
    return x;
}

void punkt6(vector<int>& vec){
    int max_value = vec[0];
    PrintVec(vec);
    
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > max_value) {
            max_value = vec[i];
        }
    }
    if (count_index(vec, max_value) > 1){
        vec.erase(remove(vec.begin(), vec.end(), max_value), vec.end());
        vec.push_back(max_value);
    }
    else if (count_index(vec, max_value) == 1){
        vec.insert(vec.begin(), max_value);
    }
    PrintVec(vec);
}

void punkt2(){
    array<int, 10> parr;
    for (int i = 0; i < 10; i++) {
        parr[i] = std::rand() % 21 - 10;
    }
    cout << "Исходный массив: ";
    PrintArr(parr);
    cout << endl;

    
    cout << "До сортировки по значению:    ";
    PrintArr(parr);
    cout << "     ";
    ValueSort(parr);
    cout << "После сортировки по значению: ";
    PrintArr(parr);
    cout << endl;
    
    cout << "До сортировки по ссылке:    ";
    PrintArr(parr);
    cout << "    ";
    ReferenceSort(parr);
    cout << "После сортировки по ссылке:    ";
    PrintArr(parr);
    cout << endl;

    cout << "До сортировки по указателю:    ";
    PrintArr(parr);
    cout << "    ";
    PointerSort(&parr);
    cout << "После сортировки по указателю:    ";
    PrintArr(parr);
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int count = 0;
    int flag;
    int bufer;
    vector<int> Vec;
    while (true){
        cout << "--------------------------" << endl; 
        cout << "0. Выход." << endl;
        cout << "1. Просмотр массива." << endl;
        cout << "2. Добавить элемент в начало." << endl;
        cout << "3. Добавить элемент в конец." << endl;
        cout << "4. Очистка всего массива." << endl;
        cout << "5. Поиск элемента в массиве." << endl;
        cout << "6. Задание варианта." << endl;
        cout << "72. Пункт 2." << endl;
        cin >> flag;
        switch(flag){
            case 0: break; break;
            case 1: if (Vec.empty()){
                cout << "[]" << endl;
            }
            else{
                PrintVec(Vec);
            }
            break;
            case 2: cin >> bufer;
            Vec.insert(Vec.begin(), bufer); break;
            case 3: cin >> bufer;
            Vec.push_back(bufer); break;
            case 4: Vec.clear(); break;
            case 5: cin >> bufer;
            SearchIndex(Vec, bufer); break;
            case 6: punkt6(Vec); break;
            case 72: punkt2(); break;
        }
    }

    return 0;
}