//
// Created by serge on 11/4/2021.
//

#include <iostream>
#include <vector>
int main(){

    int n;
    double sum = 0;
    std::cin >> n;

    std::vector<int> temp(n,0);
    std::vector<int> result{};
    int t;
    for(auto& a: temp){
        std::cin>>t;
        sum+=t;
        a=t;
    }
    sum/=n;

    for(int i=0; i<n; ++i){
        if(temp[i] > sum){
            result.push_back(i);
        }
    }

    std::cout << result.size() << std::endl;
    for(auto& r: result){
        std::cout << r << " ";
    }



    return 0;
}