#pragma once
#include <fstream>
#include <sstream>
#include <map>
#include "item.h"
#include "bag.h"


std::map<int,Item> read_from_file(const std::string &file_name);

void save_to_file(std::vector<Bag> bags, std::map<int, Item> items, std::string file_name);
