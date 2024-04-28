#include <iostream>
#include <string>
#include <vector>


std::string s = "abcd";
std::vector<int> indices = {0, 2};
std::vector<std::string> sources = {"a","cd"};
std::vector<std::string> targets = {"eee","ffff"};


int main()
{   
    int flag = 0;
    for(int i = 0; i < indices.size(); i++){
        if(sources[i] == s[indices[i]]){

        }
    }

    
    return 0;
}