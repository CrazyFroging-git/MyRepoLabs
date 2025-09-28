#include <iostream>


int main() {
    unsigned short first_number; //unsigned, потому что нам дают неотрицательное число, следовательно отрицательные значения не будут поступать, а short потому что нет ограничения на ввод чисел нет 
    unsigned short second_number;
    unsigned int result_of_prod; // unsigned int потому что два ансайгнед шорт могут 
    std::cout << "unsigned short "<< "16 " << "min-0 " << "max-" << pow(2, 16) - 1;
    std::cin >> first_number >> second_number;
    
    return 0;
} 