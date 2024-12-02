#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

namespace singly_linked_list
{
template<typename T>
struct node
{
    node* next;
    T data;
    node(T _data) : next{nullptr}, data{_data} {}
};

template<typename T>
class list
{
private:
    node<T>* head;
public:
    list() : head{nullptr} {}

    ~list()
    {
        node<T>* current_node = head;
        while (current_node)
        {
            node<T>* tmp = current_node;
            current_node = current_node->next;
            delete tmp;
        }
    }

    // Time complexity: O(1), Space complexity: O(1)
    void insert_at_head(T data)
    {
        node<T>* new_node = new node(data);
        new_node->next = head;
        head = new_node;
    }

    // Time complexity: O(1), Space complexity: O(1)
    void delete_at_head()
    {
        if(head == nullptr)
            throw std::runtime_error("List is empty to delete at head");
        node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }

    // Time complexity: O(n), Space complexity: O(1)
    void insert_at_tail(T data)
    {
        node<T>* new_node = new node(data);
        if(head == nullptr)
        {
            head = new_node;
            return;
        }
        node<T>* current_node = head;
        while (current_node->next != nullptr)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    // Time complexity: O(n), Space complexity: O(1)
    void delete_at_tail()
    {
        if(head == nullptr)
            throw std::runtime_error("List is empty to delete at tail");
        else if(head->next == nullptr)
            delete_at_head();
        else
        {
            node<T>* current_node = head;
            while (current_node->next != nullptr && current_node->next->next != nullptr)
            {
                current_node = current_node->next;
            }
            node<T>* tmp = current_node->next;
            current_node->next = nullptr;
            delete tmp;
        }
    }

    // Time complexity: O(k), Space complexity: O(1)
    void insert_at_index(int index, T data)
    {
        if(index < 0)
            throw std::out_of_range("Invalid index to insert");
        else if(!index)
            insert_at_head(data);
        else
        {
            node<T>* current_node = head;
            node<T>* new_node = new node(data);
            for(int i=0; i<index-1 && current_node != nullptr; i++)
            {
                current_node = current_node->next;
            }
            if(current_node == nullptr)
                throw std::out_of_range("Index is out of range to insert");
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
    }

    // Time complexity: O(k), Space complexity: O(1)
    void delete_at_index(int index)
    {
        if(index < 0)
            throw std::runtime_error("Index is invalid index to delete");
        else if(head == nullptr)
            throw std::runtime_error("List is empty to delete");
        else if(!index)
            delete_at_head();
        else
        {
            node<T>* current_node = head;
            for(int i=0; i<index-1 && current_node != nullptr; i++)
            {
                current_node = current_node->next;
            }
            if(current_node == nullptr || current_node->next == nullptr)
                throw std::out_of_range("Index is out of range to delete");
            node<T>* tmp = current_node->next;
            current_node->next = current_node->next->next;
            delete tmp;
        }
    }

    // Time complexity: O(n), Space complexity: O(1)
    void print_list()
    {
        node<T>* current_node = head;
        while (current_node)
        {
            std::cout << current_node->data << " === ";
            current_node = current_node->next;
        }
        std::cout << "nullptr\n";
    }
};
}
#endif