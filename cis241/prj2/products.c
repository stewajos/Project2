//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "products.h"
//#include <stdio.h>
//struct product{
//	char name[20];
//	char unit[200];
//	int quantity = 0;
//	int price = 0;
//	struct product* next = malloc(sizeof(struct product*));
//};



//delete a product
void deleteProduct(struct product *head, char* itemName){
struct product* previous = head;
	while(head->next != NULL && 0 != strcmp(head->name, itemName)){
		previous = head;
		head = head->next;
		
	}	
	if(0 != strcmp(head->name, itemName)){
		printf("Could not find product to delete");
		return;
		
	}else{
		struct product* temp = head->next;
		free(head);
		previous->next = temp;
	}	
}

//insert a product. Create the product in main and then just use this method
void insert(struct product* newItem, struct product* head){
	int i = 0;
	printf("\nabout to start while loop\n");
	while(head->next != NULL){
		printf("\nlooping...\n");
		head = head->next;
		
	}

	head->next = newItem;
	//(*newItem)->next = NULL;
}

//Delete entire list
void deleteAll(struct product* head){
	struct product* tmp = head;
	while(head->next != NULL){
		while(tmp->next != NULL){
			tmp=tmp->next;
}
	free(tmp);
}
	free(head);
}


//search for a product by name
struct product* search(struct product* head, char* itemName){
	while(head->next != NULL && 0 != strcmp(head->name, itemName)){
		head = head->next;
	}
	if(0 != strcmp(head->name, itemName)){
		struct product* fail = malloc(sizeof(struct product*));
		strcpy(fail->name, "Not Found.");
		return fail;
	}else{
		return head;	
	}
}


void saveStore(struct product* head, char* saveName){
	FILE* saveLocation = NULL;
	char* temp = malloc(20 * sizeof(char));
	strcpy(temp, saveName);
	saveLocation = fopen(temp, "w+");
	head = head->next;
	while(head != NULL){
		strcpy(temp, head->name);
		fprintf(saveLocation, "Product: %s\n", temp);
		strcpy(temp, head->unit);
		fprintf(saveLocation, "Unit: %s\n", temp);
		
		fprintf(saveLocation, "Quantity: %d\n", head->quantity);
		fprintf(saveLocation, "Price: %d\n", head->price);
		head = head->next;
	}

	printf("\nFile Saved!\n");
}

//Display products in list
void displayAll(struct product* head){
	int count = 1;
//	if(head->next != NULL){
//		head = head->next;
//	}else{
//		return;
//	}
	while(head != NULL){
		
		printf("Item %d:\n", count);
		printf("Name: %s\n", head->name);
		printf("Unit: %s\n", head->unit);
		printf("Quantity: %d\n", head->quantity);
		printf("Price: %d\n\n\n", head->price);
		count++;
		
		head = head->next;
		
	}
	printf("\nFinished displaying all %d items\n", count);
	
	
}

void display(struct product* node){
	
	printf("Name: %s\n", node->name);
	printf("Unit: %s\n", node->unit);
	printf("Quantity: %d\n", node->quantity);	
	printf("Price: %d\n\n", node->price);



}

//sell a product
void sellProduct(struct product* head, char* itemName){
	struct product* previous = head;
	while(head->next != NULL && 0 != strcmp(head->name, itemName)){
		head = head->next;
		previous = head;
	}
	
	if(0 != strcmp(head->name, itemName)){
		printf("Product not found for Deletion");
		
		
	}else{
		head->quantity = head->quantity - 1;
		if(head->quantity < 1){
			struct product* temp = head->next->next;
			previous->next = temp;
			free(head);
			
		}
	}
	
	
}


//purchase a product
void purchaseProduct(struct product* head, char* itemName){
	while(head->next != NULL && 0 != strcmp(head->name, itemName)){
		head = head->next;
		
	}if(0 == strcmp(head->name, itemName)){
		head->quantity = head->quantity + 1;
	
	}else{
		printf("Could not find product %s\n", itemName);
	}

}
