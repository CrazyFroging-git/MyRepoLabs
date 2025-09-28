#include <iostream>

int main() {
    std::cout << "unsigned short 16 min-0 max-" << pow(2, 16) - 1 << "\n";
    int max_int = pow(2, 31) - 1;
    std::cout << "int 32 min- " << -(max_int) - 1 << " max-" << max_int << "\n";
    unsigned short first_number; //unsigned, потому что нам дают неотрицательное число, следовательно отрицательные значения не будут поступать, а short потому что нет ограничения на ввод чисел нет 
    unsigned short second_number;
    std::cin >> first_number >> second_number;
    unsigned int result_prod; // unsigned int потому что два ансайгнед шорт в умножении поместятся сюда
    result_prod = first_number * second_number;
    std::cout << result_prod;
    //int result_sum = 
    
    return 0;
} 