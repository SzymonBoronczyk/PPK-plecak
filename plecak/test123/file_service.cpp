#include "file_service.h"



std::map<int, Item> read_from_file(const std::string &file_name) {

	std::ifstream file(file_name);
	std::map<int, Item> result;
	std::stringstream ss;
	std::string fileText, name;
	float weight, value;
	int i = 0;

	while (getline(file, fileText)) {
		ss << fileText;
		ss >> name >> weight >> value;
		result[i++] = create_item(name, weight, value);
		ss.clear();
	}
	file.close();

	return result;
}


void save_to_file(std::vector<Bag> bags, std::map<int, Item> items, std::string file_name) {
	std::ofstream file(file_name);
	std::stringstream ss;
	int number_generation = 1;
	for (int j = 0; j < (int)bags.size(); ++j) {
		ss << "Generacja: " << number_generation++
			<< " waga: " << bags[j].capacity << "/" << bags[j].max_capacity
			<< " wartosc: " << bags[j].value << std::endl;
		int temp_id;
		for (int i = 0; i < (int)bags[j].item_id.size(); ++i) {
			temp_id = bags[j].item_id[i];
			ss << items.at(temp_id).name << " " << items.at(temp_id).weight << " " << items.at(temp_id).value << std::endl;
					
		}
	}
	file << ss.rdbuf();
	file.close();
}
