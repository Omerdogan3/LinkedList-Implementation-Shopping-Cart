#include "ShoppingCart.h"
void ShoppingCart::addItem(LinkedList<CartItem> &c,CartItem item){
	c.append(item);
}

void ShoppingCart::DisplayItems(LinkedList<CartItem> c){
	for(int i=1; i<=c.getLength(); i++){
		cout << i << " - " << c.retrieve(i).getDesc() << " "<<
		c.retrieve(i).getCost()<< "$ " << c.retrieve(i).getQuantity() << endl;
	}
}

void ShoppingCart::remove(LinkedList<CartItem> &c1,int pos){
	c1.remove(pos);
}

double ShoppingCart::totalCostAt(LinkedList<CartItem> c1, int pos){

	CartItem Item = c1.retrieve(pos);
	double c = Item.getCost();
	int q = Item.getQuantity();

	return c*q;
}

double ShoppingCart::totalCost(LinkedList<CartItem> c1){
	int q;
	double c,total;
	for(int i=1; i<=c1.getLength(); i++){
		q = c1.retrieve(i).getQuantity();
		c = c1.retrieve(i).getCost();
		total+= q*c;
	}
	return total;
}
