#include <iostream>


int main() {
    std::cout << "unsigned short 16 min-0 max-" << pow(2, 16) - 1 << "\n";
    std::cout << "int 32 min-" << (pow(2, 31)) << "max-" << pow(2, 31) - 1 << "\n";
    unsigned short first_number; //unsigned, потому что нам дают неотрицательное число, следовательно отрицательные значения не будут поступать, а short потому что нет ограничения на ввод чисел нет 
    unsigned short second_number;
    std::cin >> first_number >> second_number;
    unsigned int result_prod = first_number * second_number; // unsigned int потому что два ансайгнед шорт в умножении поместятся сюда
    std::cout << result_prod;
    //int result_sum = 
    
    return 0;
} 