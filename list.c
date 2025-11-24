#include "list.h"
#include <stdlib.h>
#include <stdio.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * Traverses through the linked list until the tail, a node with a next value of NULL, is found, and returns that node 
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The tail of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_tail(struct ll_node *head) {
    struct ll_node *ptr = head ;
    if(ptr == NULL){
        return ptr ;
    }
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr ;
}

/**
 * Traverses through the linked list, incrementing the size variable every time a new non-empty node is entered
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The size of the linked list.
 */
int ll_size(struct ll_node *head) {
    int size = 0;
    struct ll_node *ptr = head ;
    while(ptr != NULL){
        size++;
        ptr = ptr->next ;
    }
    return size ;
}

/**
 * TODO: Describe what the function does
 * Traverses through the linked list either until the desired value is found or the end of the linked list is reached
 * And returns either NULL or the node where the value was found
 * 
 * @param head Pointer to the first node of the linked list
 * @param value The value being searched for
 * @return The node containing the desired value. If the value is not found in the list, returns NULL
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    struct ll_node *ptr = head;
    while(ptr != NULL && ptr->data != value){
        ptr = ptr->next ;
    }
    return ptr ;
}

/**
 * Determines the size of the linked list, returning NULL if empty. 
 * Then creates an array of an equal size before traversing the linked list and populating the array
 * 
 * @param head Pointer to the first node of the linked list
 * @return The array representation of the linked list. If the list is empty (NULL), returns NULL
 */
int *ll_toarray(struct ll_node *head) {
    struct ll_node *ptr = head;
    if(ptr == NULL){
        return NULL;
    }
    int size = ll_size(head);
    int pos = 0;

    int *ll_array = malloc(sizeof(int)*size);
    while(ptr != NULL){
        ll_array[pos++] = ptr->data;
        ptr = ptr->next;
    }
    
    return ll_array ;
}

/**
 * Creates a new node that is not part of an existing linked list
 * 
 * @param data The data to be held in the new node
 * @return The created node
 */
struct ll_node *ll_create(int data) {
    struct ll_node *head = malloc(sizeof(struct ll_node));
    head->data = data;
    head->next = NULL;
    return head ;
}

/**
 * Recursively adds calls to free every node in the linked list to a stack and then frees them all in sequence
 * 
 * @param head Pointer to the first node of the linked list
 */
void ll_destroy(struct ll_node *head) {
    if(head != NULL){
        ll_destroy(head->next);
        free(head);
    }
}

/**
 * Locates the tail of the existing linked list, then creates the new node and sets the previous tail's next to point to the new node
 * 
 * @param head Pointer to the first node of the linked list
 * @param data The data to be contained in the new node
 */
void ll_append(struct ll_node *head, int data) {
    struct ll_node *tail = ll_tail(head);
    struct ll_node *ptr = ll_create(data);

    tail->next = ptr;
}

/**
 * Checks if the array is empty and returns NULL if it is
 * If not, creates the head node of the new linked list from the first item in the data array
 * If the array has more than one item, creates the next node from the second item in the data array and sets head->next to point to it
 * Then, if the array has more then two items, declares a third pointer and iterates through the rest of the array and adding the data points to the linked list
 * 
 * @param data The array of data to be transferred to the new linked list
 * @param len The length of the array
 * @return The pointer to the first node of the new linked list. If the array is empty (NULL) returns NULL
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if(len == 0){
        return NULL ;
    }
    struct ll_node *head = ll_create(data[0]);
    if(len > 1){
        struct ll_node *ptr = ll_create(data[1]);
        head->next = ptr;
        if(len > 2){
            struct ll_node *next_node;
            for(int i = 2; i < len; i++){
                next_node = ll_create(data[i]);
                ptr->next = next_node;
                ptr = ptr->next;
            }
        }
    }
    return head ;
}

/**
 * TODO: Describe what the function does
 * 
 * @param head Pointer to the first node of the linked list
 * @param value The value the user is looking to remove from the linked list
 * @return The new head of the linked list. If the list was or becomes empty(NULL), returns NULL
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    struct ll_node *ptr = head;
    if(ptr == NULL){
        return ptr;
    }
    if(ptr->data == value){
        head = ptr->next;
        free(ptr);
        return head;
    }
    while(ptr->next != NULL && ptr->next->data != value){
        ptr = ptr->next;
    }
    if(ptr->next != NULL){
        struct ll_node *to_destroy = ptr->next;
        ptr->next = to_destroy->next;
        free(to_destroy);
    }

    return head ;
}

