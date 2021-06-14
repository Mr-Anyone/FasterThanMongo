#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include "../include/data.h"


static unsigned int SDBMHash(std::string str) {
    unsigned int hash = 0;
    unsigned int i = 0;
    unsigned int len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
    }

    return hash % 10000000;
}


static std::string get_data_dir(){
    std::string data_dir {};
    std::cout << "Where are the data located? " << std::endl;
    std::getline(std::cin, data_dir);
    return data_dir;
}
int main(){
    const std::string data_dir {get_data_dir()};
    Node* data {load_data(data_dir)};

    std::string query;
    while(true){
        std::cout << "Enter Query: ";
        std::getline(std::cin, query);
        std::cout << query;

        auto start = std::chrono::high_resolution_clock::now();
        int index = static_cast<int> (SDBMHash(query));
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;

        std::cout << "Fount in " << duration.count() * 1000 << " ms" << std::endl;
        data[index].print(query);
    }

}