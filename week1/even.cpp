#include <iostream>//
// Created by serge on 11/2/2021.
//

int main(){
    int a;
    std::cin >> a;
    for( int i = 1 ; i < a; ++i){
        if (i % 2 == 0) std :: cout << i;
    }

    return 0;

}