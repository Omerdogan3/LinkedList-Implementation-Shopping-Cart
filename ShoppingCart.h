#include "LinkedList.h"
#include "CartItem.cpp"

class ShoppingCart{
	public:
		void addItem(LinkedList<CartItem> &c,CartItem item); //
		void DisplayItems(LinkedList<CartItem> c); //Display all items as decr,cost,quantity
		void remove(LinkedList<CartItem> &c1,int pos); //Removes an item at given position
		double totalCostAt(LinkedList<CartItem> c1, int pos); // Returns an item's total cost at given position
		double totalCost(LinkedList<CartItem> c1); // Returns total cost of all items
		
		LinkedList<CartItem> list; //all items
		LinkedList<CartItem> cartlist; //cart items		
	
};

