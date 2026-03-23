#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <algorithm>


bool isUnique(std::string* arr, std::string word, int size) {
    for (int i = 0; i < size; i++){
        if (arr[i] == word){
            return true;
        }
    }
    return false;
}
void to_lower(std::string& s) {
    for (char& c : s) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (uc >= 192 && uc <= 223)      
            c = static_cast<char>(uc + 32);
        else if (uc == 168)              
            c = 184;                     
    }
}

bool isGoodStart(unsigned char c) {
    return (c >= 224 && c <= 255) || c == 184 || (c >= '0' && c <= '9');
}

bool isRussianLetter(unsigned char c) {
    return (c >= 224 && c <= 255) || c == 184;
}
void removeH(std::string& s) {
    to_lower(s);
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), isGoodStart));
    s.erase(std::find_if(s.rbegin(), s.rend(), isRussianLetter).base(), s.end());
}



void printHeader() {
    std::cout << std::setw(10) << "Áóêâà" << " | " << std::setw(5) << "Êîä" << "   ";
    std::cout << std::setw(10) << "Áóêâà" << " | " << std::setw(5) << "Êîä" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

void printRange(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; ++i) {
        unsigned char c = static_cast<unsigned char>(i);
        std::cout << std::setw(10) << c << " | " << std::setw(5) << i << "   ";
        
        count++;
        if (count % 2 == 0){ 
            std::cout << std::endl;
        }
    }
    if (count % 2 != 0){
        std::cout << std::endl;
    }
}
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    std::cout << "=== ÖÈÔÐÛ ===" << std::endl;
    printHeader();
    printRange(48, 57); // 0-9

    std::cout << "\n=== ÀÍÃËÈÉÑÊÈÉ ÀËÔÀÂÈÒ (A-Z, a-z) ===" << std::endl;
    printHeader();
    printRange(65, 90);  // A-Z
    printRange(97, 122); // a-z

    std::cout << "\n=== ÇÍÀÊÈ ÏÐÅÏÈÍÀÍÈß ===" << std::endl;
    printHeader();
    printRange(33, 47); // ! " # $ % & ' ( ) * + , - . /
    printRange(58, 63); // : ; < = > ? 

    std::cout << "\n=== ÐÓÑÑÊÈÉ ÀËÔÀÂÈÒ (À-ß, à-ÿ) ===" << std::endl;
    printHeader();
    std::cout << std::setw(10) << (unsigned char)168 << " | " << std::setw(5) << 168 << "   ";
    std::cout << std::setw(10) << (unsigned char)184 << " | " << std::setw(5) << 184 << std::endl;
    printRange(192, 255);

    std::ifstream in1("..\\..\\input.txt");
    if (!in1.is_open()){
        std::cout << "File not open" << std::endl;
        return -1;
    }
    unsigned char str[101];
    in1.getline((char*)str, 101);
    in1.close();
    unsigned char vowels[] = "àå¸èîóúûüýþÿ";
    for (int i = 0; str[i] != '\0'; i++){
        for (int j = 0; vowels[j] != '\0'; j++){
            if (str[i] == vowels[j]){
                if (str[i] == 184){ // ¨
                    str[i] = 168; // ¸
                } else{
                    str[i] = str[i] - 32;
                }
                break;
            }
        }
    }
    std::ofstream out1("..\\..\\output.txt");
    out1 << str;
    out1.close();


    std::ifstream in2("..\\..\\input1.txt");
    if (!in2.is_open()){
        std::cout << "File not open" << std::endl;
        return -1;
    }
    int N;
    int s = 0;
    std::string word;
    unsigned char targetLetter;
    if (!(in2 >> N)) {
        std::cout << "Íå óäàëîñü ñ÷èòàòü ÷èñëî N" << std::endl;
        return -1;
    }
    if (!(in2 >> targetLetter)) {
        std::cout << "Íå óäàëîñü ñ÷èòàòü áóêâó" << std::endl;
        return -1;
    }
    std::cout << "Ñ÷èòàíî ÷èñëî N: " << N << std::endl;
    std::cout << "Ñ÷èòàíà áóêâà: " << targetLetter << std::endl;
    /*
    while(in2 >> word){
        removeH(word);
        int len = strlen((char*)word);
        if (word[len - 1] == targetLetter){
            if (isUnique("..\\..\\text.txt", word) == 1){
                std::ofstream outText("..\\..\\text.txt", std::ios::app);
                outText << word << "\n";
                outText.close();
            }
        }
    }*/
    int size = N;
    std::string* arr = new std::string[size];
    while(in2 >> word){
        removeH(word);
        int len = word.length();
        if (word[len - 1] == targetLetter){
            if (isUnique(arr, word, size)){
                arr->append(word);
            }
        }
    }



    
    in2.close();
    std::ifstream intext("..\\..\\text.txt");
    unsigned char bufer[100];
    int count = 0;
    int min_len = 10000;
    int len_bufer;
    while (intext >> bufer){
        len_bufer = strlen((char*)bufer);
        if (min_len > len_bufer){
            min_len = len_bufer;
            count = 1;
        } else if (min_len == len_bufer){
            count++;
        }
    }

    std::ofstream out("..\\..\\output2.txt");
    while (N > 0 && min_len < 100){
        std::ifstream text("..\\..\\text.txt");
        while (text >> bufer){
            if (strlen((char*)bufer) == min_len && N > 0){
                out << bufer << "\n";
                N--;
            }
        }
        min_len++;
        text.close();
    }
    std::sort(arrs.begin())
    
    out.close();














    return 0;
}