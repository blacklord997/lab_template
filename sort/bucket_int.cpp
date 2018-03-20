//Все изменения записаны в комментариях справа от кода

#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <locale.h>

using namespace std;

int highestNum = 190;                                                           //Здесь задается самое большое число массива
int countBuckets = 5;                                                           //Здесь хранится число создаваемых корзин

void bucketSort( int arr[], int n )
{
	// 1) Создать countBuckets пустых ведер
	vector<int> b[countBuckets];                                                //Создаем countBuckets корзин, а не n штук
	
	// 2) Поместим элементы массива в разные ковши
	for (int i = 0; i<n; i++)
	{
		int bi = arr[i] * countBuckets/highestNum ; // индекс в ковши            //Индекс вычисляется пропорцией(при необходимости могу объяснить)
		b[bi].push_back( arr[i] );
	}
	
	// 3) Сортировка отдельных ведер
	for (int i = 0; i<countBuckets; i++)                                        //Проходим по countBuckets корзинам
		sort(b[i].begin(), b[i].end());
	
	// 4) Объединить все ведра в arr []
	int index = 0;
	for (int i = 0; i < countBuckets; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

int main() 
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	unsigned int start_time, end_time;
	int ques;
	int n;
	char q;
	char yes = 'y';
	cout << "Вводите размер массива: ";
	cin >> n;

	int *mas = new int[n];

	for (int i = 0; i < n; i++) 
	{
		mas[i] = ( rand() % highestNum );                                         //я записал highestNum, а не какое-то число, потому что оно также требуется в предыдущей функции. Так проще менять это число)
	}
	cout << "Вводить созданная массив на экран: (y or n) ";
	cin >> q;
	if (q == yes) 
	{
	    for (int i = 0; i < n;i++) 
	    {
		    cout << mas[i] << " ";
	    }
	}
	cout << endl;
	cout << "Сортировку:\n1. Начать\n0. Выйти\n";
	cin >> ques;

	switch (ques)
	{
	    case 1: 
	    {
			start_time = clock();
			bucketSort(mas, n);
			end_time = clock();
			for (int i = 0; i < n; i++) 
			{
				cout << mas[i] << " ";
			}
		    break;
		}
		case 0:
		{
			cout<<"Сортировка не выполнено!";
			break;
		}
		default : cout << "Не верный выбор!\n";
	}
	
	
	cout << "runtime = " << ( (double)(end_time - start_time) ) / (CLOCKS_PER_SEC) <<endl;

	return 0;
}