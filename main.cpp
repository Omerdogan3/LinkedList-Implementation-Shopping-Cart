#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "ShoppingCart.cpp"

using namespace std;


	ShoppingCart shop; //stores all items in shop object by object.
	ShoppingCart cart; //user's cart.

	void userInput(); //manages userscreen
	string fileOpen(); //open file and return it as a single text string
	void LineCalc(string text); //take text string and compute it line by line
	void convertToItem(string text); //take line string and add it to the shoppingcart as an object



int main(){


	string text = fileOpen();
	LineCalc(text);
	shop.DisplayItems(shop.list);

	userInput();

	//after finish purchase it prints result
		cout << "Purchased Items" << endl;
		cart.DisplayItems(cart.cartlist);
		cout << "Total Cost" << endl;
		cout << cart.totalCost(cart.cartlist) << "$ " << endl;

return 0;
}

void userInput(){
	int usin=-1;
	int pos;
	string desc;
	float cost;
	int quan;

	while(usin!=7){
		cout << " ______________________________" << endl;
		cout << "| 1-Show Cart                  " << endl;
		cout << "| 2-Buy an Item                " << endl;
		cout << "| 3-Get Total Cost             " << endl;
		cout << "| 4-Remove an Item From Cart   " << endl;
		cout << "| 5-Get Cost of an Item in Shop" << endl;
		cout << "| 6-Add an Extra Item          " << endl;
		cout << "| 7-Complete Purchase          " << endl;
		cout << " ______________________________" << endl;
		cin >> usin;

		switch(usin){
			case 1:
				if(cart.cartlist.isEmpty()){
					cout << "Your Cart Empty!" << endl;
				}
				shop.DisplayItems(cart.cartlist);
				break;

			case 2:
				cout << "Please enter an item to buy" << endl;
				cin >> pos;
				if(shop.list.retrieve(pos).getQuantity()==0){
					cout << "This item not in stock" << endl;
					break;
				}
				cart.addItem(cart.cartlist,shop.list.retrieve(pos));
				break;

			case 3:
				if(cart.cartlist.isEmpty()==1){
					cout << 0 << endl;
					break;
				}
				cout << cart.totalCost(cart.cartlist) << "$ " << endl;
				break;

			case 4:
				cout << "Please select a position to remove" << endl;
				cin >> pos;
				cart.remove(cart.cartlist,pos);
				break;

			case 5:
				cout << "Please select a position to get cost" << endl;
				cin >> pos;
				//if you dont enter a valid position it gives assertion error.
				cout << shop.totalCostAt(shop.list,pos) << "$" << endl;
				break;

			case 6:
				cout << "Description: ";
				cin >> desc;
				cout << "Cost: ";
				cin >> cost;
				cout << "Quantity: ";
				cin >> quan;

				CartItem obj(desc,cost,quan);
				cart.addItem(cart.cartlist,obj);
				break;

		}
	}
}

string fileOpen(){
	string line,text;
	int productNum=1;
 	ifstream myfile("products.txt");

	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
    		text = text + line + "\n";
      		productNum++;
    	}
    myfile.close();
  }
  else cout << "Unable to open file";

  return text;
}

void LineCalc(string text){
	istringstream inss(text);
	string line;
	int i=1;
	while(getline(inss,line)){
		convertToItem(line);
	}
}

void convertToItem(string text){
	istringstream inss(text);
	string word;
	int wordCounter=0;
	CartItem item;

	inss>>word;
	item.setDesc(word);
	inss>>word;
	item.setCost(atof(word.c_str()));
	inss>>word;
	item.setQuantity((int)atof(word.c_str()));

	shop.addItem(shop.list, item);
}
