#include "CartItem.h"

CartItem::CartItem(){};

CartItem::CartItem(string d, double c, int q){
	desc = d;
	cost = c;
	quantity = q;
};

string CartItem::getDesc(){
	return desc;
};

double CartItem::getCost(){
	return cost;
};

int CartItem::getQuantity(){
	return quantity;
};

void CartItem::setDesc(string d){
	desc = d;
}

void CartItem::setCost(double c){
	cost = c;
}

void CartItem::setQuantity(int q){
	quantity = q;
}

double CartItem::totalPrice(){
	return cost * quantity;
}
