#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <Windows.h>



bool isUnique(const char* fileName, const unsigned char* word) {
    std::ifstream check(fileName);
    if (!check.is_open()) return true; // Åñëè ôàéëà åùå íåò, ñëîâî óíèêàëüíî

    char buffer[100];
    while (check >> buffer) {
        if (strcmp(buffer, (char*)word) == 0) {
            check.close();
            return false; // Íàøëè äóáëèêàò
        }
    }
    check.close();
    return true;
}
void to_lower(unsigned char *str){
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 192 && str[i] <= 223) { // À-ß
            str[i] = str[i] + 32;
        } else if (str[i] == 168) { // ¨
            str[i] = 184; // ¸
        }
    }
}
void removeH(unsigned char *str){
    to_lower(str);
    int len = strlen((char*)str);
    if (len == 0) return;

    int start = 0;
    while (str[start] != '\0') {
        unsigned char c = str[start];
        bool isOk = (c >= 224 && c <= 255) || (c == 184) || (c >= 48 && c <= 57);
        if (!isOk) start++;
        else break;
    }
    
    if (start > 0) {
        int i = 0;
        while (str[start] != '\0') {
            str[i++] = str[start++];
        }
        str[i] = '\0';
    }
    len = strlen((char*)str);
    int end = len - 1;
    while (end >= 0) {
        unsigned char c = str[end];
        bool isLetter = (c >= 224 && c <= 255) || (c == 184);
        if (!isLetter) {
            str[end] = '\0';
            end--;
        } else {
            break;
        }
    }
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
    unsigned char word[100];
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
    unsigned char word2[100];
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
    
    
    out.close();
    return 0;
}