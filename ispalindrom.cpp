//
// Created by serge on 11/3/2021.
//

//
// Created by serge on 11/3/2021.
//

#include <iostream>
#include <string>
bool IsPalindrom(string s) {

    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}


int main(){

    std::cout << IsPalindrom("X");

    return 0;
}