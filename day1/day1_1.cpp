#include <iostream>
#include <fstream>
#include <string>

int INITIAL_DIAL = 50;

int point_zero = 0;

int moveRight (int curr, int num){
    if((curr + num) % 100 == 0){
        point_zero++;
        return 0;
    }
    if((curr + num) > 100){
        return curr + num - 100;
    } else{
        return curr + num;
    }
}

int moveLeft (int curr, int num){
    if((curr - num)%100 == 0){
        point_zero++;
        return 0;
    }
    if((curr - num) < 0){
        return curr - num + 100;
    } else{
        return curr - num;
    }
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