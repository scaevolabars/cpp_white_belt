//
// Created by serge on 11/3/2021.
//

#include <iostream>

int Factorial(int f){
    if (f <= 0){
        return 1;
    }
    else{
        int res = 1;
        while(f > 0){res*=f--;}
        return res;
    }
}

int main(){

    std::cout << Factorial(3);

    return 0;
}