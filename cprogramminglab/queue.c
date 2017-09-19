/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (q == NULL)
        return q;
    q->head = NULL;        
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    list_ele_t *ele;    
    /* How about freeing the list elements? */
    /* Free queue structure */
    if (q == NULL) 
        return;
    ele = q->head;
    while (ele != NULL) {
        list_ele_t *point = ele;
        ele = ele->next;
        free(point);
    }
    free(q);
    return;
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    list_ele_t *ele;
    /* What should you do if the q is NULL? */
    if (q == NULL)
        return false;    
    ele = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if (ele == NULL)
        return false;
    ele->value = v;
    ele->next = q->head;
    q->head = ele;
    if (q->size == 0) {
        q->tail = ele;
    }
    q->size++;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    list_ele_t *ele;
    if (q == NULL) 
        return false;
    ele = malloc(sizeof(list_ele_t));
    if (ele == NULL) 
        return false;
    ele->value = v;
    ele->next = NULL;
    q->tail->next = ele;
    q->tail = ele;
    if (q->size == 0) {
        q->head = ele;
    }
    q->size++;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    /* You need to fix up this code. */
    if (q == NULL || q->size == 0)
        return false;
    list_ele_t *head;
    head = q->head;
    q->head = q->head->next;
    q->size--;
    if (vp != NULL) {
        *vp = head->value;
    }
    free(head);    
    return true;
}

int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return (q == NULL) ? 0 : q->size;
}

/*
  Reverse elements in queue
 */
void q_reverse(queue_t *q)
{    
    /* You need to write the code for this function */
    if (q == NULL || q->size <= 1) 
        return;
    list_ele_t *first = q->head;
    list_ele_t *second = first->next;
    list_ele_t *third;
    first->next = NULL;
    q->tail = first;
    while (second->next != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    second->next = first;
    q->head = second;
    return;
}

