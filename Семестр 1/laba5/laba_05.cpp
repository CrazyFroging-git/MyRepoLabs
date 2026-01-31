#include <iostream>
using namespace std;

void dva(int a, int b) {
	cout << "Используется функция вычисления попарной сумм, разности, произведения, частного" << endl; 
	int raznost2= b - a;
	int prod = a * b; 
    int summ = a + b; 
	int raznost1 = a - b; 
	float div1 = static_cast<float>(a) / b; 
	float div2 = static_cast<float>(b) / a;
	cout << "a + b = " << summ << endl;
	cout << "a - b = " << raznost1 << endl;
	cout << "b - a = " << raznost2 << endl;
	cout << "a * b = " << prod << endl;
	cout << "a / b = " << div1 << endl;
	cout << "b / a = " << div2 << endl;
}


int pereg(int number1, int number2){
    cout << "Используется функция деления, если числа кратны, в противном умножение" << endl;
    int buffer;
    if ((number2 != 0) and (number1 % number2 == 0)) {
			buffer = static_cast<float>(number1) / number2;
            cout << number1 << " / " << number2 << " = ";
		}
		else if ((number1 != 0) and (number2 % number1 == 0)) {
			buffer = static_cast<float>(number2) / number1;
            cout << number2 << " / " << number1 << " = ";
		}
		else {
            cout << number1 << " * " << number2 << " = ";
			buffer = number1 * number2;
		}
    return buffer;
}
int pereg(int number1, int number2, int number3){
    if ((number1 == number2) and (number1 == number2)) {
        return 1;
    }
    return -1;
}
void pervi(){
    cout << "Используется функция для первого пункта" << endl;
    int a[3];
    cout << "Введите 3 числа" << endl;
    for (int i = 0; i < 3; i++){
        cin >> a[i];
    }
    if ((a[0] != 0) and (a[1] != 0) and (a[2] != 0)) {
		cout << pereg(a[0], a[1], a[2]) << endl;
	}
	else if ((a[0] != 0) and (a[1] != 0) and (a[2] == 0)) {
		cout << pereg(a[0], a[1]) << endl;
	}
	else if ((a[0] != 0) and (a[1] == 0) and (a[2] != 0)) {
		cout << pereg(a[0], a[2]) << endl;
	}
	else if ((a[0] == 0) and (a[1] != 0) and (a[2] != 0)) {
		cout << pereg(a[2], a[1]) << endl;
	}
	else {
		cout << "Вы ввели одно число" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int punkt;
    cout << "Введите номер пункта: ";
    cin >> punkt;
    if (punkt == 1){
        pervi();
    }
    else if (punkt == 2){
        int num1;
        int num2;
        cin >> num1, num2;
        dva(num1, num2);
    }
    
    return 1;
}