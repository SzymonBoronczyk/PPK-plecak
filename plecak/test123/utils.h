#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <fstream>
#include <map>
#include "item.h"
#include "bag.h"


std::vector<Bag> generate(const std::map<int,Item> &items, float max_capacity, int ammount_generations);

std::vector<Bag> selection(std::vector<Bag> bags, int quantity_selection);

Bag cross(Bag bag1, Bag bag2, std::map<int, Item> &items);

Bag algorithme(std::map<int, Item> &items, float bag_max_capacity, int ammount_generations);
