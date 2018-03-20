#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <locale.h>

using namespace std;

void bucketSort(float arr[], const int n)
{
	// 1) Create n empty buckets
	vector<float> b[n];

	// 2) Put array elements in different buckets
	for (int i = 0; i<n; i++)
	{
		int bi = n*arr[i]; // Index in bucket
		b[bi].push_back(arr[i]);
	}

	// 3) Sort individual buckets
	for (int i = 0; i<n; i++)
		sort(b[i].begin(), b[i].end());

	// 4) Concatenate all buckets into arr[]
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
	cout<<"Сколко цыфр после запитой?";
	cin >> k;
	float *mas = new float[n];

	for (int i = 0; i < n; i++) {
		mas[i] = (rand() % 19*k*2) /(pow(10.0, k));
	}
	cout << "Вводить созданная массив на экран: (y or n) ";
	cin >> q;
	switch (q == yes) {
	case 1:for (int i = 0; i < n;i++) {
		cout << mas[i] << " ";
	}
		   break;
	}
	cout << endl;
	cout << "Сортировать:\n0. Начать\n1.Выйти";
	cin >> ques;
	if (ques >= 0 && ques <= 1) {
		switch (ques)
		{
		case 0: {
			start_time = clock();
			bucketSort(mas, n);
			end_time = clock();
			for (int i = 0; i < n; i++) {
				cout << mas[i] << " ";
			}
			break;
		}
		case 1:{
			cout<<"Сортировка не выполнено!";
			break;
		}
		}
	}
	else cout << "Не верный выбор!\n";
	cout << "runtime = " << end_time - start_time << endl; // время работы программы

	return 0;
}