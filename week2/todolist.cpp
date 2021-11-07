//
// Created by serge on 11/4/2021.
//

#include <iostream>
#include <string>
#include <vector>

void Add(std::vector<std::vector<std::string>>& input,
        int day,
        std::string task){

    input[day - 1].push_back(task);

}

void Dump(std::vector<std::vector<std::string>>& input,
        int day){

    if( input[day - 1].size() > 0){
        std::cout <<input[day - 1].size()<< " ";
        for (auto& i: input[day - 1]){
            std::cout << i << " ";
        }

        std::cout << std::endl;

    }else{

        std::cout << 0 << std::endl;

    }

}

void Next(std::vector<std::vector<std::string>>& input,
        int num_days){

    if(num_days > input.size()){
        std::vector<std::vector<std::string>> tail{num_days - input.size(),
                                                   std::vector<std::string>{}
        };
        input.insert(input.end(),
                tail.begin(),
                tail.end());
    }
    else if(num_days < input.size()){

        for (int i = num_days; i < input.size(); i++){

            input[num_days - 1].insert(
                    input[num_days - 1].end(),
                    input[i].begin(), input[i].end()
                    );

        }

         input.resize(num_days);

    }

}

int main(){

    std::vector<int> months{31,28,31,30,31,30,31,31,30,31,30,31};
    int current_month = 0;
    std::vector<std::vector<std::string>> days{31,
                                               std::vector<std::string>{} };

    int Q;
    std::cin >> Q;


    while(Q--){
        std::string command;
        int day;
        std::string task;

        std::cin >> command;

        if(command =="ADD"){
            std::cin >> day >> task;
            Add(days, day, task);


        } else if (command == "NEXT"){


            ++current_month;
            current_month%=12;
            //std::cout<<"Month num: " << current_month << "Days: " <<  months[current_month];

            Next(days, months[current_month]);



        } else if (command == "DUMP"){

            std::cin >> day;
            Dump(days, day);
        }



    }



    return 0;
}