//
// Created by serge on 11/5/2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

void Change_capital(std::map <std::string, std::string>& gloss,
                    const std::string& country,
                    const std::string& new_capital){

    auto query = gloss.find(country);
    if(query == gloss.end()){
        gloss[country] = new_capital;
        std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
    }

    else if(query->second == new_capital){

        std::cout << "Country " << country << " hasn't changed its capital"<< std::endl;

    }

    else if(query->second != new_capital){

        std::cout << "Country " << country << " has changed its capital from "<< query->second
                  << " to " << new_capital << std::endl;

        gloss[country] = new_capital;


    }






}

void Rename_country(std::map <std::string, std::string>& gloss,
                    const std::string& old_country,
                    const std::string& new_country){

    auto query1 = gloss.find(old_country);
    auto query2 = gloss.find(new_country);

    if (old_country == new_country || query1 == gloss.end() || query2 != gloss.end()){

        std::cout << "Incorrect rename, skip" << std::endl;

    }
    else{

        std::string temp_cap = query1->second;
        gloss.erase(old_country);
        gloss[new_country] = temp_cap;

        std::cout << "Country " << old_country << " with capital " <<
        temp_cap << " has been renamed to " << new_country << std::endl;
    }


}



void About(const std::map <std::string, std::string>& gloss,
           const std::string& country){

    auto query = gloss.find(country);

    if(gloss.find(country) == gloss.end()){
        std::cout << "Country " << country << " doesn't exist" << std::endl;
    } else{
        std::cout << "Country " << country << " has capital " << query->second << std::endl;
    }


}


void Dump(const std::map <std::string, std::string>& gloss){

    if(gloss.empty()){
        std::cout << "There are no countries in the world" << std::endl;
    }else{
        for(auto& it: gloss){
            std::cout<< it.first<<"/"<<it.second << " ";
        }
    }

}


int main(){
    int Q;
    std::string command;
    std::string param1;
    std::string param2;

    std::map <std::string, std::string> mapping{};

    std::cin >> Q;

    while(Q--){

        std::cin >> command;

        if(command == "CHANGE_CAPITAL"){

            std::cin >> param1 >> param2;
            Change_capital(mapping, param1, param2);

        }

        else if(command == "RENAME"){

            std::cin >> param1 >> param2;
            Rename_country(mapping, param1, param2);


        }


        else if(command == "ABOUT"){

            std::cin >> param1;
            About(mapping, param1);

        }

        else if(command == "DUMP"){
            Dump(mapping);

        }


    }


    return 0;
}