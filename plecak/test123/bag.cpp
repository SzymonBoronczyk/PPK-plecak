#include "bag.h"


void clear_bag(Bag &bag) {
	bag.item_id.clear();
	bag.capacity = 0;
	bag.value = 0;
}

bool add_to_bag(Bag &bag, const Item &item, int key) {

	if (bag.capacity + item.weight <= bag.max_capacity) {
		bag.capacity += item.weight;
		bag.value += item.value;
		bag.item_id.push_back(key);
		return true; // z powodzeniem dodano przedmiot
	}
	return false; // przedmiot za ciê¿ki
}

bool remove_item_from_bag(Bag &bag, std::map<int,Item> &items, int remove_id) {
	if ((int)bag.item_id.size() < remove_id || remove_id < 0) return false;
	bag.value -= items[remove_id].value;
	bag.capacity -= items[remove_id].weight;

	for (auto it = bag.item_id.begin(); it < bag.item_id.end(); ++it) {
		if (*it == remove_id) {
			bag.item_id.erase(it);
			return true;
		}
	}
	return false;
}

Bag create_bag(float maxCapacity) {
	Bag bag;
	bag.max_capacity = maxCapacity;
	bag.capacity = 0;
	bag.value = 0;
	return bag;
}

void show_bag(Bag &bag, std::map<int,Item> items) {
	for (auto items_id : bag.item_id)
		show_item(items[items_id]);
}

void show_bag_2(Bag &bag) {
	std::cout << "Pojemnosc: " << bag.capacity << " / " << bag.max_capacity << std::endl;
	std::cout << "Wartosc: " << bag.value << std::endl;
	std::cout << "Przedmioty: ";

	for (auto items_id : bag.item_id)
			std::cout << items_id << " ";

	std::cout << std::endl << std::endl;
}

bool is_in_bag(Bag &bag, int item_id) {
	for (auto bag_item_id : bag.item_id)
		if (bag_item_id == item_id) return true;
	return false;
}

int search_not_in_bag(Bag &bag, const std::map<int,Item> &items, int item_id_start) {
	int temp = 0;
	while (is_in_bag(bag, item_id_start)) {
		temp++;
		item_id_start = (item_id_start + 1) % (int)(items.size());
		if (temp == (int)(items.size())) return -1;
	}
	return item_id_start;
}

int search_not_in_secound_bag(Bag &bag1, Bag &bag2, int item_id_start) {
	int temp = 0;
	while (is_in_bag(bag1, bag2.item_id[item_id_start])) {
		temp++;
		item_id_start = (item_id_start + 1) % (int)(bag2.item_id.size());
		if (temp == (int)(bag2.item_id.size())) return -1;
	}
	return item_id_start;
}
