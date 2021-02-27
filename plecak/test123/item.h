#pragma once
#include <string>
#include <iostream>

struct Item {
	//int id;
	std::string name;
	float weight;
	float value;
};


Item create_item(std::string name, float weight, float value);

void show_item(Item item);
