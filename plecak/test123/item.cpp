#include "item.h"

Item create_item(std::string name, float weight, float value) {
	Item item;
	item.name = name;
	item.weight = weight;
	item.value = value;
	return item;
}

void show_item(Item item) {
	std::cout << "Nazwa: " << item.name << std::endl;
	std::cout << "Waga: " << item.weight << std::endl;
	std::cout << "Wartosc: " << item.value << std::endl;
}
