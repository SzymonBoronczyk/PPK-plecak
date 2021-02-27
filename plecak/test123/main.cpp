#include <iostream>
#include "utils.h"
#include "file_service.h"
#include "view.h"
using namespace std;

int main(int argc, char *argv[]) {
	string read_file = "def_read.txt", save_file = "def_result.txt";
	float max_capacity = 5.0f;
	int count_generations = 5, count_bags = 2;

	view(argc, argv, &read_file, &save_file, &max_capacity, &count_generations, &count_bags);

	srand(time(NULL));

	map<int, Item> items = read_from_file(read_file);
	vector<Bag> results;
	Bag result;

	for (int i = 0; i < count_bags; ++i) {
		result = algorithme(items, max_capacity, count_generations);
		show_bag_2(result);
		results.push_back(result);
	}

	save_to_file(results, items, save_file);
	
	return 0;
}
