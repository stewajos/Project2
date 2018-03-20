#include <stdio>
#include <string.h>
struct product{
	char[20] name;
	char[20] unit;
	int quantity;
	int price;
	struct product* next;
}
//we should just do this in the main
void createList(){
	product *head = (product *)malloc(sizeof(product));
	//where does this come from?
	d -> d = ‘n’; 
	head -> next = NULL;
}

//what? Why do we have this?
void getInfo ( struct product * pItem)  {
	fscanf ( "%d %s %d", &(pItem->price), pItem->name, pItem->quantity);
}



//delete a product
void deleteProduct(struct product *head, char* itemName){
	while(head->next != NULL && 0 != strcmp(head->name, itemName)){
		head = head->next;

	}	
	if(0 != strcmp(head->name, itemName)){
		printf("Could not find product to delete");
		return;
		
	}else{
		struct product* temp = head->next->next;
		free(head->next)
		head->next = temp;
	}	


}

//insert a product. Create the product in main and then just use this method
void insert(struct product* newItem, struct product* head){
	newItem->next = head->next;
	head->next = newItem;
	
	
}

//Delete entire list
void deleteAll(struct product* head){
	if(head!=NULL){
	deleteAll(head->next);
	free(head);
}


}


//search for a product by name
struct product* search(struct product* head, char* itemName){
	while(head->next != NULL && 0 != strcmp(head->name, itemName)){
		head = head->next;
	}
	if(0 != strcmp(head->name, itemName)){
		struct product* fail = malloc(sizeof(product));
		fail->name = "Not Found."
		return fail;
	}else{
		return head;	
	}
}

//Display products in list
void display(struct product* head){
	int count = 0;
	while(head != NULL){
		printf("Item %d:\n", count);
		printf("Name: %s\n", head->name);
		printf("Unit: %s\n", head->unit);
		printf("Quantity: %d\n", head->quantity);
		printf("Price: %d\n\n\n");
		count++;
		
		head = head->next;
		
	}
	
	
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
		return NULL;
		
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
