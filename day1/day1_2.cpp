#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int INITIAL_DIAL = 50;

int point_zero = 0;

int moveRight (int curr, int num){
    
    int total = curr + num;

    point_zero += total / 100;

    return total % 100;
}

int moveLeft (int curr, int num){

    if(curr == 0){
        point_zero += num / 100;
    }
    else if(num >= curr){
        point_zero += 1;
        point_zero += (num - curr) / 100;
    }

    int total = curr - num;
    return (total % 100 + 100) % 100;

}

int main() {

    std::ifstream file("rotation.txt");
    if(!file.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std:: string line;
    int current_position =  INITIAL_DIAL;

    while (std::getline(file, line)){

        char direction = line[0];

        int num = std::stoi(line.substr(1)); 

        if(direction == 'L' || direction == 'l' ){
            current_position = moveLeft(current_position, num);

        }else if(direction == 'R' || direction == 'r' ){
            current_position = moveRight(current_position, num);
        }

    }
    std::cout << "The key is: " << point_zero << "\n";


}