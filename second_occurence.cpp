//
// Created by serge on 11/2/2021.
//
#include <iostream>
#include <string>
int main(){
    int a = -2;
    std::string str = "";
    std::cin >> str;


    for(int i = 0; i < str.size(); ++i){
        if (str[i] == 'f'){
            a++;
        }

        if (a == 0){

            std:: cout << i;
            break;

        }



    }


    switch (a){

        case -1 : std::cout << a;
            break;

        case -2 : std::cout << a;
    }





    return 0;
}
