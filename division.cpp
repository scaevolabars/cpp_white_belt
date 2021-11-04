//
// Created by serge on 11/2/2021.
//

#include <iostream>


void division(int& a, int& b){

    if (b == 0) {
        std::cout << "Impossible";
    } else{
        std::cout << a/b;
    }
}

int main(){

    int a, b;

    std::cin >> a;
    std::cin >> b;
    division(a,b);




    return 0;

}