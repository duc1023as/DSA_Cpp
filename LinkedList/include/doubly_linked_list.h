#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

namespace doubly_linked_list
{
template<typename T>
struct node
{
    node<T>* next;
    node<T>* pre;
    T data;
    node(T value) : data{value}, next{nullptr}, pre{nullptr} {}
};

template<typename T>
class list
{
private:
    node<T>* head;
    node<T>* tail;
public:
    list() : head{nullptr}, tail{nullptr} {}

    ~list()
    {
        node<T>* current_node = head;
        while (current_node)
        {
            node<T>* tmp = current_node;
            current_node =  current_node->next;
            delete tmp;
        }
    }

    void insert_at_head(T data)
    {
        node<T>* new_node = new node(data);
        if(head == nullptr)
            head = tail = new_node;
        else
        {
            new_node->next = head;
            head->pre = new_node;
            head = new_node;
        }
    }

    void delete_at_head()
    {
        if(head == nullptr)
            throw std::runtime_error("List is empty to delete at head");
        node<T>* tmp = head;
        head = head->next;
        if(!head)
            tail = head;
        else
            head->pre = nullptr;
        delete tmp;
    }

    void insert_at_tail(T data)
    {
        node<T>* new_node = new node(data);
        if(head == nullptr)
            head = tail = new_node;
        else
        {
            tail->next = new_node;
            new_node->pre = tail;
            tail = new_node;
        }
    }

    void delete_at_tail()
    {
        if(head == nullptr)
            throw std::runtime_error("List is empty to delete at tail");
        node<T>* tmp = tail;
        tail = tail->pre;
        if(!tail)
            head = nullptr;
        else
            tail->next = nullptr;
        delete tmp;
    }

    void insert_at_index(int index, T data)
    {
        if(index < 0)
            throw std::runtime_error("Index is invalid");
        else if(!index)
            insert_at_head(data);
        else
        {
            node<T>* new_node = new node(data);
            node<T>* current_node = head;
            for(int i=0; i<index-1 && current_node != nullptr; i++)
            {
                current_node = current_node->next;
            }
            if(current_node == nullptr)
                throw std::out_of_range("Index is out of range to insert");
            new_node->next = current_node->next;
            new_node->pre = current_node;
            if(current_node->next != nullptr)
                current_node->next->pre = new_node;
            else
                tail = new_node;
            current_node->next = new_node;
        }
    }

    void delete_at_index(int index)
    {
        if(index < 0)
            throw std::runtime_error("Index is invalid");
        else if(head == nullptr)
            throw std::runtime_error("List is empty to delete");
        else if(!index)
            delete_at_head();
        else
        {
            // stop at index 
            node<T>* current_node = head;
            for(int i=0; i<index && current_node != nullptr; i++)
            {
                current_node = current_node->next;
            }
            if(current_node == nullptr)
                throw std::out_of_range("Index is out of range");
            node<T>* tmp = current_node;
            if(current_node->next == nullptr)
                tail = current_node->pre;
            else
                current_node->next->pre = current_node->pre;
            if(current_node->pre)
                current_node->pre->next = current_node->next;
            delete tmp;
            // stop at index -1
            // node<T>* current_node = head;
            // for(int i=0; i<index-1 && current_node != nullptr; i++)
            // {
            //     current_node = current_node->next;
            // }
            // if(current_node == nullptr || current_node->next == nullptr)
            //     throw std::out_of_range("Index is out of range");
            // node<T>* tmp = current_node->next;
            // if(current_node->next->next == nullptr)
            //     tail = current_node;
            // else
            //     current_node->next->next->pre = current_node;
            // current_node->next = current_node->next->next;
            // delete tmp;
        }
    }

    void print_forward()
    {
        node<T>* current = head;
        while (current)
        {
            std::cout << current->data << " === ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    void print_backward()
    {
        node<T>* current = tail;
        while (current)
        {
            std::cout << current->data << " === ";
            current = current->pre;
        }
        std::cout << "nullptr\n";
    }
};

}

#endif