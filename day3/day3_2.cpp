#include <iostream>
#include <fstream>
#include <string>

long long find_max(std::string line) {

    int total = 12;
    int start = 0;

    std::string answer = "";

    for (int i = 0; i < total; i++) {

        int remaining = total - i - 1;
        int end = line.length() - remaining;

        char maxDigit = '0';
        int maxIndex = start;

        for (int j = start; j < end; j++) {
            if (line[j] > maxDigit) {
                maxDigit = line[j];
                maxIndex = j;
            }
        }

        answer += maxDigit;
        start = maxIndex + 1;
    }

    return std::stoll(answer);
}

int main() {
    std::ifstream file("input.txt");
    if(!file) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    std::string line;

    long long  max;
    long long sum = 0;
    while (std::getline(file, line)){
       max = find_max(line);
       sum += max;
    }
    std::cout << sum;
    return 0;
}
