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
        LinkedList() : head(nullptr) {}
        void insertAtBeginning(int _data){
            Node *newNode = new Node(_data);
            newNode->next = head;
            head = newNode;
        }
        void insertAtEnd(int data){
            Node *newNode = new Node(data);
            Node *current = head;
            if(head == nullptr){
                head = newNode;
            }
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
            newNode->next = nullptr;
        }
        void insertAtIndex(int index,int value){
            if(index < 0){
                std::cerr<<"Failed to insert\n";
                return;
            }
            Node *newNode = new Node(value);
            Node *current = head;
            if(index == 0){
                newNode->next = head;
                head = newNode;
                return;
            }
            int position = 0;
            while(current != nullptr && position < index-1){
                current = current->next;
                position++;
            }
            if(current == nullptr){
                std::cerr<<"Out of range\n";
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
                Node *tempt = head;
                delete tempt;
                head = nullptr;
            }
            Node *current = head;
            Node *previous;
            while(current->next != nullptr){
                previous = current;
                current = current->next;
            }
            delete current;
            previous->next = nullptr;
        }
        void deleteAtIndex(int index){
            if(index < 0){
                std::cerr<<"Failed to delete\n";
                return;
            }
            if(index == 0){
                Node *tempt = head;
                head = head->next;
                delete tempt;
                return;
            }
            Node *current = head;
            Node *previous;
            int position = 0;
            while(current != nullptr && position<index){
                previous = current;
                current = current->next;
                position++;
            }
            if(current == nullptr){
                std::cerr<<"Failed to delte because index is out of range\n";
                return;
            }
            previous->next = current->next;
            delete current;
        }
        bool FindValue(int value){
            if(head == nullptr){
                std::cerr<<"Linked List is empty\n";
                return false;
            }
            Node *current = head;
            while(current != nullptr){
                if(current->data == value){
                    return true;
                }
                current = current->next;
            }
            return false;
        }
        void display(){
            Node * current = head;
            while(current != nullptr){
                std::cout<<current->data<<"-->";
                current = current->next;
            }
            std::cout<<"Null ptr\n";
        }
        ~LinkedList(){
            Node *current = head;
            while(current != nullptr){
                Node *tempt = current->next;
                delete current;
                current = tempt;
            }
        }
};

int main(){
    LinkedList myLinkedList;
    myLinkedList.insertAtBeginning(100);
    myLinkedList.insertAtBeginning(200);
    myLinkedList.insertAtBeginning(300);
    myLinkedList.insertAtBeginning(500);
    myLinkedList.insertAtEnd(700);
    myLinkedList.insertAtEnd(800);
    myLinkedList.insertAtEnd(900);
    myLinkedList.display();
    myLinkedList.insertAtIndex(2,456);
    myLinkedList.insertAtIndex(3,488);
    myLinkedList.insertAtIndex(0,1913138);
    myLinkedList.display();
    myLinkedList.deleteAtBeginning();
    myLinkedList.deleteAtBeginning();
    myLinkedList.display();
    myLinkedList.deleteAtEnd();
    myLinkedList.deleteAtEnd();
    myLinkedList.display();
    myLinkedList.deleteAtIndex(2);
    myLinkedList.deleteAtIndex(0);
    myLinkedList.display();
    std::cout<<myLinkedList.FindValue(100)<<std::endl;
    return 0;
}