/* Develop a C program for a Doubly Linked List representing a sequence of web pages visited by a
user. The program should insert a new page, move forward and backward, delete a specified
page, and display the pages from first-to-last and last-to-first while handling beginning and end
conditions correctly.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Create a struct called as Node containing data as char array*/
struct Node{
    char url[100];
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;      /* first page  pointer */
struct Node *tail = NULL;      /* last page  pointer  */
struct Node *cur = NULL;       /* current page pointer*/
/* Insert a new page at the end of the list */
void insert(char url[]) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    strcpy(n->url, url);
    n->next=NULL;
    n->prev=NULL;
    if (head==NULL) {
        head=n;
        tail= n;
    } else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    cur=n;   /* Now new page becomes the current page */
    printf("Inserted: %s\n", url);
}
/* Move to the next page */
void moveForward() {
    if (cur == NULL) {
        printf("List is empty.\n");
    } else if (cur->next == NULL) {
        printf("Already at the last page.\n");
    } else {
        cur = cur->next;
        printf("Moved forward to: %s\n", cur->url);
    }
}
/* Move to the previous page */
void moveBackward() {
    if (cur == NULL) {
        printf("List is empty.\n");
    } else if (cur->prev == NULL) {
        printf("Already at the first page.\n");
    } else {
        cur = cur->prev;
        printf("Moved backward to: %s\n", cur->url);
    }
}
/* Delete a page by its url */
void deletePage(char url[]) {
    struct Node *temp = head;
    while (temp != NULL && strcmp(temp->url, url) != 0)
        temp = temp->next;
    if (temp == NULL) {
        printf("Page not found: %s\n", url);
        return;
    }
    if (temp == cur)
        cur = (temp->next != NULL) ? temp->next : temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;          /* Deleting the first node */
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;          /* Deleting the last node */
    printf("Deleted: %s\n", url);
    free(temp);
}
/* Display pages from first to last */
void displayForward() {
    struct Node *temp = head;
 
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("First -> Last: ");
    while (temp != NULL) {
        printf("%s", temp->url);
        if (temp == cur)
            printf("(current)");
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}
/* Display pages from last to first */
void displayBackward() {
    struct Node *temp = tail;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Last -> First: ");
    while (temp != NULL) {
        printf("%s", temp->url);
        if (temp == cur)
            printf("(current)");
        if (temp->prev != NULL)
            printf(" -> ");
        temp = temp->prev;
    }
    printf("\n");
}
int main()
{
    int choice;
    char url[100]; //Create an url array
    //Create a while loop which executes until true.
    while (1){
        printf("\n1.Insert  2.Forward  3.Backward  4.Delete  5.Display Forward  6.Display Backward  7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter page url: ");
            scanf("%s", url);
            insert(url);
        } 
        else if (choice == 2) {
            moveForward();
        } 
        else if (choice == 3) {
            moveBackward();
        } 
        else if (choice == 4) {
            printf("Enter page url to delete: ");
            scanf("%s", url);
            deletePage(url);
        } 
        else if (choice == 5) {
            displayForward();
        } 
        else if (choice == 6) {
            displayBackward();
        } 
        else if (choice == 7) {
            break;
        } 
        else {
            printf("Invalid choice.\n");
        }
    }
}
