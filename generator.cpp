#include <iostream>
#include<sstream>
#include<string>
#include<cmath>
#include<ctime>

int random(int low, int high){
    return low + (std::rand() % (high - low + 1));
}

std::string generateUUID(){
    int myList[16];

    std::srand (std::time (0));

    // Generate random numbers j such that 0 <= j <= 255;
    for (int i=0; i<16; i++){
        int j = random(0,255);
        myList[i] = j;
    }

    std::stringstream sstream;
    for (int i = 0; i <16; i++){
        if (i==4 || i == 6 || i == 8 || i == 10 ){
            sstream << "-";
        }
        if (myList[i] < 16){
            sstream << 0;
        }
        sstream << std::hex << myList[i];
    }
    std::string r = sstream.str();

    return r;
}

int main(){
    std::string r = generateUUID();
    std::cout << r << std::endl;

    return 0;
}