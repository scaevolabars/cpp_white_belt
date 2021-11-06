//
// Created by serge on 11/6/2021.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

void new_buses(std::map<std::string, std::vector<std::string>>& input, std::string &bus_num ,std::vector<std::string>& stops){

    input[bus_num] = stops;

};

std::vector<std::string> collect_buses(const std::map<std::string, std::vector<std::string>>& input,
        const std::vector<std::string> &order,
        const std::string &stop){
    std::vector<std::string> buses{};

    for (auto &b: order) {
        if (std::find(input.at(b).begin(), input.at(b).end(), stop) != input.at(b).end()) {
            buses.push_back(b);
        }
    }

    return buses;
}


void buses_for_stop( const std::map<std::string, std::vector<std::string>>& input, const std::vector<std::string> &order ,const std::string &stop) {

    std::vector<std::string> buses = collect_buses(input, order, stop);

    if (buses.empty()) {

        std::cout << "No stop" << std::endl;

    } else {

        for (auto& b: buses){

            std::cout << b << " ";

        }
        std::cout<<std::endl;

    }

}


void stops_for_bus(const std::map<std::string, std::vector<std::string>>& input,
        const std::vector<std::string> &order,
        const std::string &bus){

    if (input.find(bus) == input.end()){
        std::cout << "No bus" << std::endl;
        return;
    }

    auto& stops = input.at(bus);

    for (auto& s: stops){
        std::cout<<"Stop "<< s << ": ";

        auto buses = collect_buses(input, order, s);

        if (buses.size() == 1){
            std::cout << "no interchange" << std::endl;

        }else{

            for (auto& b: buses){
                if(b!=bus){


                    if (&b != &buses.back()){
                        std::cout <<b << " ";
                    } else{
                        std::cout <<b;
                    }
                }

            }

            std::cout << std::endl;

        }



    }


}

void all_buses(const std::map<std::string, std::vector<std::string>>& input){

    if(input.empty()){
        std::cout<< "No buses"<<std::endl;
    }else{

        for(auto& item: input){

            std::cout<< "Bus " << item.first << ": ";;

            for(auto& st: item.second){
                std::cout << st << " ";
            }
            std::cout<<std::endl;

        }

    }
}


int main(){
    
    int Q = 0;
    std::string bus_num;
    int bus_q = 0;
    std::string stop;
    std::vector<std::string> stop_vec{};
    std::vector<std::string> bus_vec{};
    std::string command;
    std::map<std::string, std::vector<std::string>> bus_stops{};

    std::cin >> Q;

    while (Q--){
        std::cin >> command;
        if (command == "NEW_BUS"){
            std::cin>>bus_num;
            std::cin>>bus_q;
            stop_vec = {};
            bus_vec.push_back(bus_num);

            while(bus_q--){
                std::cin>> stop;
                stop_vec.push_back(stop);
            }
            new_buses(bus_stops, bus_num, stop_vec);

        } else if (command == "BUSES_FOR_STOP"){
            std::cin>> stop;
            buses_for_stop(bus_stops, bus_vec, stop);

        } else if (command == "STOPS_FOR_BUS"){
            std::cin>>bus_num;
            stops_for_bus(bus_stops, bus_vec, bus_num);

        } else if (command == "ALL_BUSES"){

            all_buses(bus_stops);

        }

    }



    return 0;
}
