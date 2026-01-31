#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int number_of_numbers;
    float buffer = 0;
    cout << "Введите количество чисел в последовательности ";
    cin >> number_of_numbers;
    float sum_of_numbers = 0;
    float max_number = -90;
    int index_of_max_number = -1;
    cin >> buffer;
    if ((-0.36 < buffer) && (buffer <= 10.1)) {
        max_number = buffer;
        index_of_max_number = 1;
    }
    
    for (int i = 1; i != number_of_numbers; i++) {
        cin >> buffer;
        if ((-0.36 < buffer) && (buffer <= 10.1)) {
            sum_of_numbers += buffer;
            if (buffer > max_number) {
                max_number = buffer;
                index_of_max_number = i;
                }
        }
    }
    if (index_of_max_number == -1) {
        cout << "Ни одно из чисел не находится в диапазоне (-0,36; 10,1]" << endl;
    }
    else {
        cout << "Максимальное число: " << max_number << endl;
        cout << "Номер максимального числа в последовательности: " << index_of_max_number << endl;
        cout << "Сумма чисел: " << sum_of_numbers << endl;
    }
    int number;
    cout << "Введите число по модулю не превышающее 1.000" << endl; cin >> number;
    number = abs(number);
    if (number > 1000){
        int prod = 1;
        if (number == 0) {
            prod = 0;
        }
        while (number != 0) {
            int x = number % 10;
            prod *= x;
            number /= 10;
        }
        cout << "Произведение цифр: " << prod << endl;
    }
    else {
        cout << "Вы ввели число по модулю больше 1.000" << endl;
    }
    return 1;
}