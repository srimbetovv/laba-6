#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class FootBallTeams {
protected:
	string type;
	string name;
public:
	FootBallTeams() {

	}
	FootBallTeams(string a, string a1) {
		type = a;
		name = a1;
	}
	void show() {
		cout << " Название команды: " << name << endl;
		cout << " Тип лиги: " << type << endl;
	}
	void changeType(string w) {
		type = w;
	}
	void changeName(string w) {
		name = w;
	}
	string getName() {
		return name;
	}
	string getType() {
		return type;
	}
};

class Info :virtual public FootBallTeams {
protected:
	int godOsnov;
	int kolvoTrofey;
public:
	Info() {
		godOsnov = 0;
		kolvoTrofey = 0;
	}
	Info(string a, string a1, int a2, int a3) :FootBallTeams(a, a1) {
		godOsnov = a2;
		kolvoTrofey = a3;
	}
	void changegodOsnov(int w) {
		godOsnov = w;
	}
	void changekolvoTrofey(int w) {
		kolvoTrofey = w;
	}
	int getkolvoTrofey() {
		return kolvoTrofey;
	}
	int getgodOsnov() {
		return godOsnov;
	}
	void show() {
		cout << " Год основания команды: " << godOsnov << endl;
		cout << " Кол-во трофеев: " << kolvoTrofey << endl;
	}
};

class TheFirstGame :virtual public FootBallTeams {
protected:
	int godDeb;
	int kolvoIgrokov;
public:
	TheFirstGame() {
		godDeb = 0;
		kolvoIgrokov = 0;
	}
	TheFirstGame(string a, string a1, int a2, int a3) :FootBallTeams(a, a1) {
		godDeb = a2;
		kolvoIgrokov = a3;
	}
	void changegodDeb(int w) {
		godDeb = w;
	}
	void changekolvoIgrokov(int w) {
		kolvoIgrokov = w;
	}
	int getkolvoIgrokov() {
		return kolvoIgrokov;
	}
	int getgodDeb() {
		return godDeb;
	}
	void show() {
		cout << " Год дебютной игры: " << godDeb << endl;
		cout << " Кол-во игроков: " << kolvoIgrokov << endl;

	}
};

class Country :public Info, public TheFirstGame {
private:
	string komanda;
	string country;
public:
	Country() {};
	Country(string a, string a1, string a2, string a3, int s, int s1, int s2, int s3) :TheFirstGame(a2, a3, s2, s3), Info(a2, a3, s, s1), FootBallTeams(a2, a3) {
		komanda = a;
		country = a1;
	}
	void show() {
		cout << " Страна: " << country << endl;
		FootBallTeams::show();
		Info::show();
		TheFirstGame::show();
		cout << " Введите команду с кем играл первый раз: " << komanda << endl;
	}
	void changekomanda(string w) {
		komanda = w;
	}
	void changecountry(string w) {
		country = w;
	}
	string getkomanda() {
		return komanda;
	}
	string getcountry() {
		return country;
	}
};

int chooseMenu();
string onlyWords();
int chooseWhoRed(Country*&, int);
int chooseWhatRed(Country*&, int);

string onlyWords() {
	string slovo;
	while (true) {
		int Knopka;
		char symbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					symbol = (char)Knopka;
					if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
						slovo = slovo + symbol;
						cout << symbol;
					}
				}
	}
	return slovo;
}

int inNum(int lr, int rr);
bool isNumNumeric();
bool isNumRangeCorrect(int num, int lr, int rr);

