#include<iostream>

struct Node {
    int data;
    Node *next;
    Node(int _data) : data(_data),next(nullptr) {}
};

class LinkedList{
    private:
        Node *head;
    public:
        LinkedList() :  head(nullptr) {}

        void InsertAtBeginning(int value){
            Node *newNode =  new Node(value);
            newNode->next = head;
            head = newNode;
        }

        void InsertAtEnd(int value){
            Node *newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
            }
            else{
                Node *current = head;
                while(current->next != nullptr){
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        void InsertAtIndex(int index,int val){
            if(index < 0){
                std::cerr<<"Invalid posititon\n";
                return;
            }
            Node *newNode = new Node(val);
            if(head == nullptr){
                newNode->next = head;
                head = newNode;
            }
            Node *current = head;
            int temptPosition = 0;
            while(current != nullptr && temptPosition < index - 1){
                current = current->next;
                temptPosition++;
            }
            if(current == nullptr){
                std::cerr<<"Position out of bounds\n";
                delete newNode;
                return;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        void deleteAtBeginning(){
            if(head == nullptr){
                std::cerr<<"Failed to delete\n";
                return;
            }
            Node *tempt = head;
            head = head->next;
            delete tempt;
        }

        void deleteAtEnd(){
            if(head == nullptr){
                std::cerr<<"Failed to delete\n";
                return;
            }
            if(head->next == nullptr){
                std::cerr<<"Failed to delete\n";
                delete head;
                head = nullptr;
                return;
            }
            Node *current = head;
            Node *previous;
            while(current->next != nullptr){
                previous = current;
                current = current->next;
            }
            previous->next = nullptr;
            delete current;
        }

        void deleteAtIndex(int index){
            Node *current = head;
            Node *previous;
            int position = 0;
            while(current->next != nullptr && position < index){
                previous = current;
                current = current->next;
                position++;
            }
            previous->next = current->next;
            delete current;
        }
        int findValue(int val){
            Node *current = head;
            int index = 0;
            int ans = false;
            while(current != nullptr){
                if(current->data == val){
                    ans = true;
                    break;
                }
                current = current->next;
                index++;
            }
            if(ans){
                return index;
            }
            else{
                return -1;
            }
        }

        void display(){
            Node *current = head;
            while( current != nullptr){
                std::cout<<current->data<<" --> ";
                current = current->next;
            }
            std::cout<<"Null pointer\n";
        }
};

int main(){
    LinkedList myLinkedList;
    myLinkedList.InsertAtBeginning(55);
    myLinkedList.InsertAtBeginning(44);
    myLinkedList.InsertAtBeginning(77);
    myLinkedList.InsertAtEnd(100);
    myLinkedList.InsertAtEnd(500);
    myLinkedList.InsertAtIndex(1,888);
    myLinkedList.InsertAtBeginning(265);
    myLinkedList.display();
    myLinkedList.deleteAtBeginning();
    myLinkedList.display();
    myLinkedList.deleteAtIndex(2);
    myLinkedList.display();
    std::cout<<myLinkedList.findValue(999)<<std::endl;
    return 0;
}


