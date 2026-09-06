#include <iostream>
#include <fstream>
#include <string>

int find_max (std::string line) {

    int maxIndex1 = 0;
    char maxDigit1 = '/';
    for (int i = 0; i < line.length() - 1; i++){
        if(line[i] > maxDigit1){
            maxDigit1 = line[i];
            maxIndex1 = i;
        }
        if(maxDigit1 == '9'){
            break;
        }
    }
    int first_index = line.find(maxDigit1);
    maxIndex1 = first_index;

    int maxIndex2 = maxIndex1 + 1;
    char maxDigit2 = line[line.length() - 1];
    for(int i = maxIndex2; i < line.length(); i++){
        if(line[i] > maxDigit2){
            maxDigit2 = line[i];
            maxIndex2 = i;
        }
        if(maxDigit2 == '9'){
            break;
        }
    }

    int maxDigitInt1 = maxDigit1 - '0';
    int maxDigitInt2 = maxDigit2 - '0';

    return maxDigitInt1*10 + maxDigitInt2;
    

}       



int main() {
    std::ifstream file("input.txt");
    if(!file) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    std::string line;

    int max;
    int sum = 0;
    while (std::getline(file, line)){
       max = find_max(line);
       sum += max;
    }
    std::cout << sum;
    return 0;
}
