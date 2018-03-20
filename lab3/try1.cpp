/*Создать класс изделие, с полями себестоимость, цена, время выполнения, стоимость нормочаса и название. 
Поле себестоимость в базовом классе не задано ( оперделяется в наследниках ). 
Поле цена вычисляется в базовом классе по формуле себестоимость + время выполнения * цену нормочаса.
Доступ к цене нормочаса недоступен из вне, остальные поля доступны. 
Создать в базовом классе метод, возврщающий описание изделия в формате "название", цена, время выполнения. 
Определить 3 класса наследника, Мышь, Клавиатура, монитор, задать им разные константные поля в конструкторе. 
При добавления изделия в очередь выводить строку "Изделие 'назвение' принято к работе, ожидаемое время выполнения 'время'". 
При удалении из очереди "Изделие 'назвение' произведено".*/

#include <iostream>
#include <locale.h>
#include <bitset>
#include"Trun.h"

using namespace std;


class Product
{
public:
	string name;														//называния
	string type;														//
	int cost;                                                           //sebestoimost
	int timeofwork;														//
	int costperhour;													//

	Product(string title)
	{
		this->name = title;												//
	}

	void setPrice()
	{
		this->price = this->cost + this->timeofwork * this->costperhour;//
		cout << this->info() << " принято к изготовлению.\n";
	}

	string info()
	{
		string response = "";											//
		response += type + " " + name + " ";
		response += "c ценой " + to_string(price) + " ";
		response += "и временем выполнения " + to_string(timeofwork);

		return response;
	};
	~Product()
	{
		cout << "Изделие " << info() << " произведено!" << endl;
	};

private:
	int price;

};

class Mouse: public Product
{
public:
	Mouse(string name) : Product(name)
	{
		this->name = name;												//
		this->type = "Мышь";											//тип товара
		this->cost = 500;												//
		this->timeofwork = rand() % 20 + 5;								//время выполнения
		this->costperhour = 200;										//цена нормочаса
		this->setPrice();												//конечный стоимость
	}

};

class Keyboard : public Product
{
public:
	Keyboard(string name) : Product(name)
	{
		this->name = name;
		this->type = "Клавиатура";
		this->cost = 1000;
		this->timeofwork = rand() % 20 + 5;
		this->costperhour = 300;
		this->setPrice();
	};

};

class Monitor : public Product
{
public:
	Monitor(string name) : Product(name)
	{
		this->name = name;
		this->type = "Монитор";
		this->cost = 700;
		this->timeofwork = rand() % 20 + 5;
		this->costperhour = 150;
		this->setPrice();
	}

};

int main()
{
	setlocale(LC_ALL, "Rus");

	string mouse, keybord, monitor;
	int menu;

	Trun<Product *> trun;
	do {
		cout << "1.Начат выполнеие мыша.";
		cout << "\n2.Начат выполнеие монитора.";
		cout << "\n3.Начат выполнеие клавиатура.";
		cout << "\n4.Показат 1 закоченный.";
		cout << "\n0.Выход.\n";
		cin >> menu;
		switch (menu) {
		case 1: {
			cout << "Называния продукта:\n";
			cin >> mouse;
			trun.push(new Mouse(mouse));	//mouse
			cout << "\nТекущий размер очереди: " << trun.getCurrentSize() << endl;
			break;
		}
		case 2: {
			cout << "Называния продукта:\n";
			cin >> monitor;
			trun.push(new Monitor(monitor));	//monitor
			cout << "\nТекущий размер очереди: " << trun.getCurrentSize() << endl;
			break;
		}
		case 3: {
			cout << "Называния продукта:\n";
			cin >> keybord;
			trun.push(new Keyboard(keybord));  //keyb
			cout << "\nТекущий размер очереди: " << trun.getCurrentSize() << endl;
			break;
		}
		case 4: {
			cout << "Производство:\n";
			trun.pop();
			break;
		}
		}
	} while (menu != 0);

	return 0;
}

