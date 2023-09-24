#include <stdio.h>
#include <stdlib.h>

#include "lib/list.h"

int main() {
    linked_list list;
    add_element(&list, 0);
    add_element(&list, 1);
    add_element(&list, 2);
    remove_nth_element(&list, 3);
    walk_through(&list);
    return 0;
}