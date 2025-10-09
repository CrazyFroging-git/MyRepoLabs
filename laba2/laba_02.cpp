#include <iostream>
#include <bitset>
using namespace std;


int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	short buffer;
	short num;
	int number1;
	int number2;
	int number_of_error;
	short number_bit_i;
	bool bit_of_i; 
	cout << "Введите число:  ";
    cin >> buffer;
	if ((buffer < SHRT_MIN) or (buffer > SHRT_MAX)){
        cout << "Вы ввели число, ненаходящееся в диапазоне short ";
        return 1;
    }
	num = buffer;
	bitset<8> num8 = num;
	cout << "Для числа " << num<< " первые 8 бит в 2 сс:  "<< num8 << endl;
	cout << "Введите номер бита:  ";
    cin >> number_bit_i;
	if ((number_bit_i > 7) or ((number_bit_i < 0))){
        cout << "Вы ввели номер бита больше 7 или меньше 0";
        return 1;
    }
	bit_of_i = (num >> number_bit_i) & 1;
    cout << "Значение бита под номером " << number_bit_i << ": " << bit_of_i << endl;
	if (bit_of_i != 0)
	{
		cout << "1-ое Число: ";
		cin >> number1;
		cout << "2-ое Число: ";
		cin >> number2;

		if ((number2 != 0) and (number1 % number2 == 0)) {
			cout << number1<< "/" << number2 << " = " << number1 / number2 << endl;
		}
		else if ((number1 != 0) and (number2 % number1 == 0)) {
			cout << number2 << "/" << number1 << " = " << number2 / number1 << endl;
		}
		else {
			cout << number1 << "*" << number2 << " = " << number1 * number2 << endl;
		}

	}
	else {
		num8 ^= (1 << number_bit_i + 1) | (1 << number_bit_i - 1);
		cout << "Измененное двоичное число: " << num8 << endl;
		cout << "Ищмененное десятичное число: " << num8.to_ullong() << endl;
	}
	cout << "Напишите номер ошибки" << endl;
	cin >> number_of_error;

	switch (number_of_error){
		case 1:
			cout << "Неисправность ЭБУ впрыска" << endl;break;
		case 2:
			cout << "Неисправность ДУТ" << endl;break;
		case 4:
			cout << "Повышенное напряжение" << endl;break;
		case 8:
			cout << "Пониженное напряжение" << endl;break;
		case 13:
			cout << "Отсутствует сигнал датчика кислорода" << endl;break;
		case 51:
			cout << "Неисправность работы ПЗУ" << endl;break;
		case 52:
			cout << "Неисправность работы ОЗУ" << endl;break;
		case 55:
			cout << "Слишком бедная смесь" << endl;break;
		case 61:
			cout << "Проблемы в датчике кислорода" << endl;break;
		default:
			cout << "Такой ошибки нет" << endl;break;
	}
	return 1;
}