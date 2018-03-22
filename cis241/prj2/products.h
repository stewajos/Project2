#include <stdio.h>
#include <string.h>

struct product{
char name[20];
char unit[20];
int quantity;
int price;
struct product* next;
};

void deleteProduct(struct product* head, char* itemName);

void insert(struct product* head, struct product* newNode);

void deleteAll(struct product* head);

struct product* search(struct product* head, char* itemName);

void saveStore(struct product* head, char* saveName); 

void displayAll(struct product* head);

void display(struct product* node);

void purchaseProduct(struct product* head, char* itemName);

void sellProduct(struct product* head, char* itemName);
