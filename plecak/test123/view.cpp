#include "view.h"


void view(int argc, char *argv[], std::string *read_file,
	std::string *save_file, float *max_capacity,
	int *count_generations, int *count_bags) {

	for (int i = 1; i < argc; i += 2) {
		if (*argv[i] == '-') {
			if (*(argv[i] + 1) == 'h') {
				instruction(); break;
			}
			else if (argv[i + 1] != nullptr) {
				if (*(argv[i] + 1) == 'i') 
					*read_file = argv[i + 1];

				else if (*(argv[i] + 1) == 'o') 
					 *save_file = argv[i + 1];

				else if (*(argv[i] + 1) == 'p') 
					 *max_capacity = atof(argv[i + 1]);

				else if (*(argv[i] + 1) == 'q') 
					*count_bags = atoi(argv[i + 1]);

				else if (*(argv[i] + 1) == 'n') 
					*count_generations = atoi(argv[i + 1]);
			}

		}
	}
}

void instruction() {
	std::cout << "==========Krotka instrukcja==========" << std::endl;
	std::cout << "Program korzystajac z algorytmu genetycznego probuje rozwiazac problem wypelnienia plecaka w jak najbardziej korzystny sposob," <<
		"argumenty do programu sa przesylane w nastepujacy sposob: \n" <<
		"-i plik wejsciowy opisujacy zbior przedmiotow" << std::endl <<
		"-o plik wyjsciowy z najlepszymi rozwiazaniami w kolejnych pokoleniach" << std::endl <<
		"-p ladownosc plecaka" << std::endl <<
		"-g liczba generacji (liczba plecakow)" << std::endl <<
		"-n liczba osobnikow w ramach generacji" << std::endl <<
		"-h wyswietlenie wszystkich mozliwych przelacznikow oraz krotka instrukcja" << std::endl <<
		"program posiada parametry domyslne ktore zostana wywolane po wyswietleniu instrukcji: " << std::endl <<
		"test123.exe -i def_read.txt -o def_result -p 8.2 -q 20 -n 5" << std::endl<< std::endl;
}