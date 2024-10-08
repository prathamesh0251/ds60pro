#include <stdio.h>
#include <stdlib.h>

// Definition of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to find intersection of two linked lists
Node* findIntersection(Node* head1, Node* head2) {
    Node* intersectionHead = NULL;
    Node* tail = NULL;

    while (head1 != NULL) {
        Node* temp = head2;
        while (temp != NULL) {
            if (head1->data == temp->data) {
                Node* newNode = createNode(head1->data);
                if (intersectionHead == NULL) {
                    intersectionHead = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
                break; // Found intersection, move to next node in head1
            }
            temp = temp->next;
        }
        head1 = head1->next;
    }

    return intersectionHead;
}

// Function to display the linked list
void display(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Create first linked list
    insert(&list1, 1);
    insert(&list1, 2);
    insert(&list1, 3);
    insert(&list1, 4);
    insert(&list1, 5);

    // Create second linked list
    insert(&list2, 4);
    insert(&list2, 5);
    insert(&list2, 6);
    insert(&list2, 7);

    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    // Find intersection
    Node* intersection = findIntersection(list1, list2);
    
    printf("Intersection: ");
    display(intersection);

    return 0;
}