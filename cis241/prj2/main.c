#include <stdio.h>
#include <stdlib.h>
#include "products.c"
int main(){
	char option = 'q'; //variable to hold choices
	printf(" 1: create an empty list	2: insert a product\n 
	3: Delete a product	4: Delete entire list\n
	5: Search a product	6: Display products in the list\n
	7: Purchase a product	8: Sell a product\n
	9: Save to file 	0: Exit\n");
	while(option != 0){
		scanf("%c", option);

		if('1' == option){
			//creating linked list of Products
			product *head = (product *)malloc(sizeof(product));
		}
		else if('2' == option){
			printf("\nPlease Enter the name of the product: ");
			char[20] newName = "";
			scanf(%s, newName);
	
			printf("\nPlease enter the product description 200 character max: ");
			char[200] newDesc = "";
			scanf(%s, newDesc);

			printf("\nPlease enter the number of units: ");
			int count = 0;
			scanf(%d, count);

			printf("\nPlease enter the price of the product: ");
			int newPrice = 0;
			scanf(%d, newPrice);

			struct product* newProd = malloc(sizeof(product));
			
			strcpy(newProd->name, newName);
			strcpy(newProd->unit, newDesc);
			newProd->quantity = count;
			newProd->price = newPrice;
			insert(newProd, head);		
			
			
			
				
		}
		else if('3' == option){
			printf("\nWhat's the name of the product?: ");	
			char[20] newName = "";
			scanf(%s, newName);
			
			deleteProduct(head, search(head, newName) );
						
		}
		else if('4' == option){
			deleteAll(head);
		}
		else if('5' == option){
			printf("What is the name of the product?: ");
			char[20] prodName = ""
			scanf(%s, prodName);
			
			display(search(head, prodName));	
		}
		else if('6' == option){
			displayAll(head);	
		}
		else if('7' == option){
			printf("What is the name of the product being purchased?: ");
			char[20] itemName = "";
			scanf(%s, itemName);
			purchase(head, itemName);
			
			
			
		}
		else if('8' == option)
	
		}
		else if('9' == option)
	
		}
		else if('0' == option){
			exit(1);
		}
	}
	return 0;
}
