#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flowers
{
    char f_name[20]; // biological name
    struct flowers *next;
};

void insertatbeg(struct flowers **heads, char *new_fname)
{
    struct flowers *new_flower = (struct flowers *)malloc(sizeof(struct flowers));
    strcpy(new_flower->f_name, new_fname);
    new_flower->next = (*heads);
    (*heads) = new_flower;
}

// Insert a node after a node
void insertAfter(struct flowers *prev_flower, char *new_fname) {
    if (prev_flower == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct flowers *new_flower = (struct flowers *)malloc(sizeof(struct flowers));
    strcpy(new_flower->f_name, new_fname);
    new_flower->next = prev_flower->next;
    prev_flower->next = new_flower;
}

// Insert a node after a flower name
void insertAfterByName(struct flowers *head, char *existing_fname, char *new_fname) {
    struct flowers *current = head;
    while (current != NULL) {
        if (strcmp(current->f_name, existing_fname) == 0) {
            insertAfter(current, new_fname);
            return;
        }
        current = current->next;
    }
    printf("Flower with name '%s' not found\n", existing_fname);
}

// Insert a node before a flower name
void insertBefore(struct flowers **heads, char *existing_fname, char *new_fname) {
    struct flowers *current = *heads;
    struct flowers *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->f_name, existing_fname) == 0) {
            struct flowers *new_flower = (struct flowers *)malloc(sizeof(struct flowers));
            strcpy(new_flower->f_name, new_fname);
            new_flower->next = current;

            if (prev == NULL) {
                *heads = new_flower;
            } else {
                prev->next = new_flower;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Flower with name '%s' not found\n", existing_fname);
}

// Insert a node at the end
void insertAtEnd(struct flowers **heads, char *new_fname) {
    struct flowers *new_flower = (struct flowers *)malloc(sizeof(struct flowers));
    strcpy(new_flower->f_name, new_fname);
    new_flower->next = NULL;

    if (*heads == NULL) {
        *heads = new_flower;
        return;
    }

    struct flowers *last = *heads;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_flower;
}

int main() 
{
    struct flowers *head = NULL;
    struct flowers *Rose = NULL;
    struct flowers *lotus = NULL;
    struct flowers *sunflower = NULL;
    struct flowers *traverse;

    Rose = (struct flowers *)malloc(sizeof(struct flowers));
    lotus = (struct flowers *)malloc(sizeof(struct flowers));
    sunflower = (struct flowers *)malloc(sizeof(struct flowers));

    // Assign data values
    strcpy(Rose->f_name, "Rosa");
    strcpy(lotus->f_name, "Nelumbo nucifera");
    strcpy(sunflower->f_name, "Helianthus");

    Rose->next = lotus;
    lotus->next = sunflower;
    sunflower->next = NULL;

    head = Rose;
    insertatbeg(&head, "Lilium");
    
    insertAfterByName(head, "Rosa", "Hibiscus");
    
    // Example: Insert before "Lotus"
    insertBefore(&head, "Nelumbo nucifera", "Daisy");

    // Example: Insert at end
    insertAtEnd(&head, "Tulip");

    traverse = head;

    while (traverse != NULL)
    {
        printf("%s\n", traverse->f_name); // Use %s to print strings
        traverse = traverse->next;
    }
    
    // Free allocated memory
    while (head != NULL) {
        struct flowers *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
