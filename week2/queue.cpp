//
// Created by serge on 11/4/2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>



void worry(std::vector<bool>& states, int i){

    states[i] = true;

}

void quite(std::vector<bool>& states, int i){

    states[i] = false;

}

void come(std::vector<bool>& states, int k){

    if(k > 0){
        for(int q = 0; q < k; q++)
        states.push_back(false);
    }
    else{
        states.resize(states.size() + k);
    }

}

void worry_count(const std::vector<bool>& states){
    int sum_of_elems = 0;
    for (int i = 0; i < states.size(); i++){
        if(states[i]){
            sum_of_elems += 1;
        }

    }


    std::cout << sum_of_elems << std::endl;

}




void ManageQueue(int& n_oper){
    std::vector<bool> states{};
    std::string command;
    std::map<std::string, int> mapping{{"WORRY", 0}, {"QUIET", 1},
                                       {"COME", 2}, {"WORRY_COUNT", 3}};

    int parameter;



    while(n_oper--){

        std::cin >> command;



        switch (mapping[command]){

            case 0:
                std::cin>>parameter;
                worry(states, parameter);
                break;

            case 1:
                std::cin>>parameter;
                quite(states, parameter);
                break;

            case 2:
                std::cin>>parameter;
                come(states, parameter);
                break;

            case 3:
                worry_count(states);
                break;
        }

    }





}

int main(){

    int Q;
    std::cin >> Q;

    ManageQueue(Q);



    return 0;
}