const int NUM_S = 0;
const int NUM_F = 2147483647;
int main() {
	setlocale(0, "rus");
	int nfootball = 0;
	Country* football = new Country[nfootball];
	while (true) {
		int choose = chooseMenu();
		if (choose == 1) {
			if (nfootball != 0) {
				while (true) {
					int choose1 = chooseWhoRed(football, nfootball);
					if (choose1 == nfootball) break;
					while (true) {
						int choose2 = chooseWhatRed(football, choose1);
						if (choose2 == 8) break;
						if (choose2 == 0) {
							cout << "Введите название команды: ";
							string ptr1 = onlyWords();
							football[choose1].changeName(ptr1);
							system("cls");
						}
						else
							if (choose2 == 1) {
								cout << "Введите тип лиги: ";
								string ptr1 = onlyWords();
								football[choose1].changeType(ptr1);
								system("cls");
							}
							else
								if (choose2 == 2) {
									cout << "Введите год основания: ";
									int ptr = inNum(NUM_S, NUM_F);
									football[choose1].changegodOsnov(ptr);
									system("cls");
								}
								else
									if (choose2 == 3) {
										cout << "Введите кол-во трофеев: ";
										int ptr = inNum(NUM_S, NUM_F);
										football[choose1].changekolvoTrofey(ptr);
										system("cls");
									}
									else
										if (choose2 == 4) {
											cout << "Введите страну: ";
											string ptr1 = onlyWords();
											football[choose1].changecountry(ptr1);
											system("cls");
										}
										else
											if (choose2 == 5) {
												cout << "Введите год дебютной игры: ";
												int ptr = inNum(NUM_S, NUM_F);
												football[choose1].changegodDeb(ptr);
												system("cls");
											}
											else
												if (choose2 == 6) {
													cout << "Введите кол-во игроков: ";
													int ptr = inNum(NUM_S, NUM_F);
													football[choose1].changekolvoIgrokov(ptr);
													system("cls");
												}
												else
													if (choose2 == 7) {
														cout << "Введите первую команду с кем играл: ";
														string ptr1 = onlyWords();
														football[choose1].changekomanda(ptr1);
														system("cls");
													}
					}
				}
			}
			else {
				cout << "Вы еще не добавили историй" << endl;
				system("pause");
				system("cls");
			}
		}
		else
			if (choose == 0) {
				Country sum;
				cout << "Введите название команды: ";
				string ptr1 = onlyWords();
				sum.changeName(ptr1);
				system("cls");
				cout << "Введите тип лиги: ";
				ptr1 = onlyWords();
				sum.changeType(ptr1);
				system("cls");
				cout << "Введите год основания команды: ";
				int ptr = inNum(NUM_S, NUM_F);
				sum.changegodOsnov(ptr);
				system("cls");
				cout << "Введите кол-во трофеев: ";
				ptr = inNum(NUM_S, NUM_F);
				sum.changekolvoTrofey(ptr);
				system("cls");
				cout << "Введите страну: ";
				ptr1 = onlyWords();
				sum.changecountry(ptr1);
				system("cls");
				cout << "Год дебютной игры: ";
				ptr = inNum(NUM_S, NUM_F);
				sum.changegodDeb(ptr);
				system("cls");
				cout << "Введите кол-во игроков : ";
				ptr = inNum(NUM_S, NUM_F);
				sum.changekolvoIgrokov(ptr);
				system("cls");
				cout << "Введите команду с кем играл первый раз: ";
				ptr1 = onlyWords();
				sum.changekomanda(ptr1);
				system("cls");
				nfootball++;
				Country* ptrr = new Country[nfootball];
				for (int i = 0; i < nfootball - 1; i++)
					ptrr[i] = football[i];
				football = ptrr;
				ptrr = NULL;
				delete[]ptrr;
				football[nfootball - 1] = sum;
			}
			else
				if (choose == 2) {
					for (int i = 0; i < nfootball; i++) {
						football[i].show();
						cout << endl;
						cout << endl;
					}
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) break;
	}
	return 0;
}

int inNum(int lr, int rr)
{
	int num;
	while (true)
	{
		cin >> num;
		if (isNumNumeric() && isNumRangeCorrect(num, lr, rr)) return num;
		cout << "Некорректный ввод! Введите числа в дипазоне от " << lr << " по " << rr << ": ";
	}
}
bool isNumNumeric()
{
	if (cin.get() == '\n') return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
}
bool isNumRangeCorrect(int num, int lr, int rr) { return (lr <= num && num <= rr); }

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> Добавить команду" << endl; }
		else { cout << " Добавить команду" << endl; }

		if (choose_menu == 1) { cout << " -> Редактировать команды" << endl; }
		else { cout << " Редактировать команды" << endl; }

		if (choose_menu == 2) { cout << " -> Просмотр всех командов" << endl; }
		else { cout << " Просмотр всех командов" << endl; }

		if (choose_menu == 3) { cout << " -> Завершить программу" << endl; }
		else { cout << " Завершить программу" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseWhoRed(Country*& football, int nVirus) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + (nVirus + 1)) % (nVirus + 1);

		for (int i = 0; i < nVirus; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << football[i].getName() << endl; }
			else { cout << " " << i + 1 << " - " << football[i].getName() << endl; }

		if (choose_menu == nVirus) { cout << " -> Выйти с выбора команды" << endl; }
		else cout << " Выйти с выбора команды" << endl;

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseWhatRed(Country*& football, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 9) % 9;

		if (choose_menu == 0) { cout << " -> Название команды: " << football[choose].getName() << endl; }
		else cout << " Название команды: " << football[choose].getName() << endl;

		if (choose_menu == 1) { cout << " -> Тип лиги: " << football[choose].getType() << endl; }
		else cout << " Тип лиги: " << football[choose].getType() << endl;

		if (choose_menu == 2) { cout << " -> Год основания команды: " << football[choose].getgodOsnov() << endl; }
		else cout << " Год основания команды: " << football[choose].getgodOsnov() << endl;

		if (choose_menu == 3) { cout << " -> Кол-во трофеев: " << football[choose].getkolvoTrofey() << endl; }
		else cout << " Кол-во трофеев: " << football[choose].getkolvoTrofey() << endl;

		if (choose_menu == 4) { cout << " -> Страна: " << football[choose].getcountry() << endl; }
		else cout << " Страна: " << football[choose].getcountry() << endl;

		if (choose_menu == 5) { cout << " -> Год дебютной игры: " << football[choose].getgodDeb() << endl; }
		else cout << " Год дебютной игры: " << football[choose].getgodDeb() << endl;

		if (choose_menu == 6) { cout << " -> Кол-во игроков в команде: " << football[choose].getkolvoIgrokov() << endl; }
		else cout << " Кол-во игроков в команде: " << football[choose].getkolvoIgrokov() << endl;

		if (choose_menu == 7) { cout << " -> Команда с кем играл первый раз: " << football[choose].getkomanda() << endl; }
		else cout << " Команда с кем играл первый раз: " << football[choose].getkomanda() << endl;

		if (choose_menu == 8) { cout << " -> Выйти в меню выбора страны " << endl; }
		else cout << " Выйти в меню выбора страны " << endl;


		keyboard_button = _getch();

		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}
