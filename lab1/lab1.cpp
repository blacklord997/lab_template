// lab_stack.cpp: определяет точку входа для консольного приложения.
//


#include <iostream>
#include <locale.h>
#include <stack>

using namespace std;

struct steck{
	int x;
	steck *next, *head;
};

void add(int x, steck *&list) {
	steck *temp = new steck; 
	temp->x = x; 
	temp->next = list->head; 
	list->head = temp; 
}

void show(steck *list) {
	steck *temp = new steck;
	while (temp != NULL) {
		cout << temp->x;
		temp = temp->next;
	}

}


int main()
{
	setlocale(LC_ALL, "RUS");
	///////////////////////////////////////
	steck *list = new steck;
	list->head = NULL;
	///////////////////////////////////////
	int n, i;
	cin >> n;
	while(n>0){
		cin >> i;
		add(i, list);
		n--;
	}
	
	cout << "внутри: ";
	for (int i = 0; i < n; i++) {
		show(list);
	}




	delete list->head;
	delete list;
    return 0;
}

