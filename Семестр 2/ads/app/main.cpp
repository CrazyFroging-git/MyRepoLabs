#include "player.hpp"

int main() {
	std::srand((unsigned)std::time(nullptr));
	setlocale(LC_ALL, "Rus");
	lootbox test1("TestCase1", {bow, water, grass});
	lootbox test2("TestCase2", {woodSword, diamondSword, dolg, avtomat});
	Player alex2("df","afk", {bow}, 10, 1, 1);
	alex2.openBox(test1);
	alex2.printinfo();
	std::cout << "=======" << std::endl;
	avtomat.printItem();
	std::cout << "=======" << std::endl;
	test1.printLootbox();
	std::cout << "Интерес: 5/5" << "\n" << "Наполненность: ?/5" << "\n" << "Сложность: 3.5/5" << "\n";
	return 0;
}