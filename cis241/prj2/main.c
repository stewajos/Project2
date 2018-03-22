#include <stdio.h>
#include <stdlib.h>
#include "products.h"
int main(){
	struct product* head;
	struct product* newProd;
	int listCreated = -1;
	int listLength = 0;
	int option = 'q'; //variable to hold choices
	while(0 != option){
		printf("\n\n 1: create an empty list	2: insert a product\n 3: Delete a product	4: Delete entire list\n5: Search a product	6: Display products in the list\n7: Purchase a product	8: Sell a product\n	9: Save to file 	0: Exit\n");
	
		scanf("%d", &option);

		if(1 == option){
			//creating linked list of Products
			printf("\ncreating head\n");
			head = malloc(sizeof(struct product*));
			listCreated = 1;
			head->quantity = 0;
			head->next = NULL;
			head->price = 0;
			head->lastNode = 1;
			listLength += 1;
		}	
		else if(2 == option){
			printf("\nPlease Enter the name of the product: ");
			char newName[20];
			scanf("%s", newName);
	
			printf("\nPlease enter the product unit of measurement: ");
			char newDesc[200];
			scanf("%s", newDesc);

			printf("\nPlease enter the number of units: ");
			int count = 0;
			scanf("%d", &count);

			printf("\nPlease enter the price of the product: ");
			int newPrice = 0;
			scanf("%d", &newPrice);

			newProd = (struct product*)malloc(sizeof(struct product*));
			printf("\nMaking product...\n");
			strcpy((*newProd).name,  newName);
			strcpy(newProd->unit, newDesc);
			newProd->quantity = count;
			newProd->price = newPrice;
			printf("\n...adding product to list...\n");
			newProd->next = NULL;
			newProd->lastNode = 1;
			insert(&newProd, &head, listLength);		

			printf("\n...product created\n\n");
				
			listLength +=1;
				
		}
		else if(3 == option){
			printf("\nWhat's the name of the product?: ");	
			char newName[20];
			scanf("%s", newName);
			
			deleteProduct(head,  newName);
						
		}
		else if(4 == option){
			deleteAll(head);
		}
		else if(5 == option){
			printf("What is the name of the product?: ");
			char prodName[20];
			scanf("%s", prodName);
			
			display(search(head, prodName));	
		}
		else if(6 == option){
			displayAll(head);	
		}
		else if(7 == option){
			printf("\nWhat is the name of the product being purchased?: ");
			char itemName[20];
			scanf("%s", itemName);
			purchaseProduct(head, itemName);
			
			
			
		}
		else if(8 == option){
			printf("\nWhat is the name of the product being sold?: ");	
			char itemName[20];
			scanf("%s", itemName);
			sellProduct(head, itemName);


		}	
		else if(9 == option){
			printf("\nFIXME: SAVE METHOD");
			char saveName[20];
			scanf("%s", saveName);
			char* temp = malloc(20 * sizeof(char));
			strcpy(temp, saveName);
			saveStore(head, temp);
				
		}
		else if(0 == option){
			exit(1);
		}
	}
	return 0;
}
