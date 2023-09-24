#include <stdio.h>
#include <stdlib.h>

typedef struct li_element {
    int value;
    struct li_element *next;
} li_element;

typedef struct linked_list {
    struct li_element *head; // First element
    struct li_element *tail; // Last element
} linked_list;

// Adds the element <value> to the end of the list
void add_element(linked_list *list, int value) {
    li_element *element = malloc(sizeof(li_element));
    element->value = value;
    element->next = NULL;
    /* If list.head == NULL, list.length == 0 */
    if (list->head == NULL) {
        list->head = element;
        list->tail = element;
    } else {
        list->tail->next = element;
        list->tail = element;
    }
}

// Gets the nth element of the list, starting at 0.
int get_nth_element(linked_list *list, int n) {
    li_element *element = list->head;
    for (int i = 0; i < n; i++) {
        element = element->next;
    }
    return element->value;
}

// Removes the nth element of the list with index n, starting at 0
int remove_nth_element(linked_list *list, int n) {
    li_element *element = list->head;
    for (int i = 0; i < n; i++) {
        if(element -> next == NULL) return 1;
        element = element->next;
    }
    li_element *next = element->next;
    element->next = next->next;
    free(next);
    return 0;
}

// Walk through the list and print each element
void walk_through(linked_list *list) {
    li_element *element = list->head;
    while (element != NULL) {
        printf("%d\n", element->value);
        element = element->next;
    }
}