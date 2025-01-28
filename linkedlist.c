#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} LNODE;

LNODE* createNode() {
    LNODE* nd = (LNODE*) malloc(sizeof(LNODE));
    nd->next = NULL;
    return nd;
}

void display(LNODE* st) {
    while (st != NULL) {
        printf("%d ", st->val);
        st = st->next;
    }
    printf("\n");
}
LNODE* insertBegin(LNODE* st, int el) {
    LNODE* newnd = createNode();
    newnd->val = el;
    newnd->next = st;
    return newnd;
}

LNODE* insertEnd(LNODE* st, int el) {
    LNODE* newnd = createNode();
    newnd->val = el;

    if (st == NULL) {
        return newnd;
    }

    LNODE* temp = st;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnd;
    return st;
}
LNODE* deleteBegin(LNODE* st) {
    if (st == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    LNODE* temp = st;
    st = st->next;
    free(temp);
    return st;
}
LNODE* deleteEnd(LNODE* st) {
    if (st == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (st->next == NULL) {
        free(st);
        return NULL;
    }

    LNODE* temp = st;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    LNODE* nodeToDelete = temp->next;
    temp->next = NULL;
    free(nodeToDelete);
    return st;
}
void RevDisplay(LNODE*st)
{
    LNODE *q=st;
    if(q!=NULL)
    RevDisplay(q->next);
    printf("%d",q->val); 
}
int main() {
    LNODE* head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
     printf("Linked List after inserting at beginning: ");
    display(head);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
     printf("Linked List after inserting at end: ");
    display(head);
    head = deleteBegin(head);
     printf("\nLinked List after deleting from beginning: \n");
    display(head);
    head = deleteEnd(head);
  printf("\nLinked List after deleting from end: ");
    display(head);
    RevDisplay(head);
      return 0;
}