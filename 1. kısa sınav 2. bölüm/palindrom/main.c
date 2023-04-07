#include <stdio.h>
#include <stdlib.h>
 //Akif Silan 1220505044
struct node {
    char data;
    struct node* next;
};
 
int palindromkontrolu(struct node* head) {
    struct node* temp = head;
    int stack[100], top = -1, i = 0;
 
    while (temp != NULL) {
        stack[++top] = temp->data;
        temp = temp->next;
    }
 
    while (head != NULL) {
        if (stack[top--] != head->data)
            return 0;
        head = head->next;
    }
    return 1;
}
 
void insert(struct node** head, char new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
 
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}
 
int main() {
    struct node* head = NULL;
    char str[] = "akif";
    int i;
 
    for (i = 0; str[i] != '\0'; i++) {
        insert(&head, str[i]);
    }
 
    if (palindromkontrolu(head)) {
        printf("Evet bu palindromdur\n");
    } else {
        printf("Hayir bu palindrom degildir\n");
    }
    return 0;
}

