#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <Windows.h>
#include <list>

void TryStoi(std::string stringvar, int& variable) {
	try {
		variable = stoi(stringvar);
	}
	catch (std::invalid_argument& e) {
		std::cerr << "Catched std::invalid_argument: " << e.what() << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cerr << "Catched std::out_of_range:" << e.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void TryStod(std::string stringvar, double& variable) {
	try {
		variable = stod(stringvar);
	}
	catch (std::invalid_argument& e) {
		std::cerr << "Catched std::invalid_argument: " << e.what() << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cerr << "Catched std::out_of_range: " << e.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void Calculate(std::string wybor, double liczba1, double liczba2, double& wynik) {
	if (wybor == "dodawanie")
		wynik = liczba1 + liczba2;
	else if (wybor == "odejmowanie")
		wynik = liczba1 - liczba2;
	else if (wybor == "mnozenie")
		wynik = liczba1 * liczba2;
	else if (wybor == "dzielenie")
		wynik = liczba1 / liczba2;
	else if (wybor == "potegowanie")
		wynik = pow(liczba1, liczba2);
	else if (wybor == "pierwiastkowanie")
		wynik = pow(liczba1, 1 / liczba2);
	else {
		std::cout << "Masz podac typ dzialania." << std::endl;
	}
}

std::string ToLower(const std::string& str) {
	std::string result = str;
	for (char& c : result) {
		c = std::tolower(c);
	}
	return result;
}

int main(void) {
	/***** Lista działań, zrobione na obsługę błędu *****/
	std::list<std::string> dzialania{
		"dodawanie",
		"odejmowanie",
		"mnozenie",
		"dzielenie",
		"potegowanie",
		"pierwiastkowanie"
	};
	/***** Zmienne *****/
	std::string wybor;
	std::string liczba1s;
	std::string liczba2s;
	std::string liczbadalej;
	std::string liczba3s;
	double liczba1;
	double liczba2;
	double liczba3;
	double wynik = 0;
	bool found = false;
	/***** Program *****/
	std::cout << " - Kalkulator  C++ - " << std::endl;
	std::cout << " -  dzikmikrofala  - " << std::endl;
	std::cout << "\nWybierz typ dzialania: \n\ndodawanie \nodejmowanie \nmnozenie \ndzielenie \npotegowanie \npierwiastkowanie \n\nWybor: ";
	std::cin >> wybor;
	ToLower(wybor);
	for (const auto& choice : dzialania) {
		if (wybor == choice) {
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "Masz wybrac 1 z typow dzialan!" << std::endl;
		return 1;
	}
	std::cout << "Podaj 1 liczbe: ";
	std::cin >> liczba1s;
	TryStod(liczba1s, liczba1);
	std::cout << "Podaj 2 liczbe: ";
	std::cin >> liczba2s;
	TryStod(liczba2s, liczba2);
	if (liczba2 == 0) {
		std::cout << "Nie dziel przez zero!" << std::endl;
		return 1;
	}
	Calculate(wybor, liczba1, liczba2, wynik);
	std::cout << "Wynik: " << wynik << std::endl;
	std::cout << "Czy chcesz zrobic kolejne dzialanie na wyniku? (tak/nie): ";
	std::cin >> liczbadalej;
	if (ToLower(liczbadalej) == "nie") {}
	else if (ToLower(liczbadalej) == "tak") {
		int j = 0;
		while (j < 1) {
			system("cls");
			std::cout << "Wybierz typ dzialania: \n\ndodawanie \nodejmowanie \nmnozenie \ndzielenie \npotegowanie \npierwiastkowanie \n\nWybor: " << std::endl;
			std::cout << "Aktualny wynik: " << wynik << std::endl << std::endl;
			std::cout << "Wybor: ";
			std::cin >> wybor;
			ToLower(wybor);
			std::cout << "Podaj liczbe: ";
			std::cin >> liczba3s;
			TryStod(liczba3s, liczba3);
			Calculate(wybor, wynik, liczba3, wynik);
			std::cout << "Wynik: " << wynik << std::endl;
			std::cout << "Czy chcesz zrobic kolejne dzialanie na wyniku? (tak/nie): ";
			std::cin >> liczbadalej;
			if (ToLower(liczbadalej) == "nie") {
				j++;
			}
			else if (ToLower(liczbadalej) == "tak") {}
			else {
				std::cout << "Podaj odpowiedz tak lub nie!" << std::endl;
				return 1;
			}
		}
	}
	else {
		std::cout << "Podaj odpowiedz tak lub nie!" << std::endl;
		return 1;
	}
	return 0;
}