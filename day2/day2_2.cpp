#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <set>


int main() {
    FILE* file = std::fopen("ids.txt", "r");

    if(!file) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    long long sum = 0;
    long long first, second;

    while (std::fscanf(file, "%lld-%lld,", &first, &second) == 2) {

        std::set<long long> invalidIDs;

        for (long long i = 1; ; i++) {

            std::string s = std::to_string(i);

            std::string wrong_number_string = s + s;

            while (wrong_number_string.length() <= std::to_string(second).length()) {

                long long wrong_number = std::stoll(wrong_number_string);

                if (wrong_number > second) break;

                if (wrong_number >= first) {
                    invalidIDs.insert(wrong_number);
                }

                wrong_number_string += s;
            }

            if (std::stoll(s + s) > second) {
                break;
            }
        }
        for (long long id : invalidIDs) {
            sum += id;
        }
    }

    std::cout << "the sum is " << sum << "\n";

    std::fclose(file);
}
