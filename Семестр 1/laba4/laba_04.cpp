#include <iostream>
#include <string>
using namespace std;

int main() {
<<<<<<< HEAD
    int i;
    int j;
    int arr3v[6];
    for (i = 0; i != 6; i++) {
        cin >> arr3v[i];
    }
    int left;
    int right;
    bool count = 0;
    for (i = 0; i != 5; i++) {
        left = arr3v[i];
        right = arr3v[i + 1];
        if (left == right) {
            count = 1;
            break;
        }
    }
    if (count == 1) {
        for (i = 0; i != 6; i++) {
            for (j = 0; j != 5; j++) {
                if (arr3v[j] > arr3v[j + 1]) {
                    swap(arr3v[j + 1], arr3v[j]);
                }
            }
        }
    }   
    for (i = 0; i != 6; i++) {
        cout << arr3v[i] << " ";
    }
        
=======
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int i;
    int j;
    bool flag = false;
    int arr3v[6];
    for (i = 0; i != 6; i++){
        cin >> arr3v[i];
    }
    for (i = 0; i != 5; i++){
        if (arr3v[i] == arr3v[i + 1]) {
            flag = true;
        }
    }
    for (i = 0; i != 6; i++) {
        for (j = 0; j != 5; j++) {
            if ((arr3v[j] > arr3v[j + 1]) and flag == true) {
                swap(arr3v[j], arr3v[j + 1]);
            }
        }
    }
    for (i = 0; i != 6; i++){
        cout << arr3v[i] << " ";
    }
    cout << endl;
    cout << "---------------------"<< endl;
    int matrix[3][4];
    for (i = 0; i != 3; i++) {
            for (j = 0; j != 4; j++) {
                cin >> matrix[i][j];
        }
    }
    for (i = 0; i != 3; i++) {
            for (j = 0; j != 4; j++) {
                cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int sum_abs[3];
    for (i = 0; i != 3; i++) {
        for (j = 0; j != 4; j++) {
            sum_abs[i] += abs(matrix[i][j]);
        }
    }
    int buffer = 0;
    for (i = 0; i != 3; i++) {
        if (sum_abs[i] > buffer) {
            buffer = i;
        }
    }
    for (i = 0; i != 4; i++) {
        matrix[buffer][i] = 0;
    }
    cout << "------------------" << endl;
        for (i = 0; i != 3; i++) {
            for (j = 0; j != 4; j++) {
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
>>>>>>> be59f25cb587e6b78e5e8fa0812c9ba102450c22
}