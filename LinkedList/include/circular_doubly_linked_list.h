#ifndef CIRCULAR_DOUBLY_LINKED_LIST
#define CIRCULAR_DOUBLY_LINKED_LIST

//cdll stands for Circular doubly linked list
namespace cdll
{
template<typename T>
struct node
{
    node* next;
    node* pre;
    T data;
    node(T value) : data{value}, next{nullptr}, pre{nullptr} {}
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
        if(head == nullptr)
            return;
        node<T>* current_node = head;
        do
        {
            node<T>* tmp = current_node;
            current_node = current_node->next;
            delete tmp;
        } while (current_node != head);
    }

    void insert_at_head(T data)
    {
        node<T>* new_node = new node(data);
        if(head == nullptr)
        {
            head = new_node;
            new_node->next = new_node;
            new_node->pre = new_node;
        }
        else
        {
            node<T>* tail = head->pre;
            new_node->next = head;
            new_node->pre = tail;
            head->pre = new_node;
            tail->next = new_node;
            new_node = head;
        }
    }

    void delete_at_head()
    {
        if(head == nullptr)
            throw std::runtime_error("List is empty to delete");
        node<T>* tail = head->pre;
        node<T>* tmp = head;
        if(tail == head)
            head = nullptr;
        else
        {
            head = head->next;
            head->pre = tail;
            tail->next = head;
        }
        delete tmp;
    }

    void insert_at_tail(T data)
    {
        node<T>* new_node = new node(data);
        if(head == nullptr)
        {
            head = new_node;
            head->next = head;
            head->pre = head;
        }
        else
        {
            node<T>* tail = head->pre;
            tail->next = new_node;
            new_node->pre = tail;
            new_node->next = head;
            head->pre = new_node;
        }
    }

    void delet_at_tail()
    {
        if(head == nullptr)
            throw std::runtime_error("List is empty to delete");
        node<T>* tail = head->pre;
        if(tail == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            tail->pre->next = head;
            head->pre = tail->pre;
            delete tail;
        }
    }

    void insert_at_index(int index, T data)
    {
        if(index < 0)
            throw std::runtime_error("Index is invalid");
        if(index == 0)
            insert_at_head(data);
        else
        {
            node<T>* new_node = new node(data);
            node<T>* current_node = head;
            if(index != 1)
            {
                current_node = head->next;
                for(int i=1; i<index-1 && current_node != head; i++)            
                {
                    current_node = current_node->next;
                }
                if(current_node == head)
                    throw std::out_of_range("Index is out of range");
            }
            new_node->next = current_node->next;
            new_node->pre = current_node;
            current_node->next->pre = new_node;
            current_node->next = new_node;
        }
    }

    void delete_at_index(int index)
    {
        if(head == nullptr)
            throw std::runtime_error("List is empty to delete");
        if(index < 0)
            throw std::runtime_error("Index is invalid");
        if(!index)
            delete_at_head();
        else
        {
            node<T>* current_node = head->next;
            for(int i=1; i<index && current_node != head; i++)
            {
                current_node = current_node->next;
            }
            if(current_node == head)
                throw std::runtime_error("Index is out of range");
            node<T>* tmp = current_node;
            current_node->pre->next = current_node->next;
            current_node->next->pre = current_node->pre;
            delete tmp;
        }
    }

    void print_forward()
    {
        if(head == nullptr)
        {
            std::cout << "List is empty to display\n";
            return;
        }
        node<T>* current_node = head;
        do
        {
            std::cout << current_node->data << " === ";
            current_node = current_node->next;
        } while (current_node != head);
        std::cout << "back to head\n";
    }
    
    void print_backward()
    {
        if(head == nullptr)
        {
            std::cout << "List is empty to display\n";
            return;
        }
        node<T>* current_node = head->pre;
        do
        {
            std::cout << current_node->data << " === ";
            current_node = current_node->pre;
        } while (current_node != head->pre);
        std::cout << "back to tail\n";
    }
};

}

#endif