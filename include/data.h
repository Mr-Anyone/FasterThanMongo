#ifndef FASTERTHANMONGO_DATA_H
#define FASTERTHANMONGO_DATA_H

#include <string_view>
#include <string>


constexpr int size {10000000};

class Node{
    std::string m_data;
    Node* m_next {nullptr};
public:
    bool m_initialized {false};
    void print();
    void print(const std::string& str);
    void insert(const std::string str);

    void init(const std::string& str, Node* next){
       m_data = str;
       m_next = next;
       m_initialized = true;
    }

    void init(const std::string str){
        m_data = str;
        m_initialized = true;
    }

};

Node* load_data(const std::string& data_dir);
#endif
