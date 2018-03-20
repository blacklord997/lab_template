#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <locale.h>

using namespace std;

void bucketSort(float arr[], const int n)
{
	// 1) Создать n пустых ведер
	vector<float> b[n];
	// 2) Поместим элементы массива в разные ковши
	for (int i = 0; i<n; i++)
	{
		int bi = n * arr[i]; // индекс в ковши
		 //cout<<"bi="<<bi<<" ";
		 //cout<<"arr["<<i<<"]="<<arr[i]<<" "<<endl;
		b[bi].push_back(arr[i]);
	}
	// 3) Сортировка отдельных ведер
	for (int i = 0; i<n; i++)
		sort(b[i].begin(), b[i].end());
	// 4) Объединить все ведра в arr []
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	unsigned int start_time, end_time;
	int ques;
	int n, k;
	char q;
	char yes = 'y';
	cout << "Вводите размер массива: ";
	cin >> n;
	cout<<"Сколко цифр после запитой?";
	cin >> k;
	float *mas = new float[n];

	for (int i = 0; i < n; i++) {
		mas[i] = (rand() % (n*k)) /(pow(10.0, k));
	}
	cout << "Выводить созданный массив на экран: (y or n) ";
	cin >> q;
	switch (q == yes) {
	case 1:for (int i = 0; i < n;i++) {
		cout << mas[i] << " ";
	}
		   break;
	}
	cout << endl;
	cout << "Сортировку:\n1. Начать\n0.Выйти\n";
	cin >> ques;
	if (ques >= 0 && ques <= 1) {
		switch (ques)
		{
		case 1: {
			start_time = clock();
			bucketSort(mas, n);
			end_time = clock();
			for (int i = 0; i < n; i++) {
				cout << mas[i] << " ";
			}
			break;
		}
		case 0:{
			cout<<"Сортировка не выполнено!";
			break;
		}
		}
	}
	else cout << "Не верный выбор!\n";
	cout << "runtime = " << (end_time - start_time) / (CLOCKS_PER_SEC / 1000.0) <<endl;

	return 0;
}