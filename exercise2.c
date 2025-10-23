/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 * 
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "exercise2.h"

/* 
 * Sort a singly linked list in-place using insertion sort
 * list: pointer to the first node of the list
 * 
 * The function should sort the list by rearranging pointers,
 * not by creating new nodes or swapping data values.
 * Returns pointer to the new head of the sorted list.
 */
node * sorted_insert(node * list, node *key){
    print_list(list);
    //hvis enten listne er null eller det første element er større end vores nuværende key skal key være det nye første element
    if(list == NULL || key->data < list->data){
        key->next = list;
        list = key;
    }
    else{
        node * iterator = list;
        while(iterator->next != NULL && iterator->next->data < key->data){
            iterator = iterator->next;
        }

        key->next = iterator->next;
        iterator->next = key;
    }
    return list;
}

node * isort(node* list) {
    /* TODO: Implement insertion sort for linked list */

    node * sorted = NULL;

    node * current = list;

    while(current != NULL){
        node * next = current->next;
        sorted = sorted_insert(sorted,current);
        current = next;
    }
    return sorted;
}

/* Helper function to print the list */
void print_list(node* list) {
    node* current = list;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

/* Helper function to create a node */
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Helper function to free the list */
void free_list(node *list)
{
    node *current = list;
    node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
