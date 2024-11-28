// Write a c program for implementing ascending priority queue using array?

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the priority queue

// Structure to hold an element and its priority
struct Element
{
    int data;     // The value of the element
    int priority; // The priority of the element
};

// Structure to represent the priority queue
struct PriorityQueue
{
    struct Element elements[MAX];
    int size; // Current size of the priority queue
};

// Function to initialize the priority queue
void initQueue(struct PriorityQueue *pq)
{
    pq->size = 0;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue *pq)
{
    return pq->size == 0;
}

// Function to insert an element into the priority queue
void enqueue(struct PriorityQueue *pq, int data, int priority)
{
    if (pq->size >= MAX)
    {
        printf("Priority Queue is full!\n");
        return;
    }

    // Add the new element to the end of the queue
    pq->elements[pq->size].data = data;
    pq->elements[pq->size].priority = priority;
    pq->size++;

    // Sort the queue by priority (ascending order)
    for (int i = pq->size - 1; i > 0; i--)
    {
        if (pq->elements[i].priority < pq->elements[i - 1].priority)
        {
            // Swap the elements
            struct Element temp = pq->elements[i];
            pq->elements[i] = pq->elements[i - 1];
            pq->elements[i - 1] = temp;
        }
        else
        {
            break; // No need to sort further
        }
    }
}

// Function to remove and return the element with the highest priority
struct Element dequeue(struct PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty!\n");
        exit(EXIT_FAILURE);
    }

    return pq->elements[0]; // Return the first element
}

// Function to display the elements of the priority queue
void display(struct PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++)
    {
        printf("Data: %d, Priority: %d\n", pq->elements[i].data, pq->elements[i].priority);
    }
}

int main()
{
    struct PriorityQueue pq;
    initQueue(&pq);

    // Insert elements into the priority queue
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 25, 2);

    // Display the queue
    display(&pq);

    // Dequeue an element
    struct Element dequeuedElement = dequeue(&pq);
    printf("Dequeued element: Data: %d, Priority: %d\n", dequeuedElement.data, dequeuedElement.priority);

    // Display the queue again
    display(&pq);

    return 0;
}
