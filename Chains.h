//
// Created by Tajeshwar Khara on 2019-05-21.
//

#ifndef AB_HASHING_CHAINING_CHAINS_H
#define AB_HASHING_CHAINING_CHAINS_H

#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Pointer pointer just means that H points to a pointer that points to a struct Node
void SortedInsert(struct Node** H, int x)
{
    // Make three struct node pointers
    struct Node* t, *q = NULL, *p = *H;

    // Allocate memory for one node
    t = (struct Node*)malloc(sizeof(struct Node));

    // Add the data and next value
    t->data = x;
    t->next = NULL;

    // If this is the first node
    if(*H == NULL)
    {
        // The first pointer in the array points to the node t
        *H = t;
    }
    else
    {
        // While p is not null the value is smaller than x keep moving
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        // If p points to the first pointer
        if(p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node* Search(struct Node* p, int key)
{
    while(p != NULL)
    {
        if(key == p->data)
        {
            return p;
        }

        p = p->next;
    }

    return NULL;
}


#endif //AB_HASHING_CHAINING_CHAINS_H
