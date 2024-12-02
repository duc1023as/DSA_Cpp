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
    #if 0
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
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
}
