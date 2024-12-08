#include "linked_list.h"
#include <iostream>
#include <iomanip>
#include <string>


namespace linked_list
{
void list::test_singly_linked_list()
{
    try
    {
    #if 0
        std::cout << std::string(5,'=') << " HEAD SECTION IN SINGLY LINKED LIST " << std::string(5,'=') << "\n";
        singly_linked_list.insert_at_head(100);
        singly_linked_list.insert_at_head(200);
        singly_linked_list.insert_at_head(300);
        singly_linked_list.print_list();
        singly_linked_list.delete_at_head();
        singly_linked_list.delete_at_head();
        singly_linked_list.delete_at_head();
        singly_linked_list.delete_at_head();
        singly_linked_list.print_list();
        singly_linked_list.insert_at_head(500);
        singly_linked_list.print_list();
        singly_linked_list.delete_at_head();
        singly_linked_list.print_list();
    #endif
    #if 0 
        std::cout << std::string(5,'=') << " TAIL SECTION IN SINGLY LINKED LIST " << std::string(5,'=') << "\n";
        singly_linked_list.insert_at_tail(100);
        singly_linked_list.insert_at_tail(200);
        singly_linked_list.insert_at_tail(300);
        singly_linked_list.insert_at_tail(400);
        singly_linked_list.print_list();
        singly_linked_list.delete_at_tail();
        singly_linked_list.delete_at_head();
        singly_linked_list.delete_at_head();
        singly_linked_list.delete_at_head();
        singly_linked_list.print_list();
        singly_linked_list.delete_at_head();
        singly_linked_list.delete_at_tail();
        singly_linked_list.insert_at_tail(400);
        singly_linked_list.print_list();
        singly_linked_list.delete_at_tail();
        singly_linked_list.print_list();
    #endif
    #if 1
        std::cout << std::string(5,'=') << " INDEX SECTION IN SINGLY LINKED LIST " << std::string(5,'=') << "\n";
        singly_linked_list.insert_at_index(0, 123);
        singly_linked_list.insert_at_index(1, 126);
        singly_linked_list.insert_at_index(2, 1233);
        singly_linked_list.insert_at_index(3, 12356);
        singly_linked_list.insert_at_index(4, 12356);
        singly_linked_list.print_list();
        singly_linked_list.delete_at_index(1);
        singly_linked_list.print_list();
        singly_linked_list.delete_at_index(2);
        singly_linked_list.print_list();
        singly_linked_list.delete_at_index(2);
        singly_linked_list.print_list();
        singly_linked_list.delete_at_index(1);
        singly_linked_list.delete_at_index(0);
        singly_linked_list.print_list();
    #endif
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void list::test_doubly_linked_list()
{
    try
    {
    #if 1
        doubly_linked_list.insert_at_head(10000);
        doubly_linked_list.insert_at_head(20000);
        doubly_linked_list.insert_at_head(30000);
        doubly_linked_list.insert_at_head(40000);
        doubly_linked_list.print_forward();
        doubly_linked_list.delete_at_head();
        doubly_linked_list.print_forward();
    #endif
    #if 0
        doubly_linked_list.insert_at_tail(2315);
        doubly_linked_list.insert_at_tail(897263);
        doubly_linked_list.insert_at_tail(12023);
        doubly_linked_list.insert_at_tail(5547);
        doubly_linked_list.insert_at_tail(63215);
        doubly_linked_list.print_forward();
        doubly_linked_list.delete_at_tail();
        doubly_linked_list.delete_at_tail();
        doubly_linked_list.delete_at_tail();
        doubly_linked_list.print_forward();
        doubly_linked_list.delete_at_tail();
        doubly_linked_list.delete_at_tail();
        doubly_linked_list.print_forward();
        doubly_linked_list.insert_at_tail(63215);
        doubly_linked_list.print_backward();
    #endif
    #if 0
        doubly_linked_list.insert_at_index(0,5647);
        doubly_linked_list.insert_at_index(1,2665);
        doubly_linked_list.insert_at_index(2,368);
        doubly_linked_list.insert_at_index(3,789);
        doubly_linked_list.insert_at_index(4,2136);
        doubly_linked_list.print_forward();
        doubly_linked_list.insert_at_index(3,2648);
        doubly_linked_list.print_forward();
        doubly_linked_list.delete_at_index(1);
        doubly_linked_list.print_forward();
        doubly_linked_list.delete_at_index(2);
        doubly_linked_list.print_forward();
        doubly_linked_list.delete_at_index(2);
        doubly_linked_list.print_forward();
        doubly_linked_list.delete_at_index(2);
        doubly_linked_list.print_forward();
        doubly_linked_list.delete_at_index(1);
        doubly_linked_list.print_forward();
        doubly_linked_list.delete_at_index(0);
        doubly_linked_list.print_forward();
    #endif
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void list::test_circular_singly_linked_list()
{
    circular_sll.insert_at_head(3030);
    circular_sll.insert_at_head(4563);
    circular_sll.insert_at_head(8563);
    circular_sll.insert_at_head(223);
    circular_sll.print_list();
    circular_sll.delete_at_head();
    circular_sll.delete_at_head();
    circular_sll.delete_at_head();
    circular_sll.delete_at_head();
    circular_sll.print_list();
    circular_sll.insert_at_tail(400);
    circular_sll.insert_at_tail(500);
    circular_sll.insert_at_tail(470);
    circular_sll.insert_at_tail(7050);
    circular_sll.print_list();
    circular_sll.delete_at_tail();
    circular_sll.print_list();
    circular_sll.delete_at_tail();
    circular_sll.print_list();
    circular_sll.delete_at_tail();
    circular_sll.delete_at_tail();
    circular_sll.print_list();
    circular_sll.insert_at_head(500);
    circular_sll.print_list();
    circular_sll.delete_at_tail();
    circular_sll.print_list();
    circular_sll.insert_at_index(0, 100);
    circular_sll.insert_at_index(1, 110);
    circular_sll.insert_at_index(2, 112);
    circular_sll.insert_at_index(3, 310);
    circular_sll.print_list();
    circular_sll.insert_at_index(2, 212);
    circular_sll.print_list();
    circular_sll.delete_at_index(1);
    circular_sll.print_list();
    circular_sll.delete_at_index(3);
    circular_sll.print_list();
    circular_sll.delete_at_index(2);
    circular_sll.print_list();
    circular_sll.delete_at_index(1);
    circular_sll.print_list();
    circular_sll.delete_at_index(0);
    // circular_sll.delete_at_index(2);
    circular_sll.insert_at_index(0, 7810);
    // circular_sll.insert_at_index(3, 7810);
    circular_sll.print_list();
}

void list::test_circular_doubly_linked_list()
{
    circular_dll.insert_at_head(5632);
    circular_dll.insert_at_head(2236);
    circular_dll.insert_at_head(212);
    // circular_dll.print_backward();
    circular_dll.print_forward();
    circular_dll.delete_at_head();
    circular_dll.delete_at_head();
    circular_dll.print_forward();
    circular_dll.delete_at_head();
    circular_dll.print_forward();
    circular_dll.insert_at_head(212);
    circular_dll.print_forward();
    circular_dll.delete_at_head();
    circular_dll.print_forward();
    circular_dll.insert_at_tail(2345);
    circular_dll.insert_at_tail(285);
    circular_dll.insert_at_tail(147);
    circular_dll.print_forward();
    circular_dll.delet_at_tail();
    circular_dll.print_forward();
    circular_dll.delet_at_tail();
    circular_dll.print_forward();
    circular_dll.delet_at_tail();
    circular_dll.print_forward();
    circular_dll.insert_at_tail(147);
    circular_dll.print_forward();
    circular_dll.delet_at_tail();
    circular_dll.print_forward();
    circular_dll.insert_at_index(0,1235);
    circular_dll.insert_at_index(1,125);
    circular_dll.insert_at_index(2,735);
    circular_dll.insert_at_index(3,335);
    circular_dll.print_forward();
    circular_dll.delete_at_index(3);
    circular_dll.print_forward();
    circular_dll.delete_at_index(2);
    circular_dll.print_forward();
    circular_dll.delete_at_index(1);
    circular_dll.print_forward();
}

}
