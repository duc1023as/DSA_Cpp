#ifndef LINKED_LIST
#define LINKED_LIST

#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include "circular_singly_linked_list.h"
#include "circular_doubly_linked_list.h"

namespace linked_list
{
class list
{
private:
    singly_linked_list::list<int> singly_linked_list;
    doubly_linked_list::list<int64_t> doubly_linked_list;
    csll::list<uint32_t> circular_sll;
    cdll::list<uint16_t> circular_dll;
public:
    list() = default;
    ~list() = default;
    void test_singly_linked_list();
    void test_doubly_linked_list();
    void test_circular_singly_linked_list();
    void test_circular_doubly_linked_list();
};

}

#endif