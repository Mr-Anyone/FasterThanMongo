#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
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

void Node::print() {
    Node* next {this};

    while (true) {
        if (next->m_next){
            std::cout << next->m_data << std::endl;
            next = next->m_next;
        }else
            break;
    }
}

void Node::print(const std::string& query) {
    Node* next {this};
    while (true) {
        if (next->m_next) { // Not a null pointer
            std::cout << next->m_data << std::endl;
            next = next->m_next;
        }else
            break;
    }
}

void Node::insert(const std::string str){
    Node* insertStr {new Node};
    insertStr->init(str);
    if(this->m_next){ // Not a null pointer
        Node* tmp {this->m_next};
        this->m_next = insertStr;
        insertStr->m_next = tmp;
    } else{
        this->m_next = insertStr;
    }
}

std::string get_index(const std::string &data) {
    std::string str{};

    std::string::size_type previous{0};
    for (int i = 0; i < 2; ++i) {
        auto n{data.find(',', previous)};
        previous = n + 1;
    }

    std::string::size_type count{(data.find(',', previous + 1)) - previous};
    return data.substr(previous, count);
}

Node *load_data(const std::string& data_dir) {
    std::fstream csvFile;
    csvFile.open(data_dir, std::ios::in);
    assert(csvFile.is_open() && "Cannot open file or that the file does not exists");

    std::cout << "Read file: " << data_dir << std::endl;
    std::cout << "Made array with size: " << size << std::endl;
    Node *data{new Node[size]};

    // Loading data into RAM
    std::cout << "Starting to append data to ram" << std::endl;
    std::string row{};
    int count = 0;
    while (std::getline(csvFile, row)) {
        std::string index = get_index(row); // The index of the
        int arrayIndex = static_cast<int> (SDBMHash(index));

        // Insert or initialized
        if(data[arrayIndex].m_initialized)
            data[arrayIndex].insert(row);
        else
            data[arrayIndex].init(row);

        if (count % 100000 == 0)
            std::cout << "Appended: " << count << std::endl;

        ++count;
    }

    return data;
}