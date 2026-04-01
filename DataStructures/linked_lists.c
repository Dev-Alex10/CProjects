#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void list_insert_at_position(node_t **head, int value, int position);
void list_insert_end(node_t **head, int value);
void list_insert_begin(node_t **head, int value);
int  list_remove(node_t **head, int value);   
int  list_search_element(const node_t *head, int value);
void list_update_node(node_t *head, int old_value, int new_value);
void list_print(const node_t *head); 

int main(){
    node_t *head = NULL;
    int choice, value, position, result;

    do {
        printf("\n─── Linked List Menu ───────────────\n");
        printf(" 1. Insert at beginning\n");
        printf(" 2. Insert at end\n");
        printf(" 3. Insert at position\n");
        printf(" 4. Remove value\n");
        printf(" 5. Search value\n");
        printf(" 6. Update value\n");
        printf(" 7. Print list\n");
        printf(" 0. Exit\n");
        printf("────────────────────────────────────\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                list_insert_begin(&head, value);
                break;

            case 2:
                printf("Value: ");
                scanf("%d", &value);
                list_insert_end(&head, value);
                break;

            case 3:
                printf("Value: ");
                scanf("%d", &value);
                printf("Position: ");
                scanf("%d", &position);
                list_insert_at_position(&head, value, position);
                break;

            case 4:
                printf("Value to remove: ");
                scanf("%d", &value);
                result = list_remove(&head, value);
                if (result)
                    printf("Removed %d successfully.\n", value);
                else
                    printf("Value %d not found.\n", value);
                break;

            case 5:
                printf("Value to search: ");
                scanf("%d", &value);
                result = list_search_element(head, value);
                if (result >= 0)
                    printf("Found %d at position %d.\n", value, result);
                else
                    printf("Value %d not found.\n", value);
                break;

            case 6:
                printf("Old value: ");
                scanf("%d", &value);
                printf("New value: ");
                scanf("%d", &position);      /* reusing position as new_value */
                list_update_node(head, value, position);
                break;

            case 7:
                list_print(head);
                break;

            case 0:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option, try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

void list_insert_begin(node_t **head, int value)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
        return;

    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}


void list_insert_end(node_t **head, int value)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
        return;

    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
}


void list_insert_at_position(node_t **head, int value, int position)
{
    if (position <= 0) {
        list_insert_begin(head, value);
        return;
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
        return;

    node_t *current = *head;
    for (int i = 0; i < position - 1; i++) {
        if (current == NULL) {          /* position exceeds list length */
            list_insert_end(head, value);
            free(new_node);
            return;
        }
        current = current->next;
    }

    new_node->data = value;
    new_node->next = current->next;
    current->next  = new_node;
}


int list_remove(node_t **head, int value)
{
    if (*head == NULL)
        return 0;

    /* removing head */
    if ((*head)->data == value) {
        node_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1;
    }

    node_t *current = *head;
    while (current->next != NULL) {
        if (current->next->data == value) {
            node_t *temp  = current->next;
            current->next = temp->next;
            free(temp);
            return 1;
        }
        current = current->next;
    }

    return 0;   /* value not found */
}


int list_search_element(const node_t *head, int value)
{
    int position = 0;

    while (head != NULL) {
        if (head->data == value)
            return position;
        head = head->next;
        position++;
    }

    return -1;  /* not found */
}


void list_update_node(node_t *head, int old_value, int new_value)
{
    while (head != NULL) {
        if (head->data == old_value) {
            head->data = new_value;
            return;
        }
        head = head->next;
    }
}


void list_print(const node_t *head)
{
    if (head == NULL) {
        printf("[empty list]\n");
        return;
    }

    while (head != NULL) {
        printf("[%d]", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
