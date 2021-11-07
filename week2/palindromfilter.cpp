//
// Created by serge on 11/3/2021.
//

#include <iostream>
#include <string>
#include <vector>

bool IsPalindrom(std::string s) {

    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength){
    std::vector<std::string> result{};

    for (auto& word: words){
        if (IsPalindrom(word) && word.size() >= minLength){
            result.push_back(word);
        }

    }

    return result;
}


int main(){
    auto a = PalindromFilter({"weew", "bro", "code"}, 4);

    for (auto& i : a){
        std::cout << i;
    }


    return 0;
}