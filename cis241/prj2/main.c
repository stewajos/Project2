#include <stdio.h>
#include <stdlib.h>
#include "products.h"
int main(){
	struct product* head;
//	struct product* newProd;
	struct product* iteration = malloc(sizeof(struct product*));
	int listCreated = -1;
	int listLength = 0;
	int option = 'q'; //variable to hold choices
	while(0 != option){
		printf("\n\n 1: create an empty list	2: insert a product\n 3: Delete a product	4: Delete entire list\n5: Search a product	6: Display products in the list\n7: Purchase a product	8: Sell a product\n	9: Save to file 	0: Exit\n");
	
		scanf("%d", &option);

		if(listCreated < 1 && 1 == option){
			//creating linked list of Products
			printf("\ncreating head\n");
			head = malloc(sizeof(struct product));
			listCreated = 1;
			head->quantity = 0;
			//head->next = NULL;
			head->price = 0;
			head->lastNode = 1;
			listLength += 1;
		}	
		else if(listCreated > 0 && 2 == option){
			printf("\nPlease Enter the name of the product(Must be within max 20 characters): ");
			char newName[200];
			strcpy(newName, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
			while(strlen(newName) > 20){
				scanf("%s", newName);
				if(strlen(newName) > 20){
					printf("\nPlease try again\n");
				}

			}
			printf("\nPlease enter the product unit of measurement(Must be within max 20 characters): ");
			char newDesc[200];
			strcpy(newDesc, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
			while(strlen(newDesc) > 20){
				scanf("%s", newDesc);
				if(strlen(newDesc) > 20){
					printf("\nPlease try again\n");
				}
			}
			printf("\nPlease enter the number of units(only positive values or zero accepted): ");
			int count = -1;
			while(count < 0){
				scanf("%d", &count);
				if(count < 0){
					printf("\nPlease enter a valid number\n");
				}
			}
			printf("\nPlease enter the price of the product(only positive values or zero accepted): ");
			int newPrice = -1;
			while(newPrice < 0){
				scanf("%d", &newPrice);
				if(newPrice < 0){
					printf("\nPlease enter a valid number\n");
				}
			}
			struct product* newProd = malloc(sizeof(struct product));
			printf("\nMaking product...\n");
			strcpy((*newProd).name,  newName);
			strcpy(newProd->unit, newDesc);
			newProd->quantity = count;
			newProd->price = newPrice;
			printf("\n...adding product to list...\n");
			//newProd->next = NULL;
			newProd->lastNode = 1;
			insert(newProd, head);		
			
//			iteration = head;
//			printf("\nTrying new thing...\n");
//			int i;
//			for(i = 1; i < listLength; i++){
//				printf("\nNew thing loop\n");
//				iteration = iteration->next;
//				
//			}
//			iteration->next = newProd;
			
			
			printf("\n...product created\n\n");
				
			listLength +=1;

			
				
		}
		else if(listCreated > 0 && 3 == option){
			printf("\nWhat's the name of the product?: ");	
			char newName[20];
			scanf("%s", newName);
			
			deleteProduct(head,  newName);
						
		}
		else if(listCreated > 0 && 4 == option){
			struct product* temp = head;
			while(head->next != NULL){
			head = head->next;
			free(head);
			} free(temp);
		}
		else if(listCreated > 0 && 5 == option){
			printf("What is the name of the product?: ");
			char prodName[20];
			scanf("%s", prodName);
			
			display(search(head, prodName));	
		}
		else if(listCreated > 0 && 6 == option){
			displayAll(head);	
		}
		else if(listCreated > 0 && 7 == option){
			printf("\nWhat is the name of the product being purchased?: ");
			char itemName[20];
			scanf("%s", itemName);
			purchaseProduct(head, itemName);
			
			
			
		}
		else if(listCreated > 0 && 8 == option){
			printf("\nWhat is the name of the product being sold?: ");	
			char itemName[20];
			scanf("%s", itemName);
			sellProduct(head, itemName);


		}	
		else if(listCreated > 0 && 9 == option){
			printf("\nFIXME: SAVE METHOD");
			char* saveName = malloc(20 * sizeof(char));
			printf("\nPlease enter the full name of the save file: ");
			scanf("%s", saveName);
			char* temp = malloc(20 * sizeof(char));
			strcpy(temp, saveName);
			printf("\nAbout to call save method\n");
			saveStore(head, temp);
				
		}
		else if(0 == option){
			exit(1);
		}else{
			printf("\nSorry, you must have entered an invalid command. Are you sure you created the list?\n");
			
		}
	}
	return 0;
}
