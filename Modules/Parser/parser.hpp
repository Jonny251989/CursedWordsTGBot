#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>
#include <boost/algorithm/string.hpp>



class Parser{

    private:
        std::vector<std::string> arguments;
        std::unordered_map<std::string, std::string> tokens;

    public:

    Parser(const std::vector<std::string>&&list){
        arguments = std::move(list);
        for(auto riter = list.rbegin(); riter != list.rend(); ++ riter)
            tokens[*riter];
    }

    std::vector<std::string> getArguments(){
        return arguments;
    };

    std::unordered_map<std::string, std::string> getTokens(){
        return tokens;
    };


    void remove_spaces(std::string& str){
   
        size_t start = 0, end = 0;

        while((start = str.find_first_of(' ', end)) != std::string::npos){

            start = start + 1;
            end = str.find_first_not_of(' ', start);
            
            if(end - start  >= 1){
                str.erase(start, end-start);
                end = start;
            }         
        }
    }

    std::unordered_map<std::string, std::string> parsing_string(std::string str){

        this->remove_spaces(str);

        size_t start = 0, end = 0;
        std::vector<std::string> v_args;

        while((start = str.find_first_not_of(' ', end)) != std::string::npos){
            
            end = str.find(' ', start);
            v_args.push_back(str.substr(start, end - start));
        };

        std::set<std::string> s_str { "-number", "-list", "-token"};

        for(size_t i = 0; i < v_args.size(); ++i){

            if( !(i%2)){

                if (std::find(arguments.begin(), arguments.end(), v_args[i]) == arguments.end())
                    throw std::invalid_argument("Error's token! It must have the tokens:");

            }  
            else{

                if(std::find(arguments.begin(), arguments.end(),v_args[i]) == arguments.end())
                    tokens[v_args[i - 1]] = v_args[i];
                else
                    throw std::invalid_argument("Error's token! It must have the tokens:");     
            }   
        }
        return tokens;
    }
};