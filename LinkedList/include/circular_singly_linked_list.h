#ifndef CIRCULAR_SINGLY_LINKED_LIST
#define CIRCULAR_SINGLY_LINKED_LIST

namespace csll
{
template<typename T>
struct node
{
    node* next;
    T data;
    node(T value) :  data{value}, next{nullptr} {}
};

template<typename T>
class list
{
private:
    node<T>* tail;
public:
    list() : tail{nullptr} {}

    ~list()
    {
        if(tail == nullptr)
            return;
        node<T>* current_node = tail->next;
        node<T>* head = tail->next;
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
        if(tail == nullptr)
        {
            tail = new_node;
            tail->next = tail;
        }
        else
        {
            new_node->next = tail->next;
            tail->next = new_node;
        }
    }

    void delete_at_head()
    {
        if(tail == nullptr)
            throw std::runtime_error("List is emptyp to delete");
        node<T>* head = tail->next;
        if(head == tail)
        {
            delete tail;
            tail = nullptr;
        }
        else
        {
            node<T>* tmp = head;
            tail->next = tmp->next;
            delete tmp;
        }
    }

    void insert_at_tail(T data)
    {
        node<T>* new_node = new node(data);
        if(tail == nullptr)
        {
            tail = new_node;
            tail->next = tail;
        }
        else
        {
            new_node->next = tail->next;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void delete_at_tail()
    {
        if(tail == nullptr)
            throw std::runtime_error("List is empty to delete at tail");
        node<T>* head = tail->next;
        if(head == tail)
        {
            delete head;
            tail = nullptr;
        }
        else
        {
            node<T>* current_node = head;
            while (current_node->next != tail)
                current_node = current_node->next;
            node<T>* tmp = tail;
            current_node->next = tail->next;
            tail = current_node;
            delete tmp;
        }
    }

    void insert_at_index(int index, T data)
    {
        if(index < 0)
            throw std::runtime_error("Index is invalid");
        if(!index)
            insert_at_head(data);
        else
        {
            if(tail == nullptr)
                throw std::out_of_range("Index is out of range");
            node<T>* head = tail->next;
            node<T>* new_node = new node(data);
            node<T>* current_node = head;
            if(index != 1)
            {
                current_node = current_node->next;
                for(int i=1; i<index-1 && current_node != head; i++)
                {
                    current_node = current_node->next;
                }
                if(current_node == head)
                    throw std::out_of_range("Index is out of range");
            }
            new_node->next = current_node->next;
            current_node->next = new_node; 
            if(current_node == tail)
                tail = new_node;

            // another implementation
            // Node* newNode = new Node(value);
            // Node* current = tail->next; // Start from head
            // int count = 0;

            // while (current != tail && count < index - 1) {
            //     current = current->next;
            //     count++;
            // }

            // if (count == index - 1) {
            //     newNode->next = current->next;
            //     current->next = newNode;

            //     // If inserted after the tail, update the tail
            //     if (current == tail) {
            //         tail = newNode;
            //     }
            // } else {
            //     cout << "Index out of bounds!" << endl;
            //     delete newNode;
            // }
        }
    }

    void delete_at_index(int index)
    {
        if(index < 0)
            throw std::runtime_error("Index is invalid");
        if(!index)
            delete_at_head();
        else
        {
            if(tail == nullptr)
                throw std::out_of_range("Index is out of range");
            node<T>* current_node = tail->next;
            node<T>* head = tail->next;
            if(index != 1)
            {
                current_node = current_node->next;
                for(int i=1; i<index-1 && current_node != head; i++)
                    current_node = current_node->next;
                if(current_node == head || current_node->next == head)
                    throw std::out_of_range("Index is out of range");
            }
            node<T>* tmp = current_node->next;
            current_node->next = current_node->next->next;
            if(tmp == tail)
                tail = current_node;
            delete tmp;
        }

        //another implementation
        // Node* current = tail->next; // Start from head
        // int count = 0;

        // while (current->next != tail->next && count < index - 1) {
        //     current = current->next;
        //     count++;
        // }

        // if (current->next == tail->next || count != index - 1) {
        //     cout << "Index out of bounds!" << endl;
        //     return;
        // }

        // Node* nodeToDelete = current->next;
        // current->next = nodeToDelete->next;

        // // If the deleted node is the tail, update the tail pointer
        // if (nodeToDelete == tail) {
        //     tail = current;
        // }

        // delete nodeToDelete;
    }

    void print_list()
    {
        if(tail == nullptr)
        {
            std::cout << "List is empty to display\n";
            return;
        }
        node<T>* current_node = tail->next;
        do
        {
            std::cout << current_node->data << " === ";
            current_node = current_node->next;
        } while (current_node != tail->next);
        std::cout << "Back to head node\n";
    }
};
}
#endif