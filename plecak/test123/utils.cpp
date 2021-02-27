#include "utils.h"

std::vector<Bag> generate(const std::map<int, Item> &items, float max_capacity, int ammount_generations) {
	std::vector<Bag> result;

	int rand, items_size, temp = 0;
	items_size = items.size();
	int generations = 0;

	while (generations++ < ammount_generations) {
		Bag bag = create_bag(max_capacity);
		do {
			temp = 0;
			rand = std::rand() % items_size;
			if (is_in_bag(bag, rand)) rand = std::rand() % items_size;

			rand = search_not_in_bag(bag, items, rand);
			temp = rand;

			while (rand!= -1 && !add_to_bag(bag, items.at(rand), rand)) {

				rand = search_not_in_bag(bag, items, rand);

				if (temp == rand) 
					rand = -1;
			}
		} while (rand != -1);
		result.push_back(bag);
	}
	return result;
}

std::vector<Bag> selection(std::vector<Bag> bags, int quantity_selection) {
	std::vector<Bag> result;
	if (quantity_selection >= (int)bags.size()) return result;
	auto max = bags.begin();
	for (int j = 0; j < quantity_selection; ++j) {
		for (auto it = bags.begin(); it < bags.end(); ++it) 
			if (max->value < it->value) max = it;
		result.push_back(*max);
		bags.erase(max);
		max = bags.begin();
	}
	return result;
}

Bag cross(Bag bag1, Bag bag2, std::map<int,Item> &items) {
	int rand, temp;

	for (int i = 0; i < ((int)bag1.item_id.size()) / 2; ++i) {
		rand = std::rand() % (int)bag1.item_id.size();
		remove_item_from_bag(bag1, items, bag1.item_id[rand]);
	}
	temp = 0;

	do {
		temp = 0;
		rand = std::rand() % (int)bag2.item_id.size();		// w tym przypadku rand wsazuje na tablice item_id z bag2
		rand = search_not_in_secound_bag(bag1, bag2,  rand);
		temp = rand;

		while (rand != -1 && !add_to_bag(bag1, items[bag2.item_id[rand]], bag2.item_id[rand])) {
				rand = search_not_in_secound_bag(bag1, bag2, rand);
				if (temp == rand) rand = -1;
		}
	} while (rand != -1);
	return bag1;
}

Bag algorithme(std::map<int,Item> &items, float bag_max_capacity, int ammount_generations) {
	std::vector<Bag> generation1, generation2;
	std::vector<Bag> results;
	generation1 = generate(items, bag_max_capacity, ammount_generations);
	generation2 = generate(items, bag_max_capacity, ammount_generations);

	generation1 = selection(generation1, ammount_generations / 2);
	generation2 = selection(generation2, ammount_generations / 2);


	for (int i = 0; i < ammount_generations / 2; ++i) {
		results.push_back(cross(generation1[i], generation2[i], items));
	}

	for (int i = 0; i < ammount_generations / 2; ++i) {
		results.push_back(generation1[i]);
		results.push_back(generation2[i]);
	}
	results = selection(results, 1);
	return results[0];
}
