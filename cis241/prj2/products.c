#include <stdio>
#include <string.h>
struct product{
	char[20] name;
	int quantity;
	int price;
}
void createList(){
	product *head = (product *)malloc(sizeof(product);
	d -> d = ‘n’; 
	head -> next = NULL;
}
void getInfo ( struct product * pItem)  {
	fscanf ( "%d %s %d", &(pItem->price), pItem->name, pItem->quantity);
}
void deleteProuct(struct product *head){
	if(head!=NULL){
	deleteProduct(head->next);
	free(head);
}
}


