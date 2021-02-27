#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "item.h"

struct Bag {
	std::vector<int> item_id;
	float capacity; // udüwig
	float max_capacity;
	float value;
};


void clear_bag(Bag &bag);

bool add_to_bag(Bag &bag, const Item &item, int key);

bool remove_item_from_bag(Bag &bag, std::map<int,Item> &items, int remove_id);

Bag create_bag(float maxCapacity);

void show_bag(Bag &bag, std::map<int,Item> items);

void show_bag_2(Bag &bag);

bool is_in_bag(Bag &bag, int item_id);

int search_not_in_bag(Bag &bag, const std::map<int,Item> &items, int item_id_start);

int search_not_in_secound_bag(Bag &bag1, Bag &bag2, int item_id_start);
