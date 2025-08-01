#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    int data;
    struct node *next;
};
struct node *head = NULL;

void create_list(int key, int data){
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->key = key;
    link->next = NULL;

    if(head == NULL) head = link;

    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = link;
    }
}

void print_list(){
    struct node *temp = head;
    while(temp != NULL){
        cout << temp->key << " " << temp->data << '\n';
        temp = temp->next;
    }
}

void delete_first(){
    if(head == NULL) return;
    head = head->next;
}

void delete_by_key(int key){
    struct node *temp = head;
    struct node *prev = NULL;
    while(temp->key != key){
        if(temp->next == NULL)return;
        prev = temp;
        temp = temp->next;
    }
    if(head == temp){
        head = head->next;
    }
    else prev->next = temp->next;
}

void insert_between_keys(int key, int nk, int nd){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = nd;
    newnode->key = nk;
    newnode->next = NULL;

    struct node *temp = head;
    while(temp->key != key){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}

int main(){
    create_list(1, 11);
    create_list(2, 21);
    create_list(3, 71);
    create_list(7, 55);
    create_list(9, 11);
    create_list(0, 73);

    print_list();

    delete_first();
    printf("After deletion : head\n");
    print_list();

    //delete_by_key(3);
    //printf("After deletion : by key\n");
    //print_list();

    insert_between_keys(3, 5, 83);
    printf("After insertion\n");
    print_list();
}
