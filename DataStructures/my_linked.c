#include <stdio.h>
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

        switch (choice) {
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

