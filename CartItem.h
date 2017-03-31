#ifndef CartItem_
#define CartItem_
#include <iostream>
#include <string>
using namespace std;

class CartItem{
	private:
		string desc;
		double cost;
		int quantity;
		
	public:
		CartItem(); //default constructor
		CartItem(string d, double c, int q); //constructor
		
		string getDesc(); //returns Description of an item
		double getCost(); //returns Cost of an item
		int getQuantity(); //returns Quantity of an item
		
		void setDesc(string d); //sets Description of an item
		void setCost(double c); //returns Cost of an item
		void setQuantity(int q); //returns Quantity of an item
		
		double totalPrice(); //returns total price of an item		
};

#endif
