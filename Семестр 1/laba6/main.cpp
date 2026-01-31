#include <iostream>
using namespace std;


int global_count = 0;

//функция нахождения номеров столбцов нулей
/*int* get_zeros(int** matrix, int rows, int cols) {
    int* result = (int*)calloc(cols, sizeof(int));
    for (int j = 0; j < cols; j++){
        for (int i = 0; i < rows; i++){
            if (matrix[i][j] == 0){
                result[global_count] = j + 1;
                global_count++;
                break;
            }
        }
    }
    result = (int*)realloc(result, global_count * sizeof(int));
    return result;
    free(result);
}*/
int* get_zeros(int** matrix, int rows, int cols, int& count) {
    int* result = (int*)calloc(cols, sizeof(int));
    count = 0;
    
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                result[count] = j;
                count++;
                break;
            }
        }
    }
    
    // Изменяем размер массива под фактическое количество
    if (count > 0) {
        result = (int*)realloc(result, count * sizeof(int));
    } else {
        free(result);
        result = nullptr;
    }
    
    return result;
}
// функция сдвига
void arr_shift(int* arr, int cols, int shift_index) {
    for (int i = shift_index; i < cols - 1; i++) {
        arr[i] = arr[i + 1];
    }
}


// функция удаления столбцов
/*int** del_cols(int** matrix, int rows, int cols, int* zeros, int zeros_count) {
    if (zeros_count == 0) {
        return matrix;
    }
    // Сортируем индексы по убыванию (чтобы удалять с конца)
    for (int i = 0; i < zeros_count - 1; i++) {
        for (int j = i + 1; j < zeros_count; j++) {
            if (zeros[i] < zeros[j]) {
                int temp = zeros[i];
                zeros[i] = zeros[j];
                zeros[j] = temp;
            }
        }
    }
    
    // Удаляем столбцы
    for (int k = 0; k < zeros_count; k++) {
        int col_to_remove = zeros[k];
        for (int i = 0; i < rows; i++) {
            arr_shift(matrix[i], cols - k, col_to_remove);
        }
    }
    
    // Уменьшаем размер строк
    int new_cols = cols - zeros_count;
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)realloc(matrix[i], new_cols * sizeof(int));
    }
    
    return matrix;
} */


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int punkt;
    cout << "Введите номер пункта 1 или 2: " << endl;
    cin >> punkt;


    // выбор пункта
    if (punkt == 1){
        // пункт 1
        int rows = 2; // строка
        int cols = 2; // столбец
        
        // создается изначальный массив 2х2 
        int** arr = (int**)malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; ++i){
            arr[i] = (int*)malloc(cols * sizeof(int));
        }

        // вводятся данные
        int a = -1;
        int b = -1;
        int c;
        int d;


        cout << "Введите изначальную матрицу" << endl;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                cin >> arr[i][j];
            }
        }
        while ((arr[0][0] < 0) or (arr[0][1] < 0)) {
            cout << "Вы ввели число A или B < 0, повторите еще раз" << endl;
            for (int i = 0; i < rows; ++i){
                for (int j = 0; j < cols; ++j){
                    cin >> arr[i][j];
                }
            }
        }


        cout << "Матрица до всех преобразований: " << endl;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        // определяются новые размеры для массива
        int new_rows = rows + arr[0][0];
        int new_cols = cols + arr[0][1];

        // определяются коэфициенты для заполнения
        c = arr[1][0];
        d = arr[1][1];
        // расширяется массива на новые строки
        arr = (int**)realloc(arr, new_rows * sizeof(int*));

        // расширяются существующие столбцы до нового количества стобцов
        for (int i = 0; i < rows; i++) {
            arr[i] = (int*)realloc(arr[i], new_cols * sizeof(int));
            for (int j = cols; j < new_cols; j++) {
                arr[i][j] = ((i-1) * c) + ((j-1) * d);
            }
        }

        // создаются и инициализируются новые строки
        for (int i = rows; i < new_rows; i++) {
            arr[i] = (int*)malloc(new_cols * sizeof(int));
            for (int j = 0; j < new_cols; j ++){
                arr[i][j] = ((i-1) * c) + ((j-1) * d);
            }
        }
        
        
        // выводится массив после преобразования
        cout << "Увеличенная матрица: " << endl;
        rows = new_rows;
        cols  = new_cols;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Столбцы содержащие 0: ";
        // выводятся столбцы с 0
        int* result = get_zeros(arr, rows, cols, global_count);
        for (int i = 0; i < global_count; i++){
            cout << result[i] << " ";
        }
        cout << endl;
        // Сортируем индексы по убыванию (чтобы удалять с конца)
        for (int i = 0; i < global_count - 1; i++) {
            for (int j = i + 1; j < global_count; j++) {
                if (result[i] < result[j]) {
                    int temp = result[i];
                    result[i] = result[j];
                    result[j] = temp;
                }
            }
        }

        // Удаляем столбцы
        for (int k = 0; k < global_count; k++) {
            int col_to_remove = result[k];
            for (int i = 0; i < rows; i++) {
                arr_shift(arr[i], cols - k, col_to_remove);
            }
        }

        // Уменьшаем размер строк
        new_cols = cols - global_count;
        for (int i = 0; i < rows; i++) {
            arr[i] = (int*)realloc(arr[i], new_cols * sizeof(int));
        }

        // выводится матрица после удаления столбцов содержащих ноль
        cout << "Матрица после удаления столбцов содержащих 0: " << endl;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < (cols - global_count); ++j){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        // освобождение памяти
        for (int i = 0; i < rows; i++) {
            free(arr[i]);
        }
        free(arr);
    }
    else {
        cout << "Пункт 2" << endl;

        float a, b;
        cout << "Введите вещественное число a: ";
        cin >> a;
        cout << "Введите вещественное число b: ";
        cin >> b;

        float* pointer_a = new float(a);
        float* pointer_b = new float(b);

        *pointer_a = *pointer_a * 3; 

        float temp = *pointer_a;
        *pointer_a = *pointer_b;
        *pointer_b = temp;

        cout << "После всех операций: " << endl;
        cout << "a = " << *pointer_a << ", b = " << *pointer_b << endl;

        delete pointer_a;
        delete pointer_b;
    }
    return 0;
}