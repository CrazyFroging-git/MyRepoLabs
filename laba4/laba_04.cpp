#include <iostream>
#include <string>
using namespace std;

int main() {
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
        
}