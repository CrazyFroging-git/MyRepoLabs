#include <iostream>
/*
123
321
*/

int main() {
    std::cout << "unsigned short 16 min-0 max-" << pow(2, 16) - 1 << "\n";
    int max_int = pow(2, 31); // int, потому что нужно вывсети 
    unsigned int max_un_int = pow(2, 32) - 1;
    std::cout << "int 32 min- " << -(max_int) << " max-" << max_un_int << "\n";
    std::cout << "unsigned int 32 min-0 " << "max-" << max_int - 1 << "\n";
    unsigned short first_number; //unsigned, потому что нам дают неотрицательное число, следовательно отрицательные значения не будут поступать, а short потому что нет ограничения на ввод чисел нет 
    unsigned short second_number;
    std::cin >> first_number >> second_number;
    unsigned int result_prod; // unsigned int потому что два самые большие ансайгнед шорт в умножении поместятся в ансайгнед инт, а в обычный нет 
    result_prod = first_number * second_number;
    std::cout << "*: " << result_prod << std::endl;
    int result_sum = first_number + second_number;
    std::cout << "+: " << result_sum << std::endl;
    int result_div1 = first_number / second_number;
    int result_div2 = second_number / first_number;
    std::cout << "/: " << result_div1 << "  " << result_div2 << std::endl;
    int result_minus1 = first_number - second_number;
    int result_minus2 = second_number - first_number;
    std::cout << "-: " << result_minus1 << "  " << result_minus2 << std::endl;
    return 0;
} 