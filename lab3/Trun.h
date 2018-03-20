#include <iostream>

using namespace std;
template <typename T>
class Trun
{
public:
	Trun();
	~Trun();
	void push(T);
	T read();
	void pop();
	int getCurrentSize();
	bool isEmpty();
private:
	void resize();
	int size;
	int current;
	T * trun;
	const int changer = 20;
	const int differCondition = 2;                                          //условие увеличения очередь
};

template <typename T>
Trun<T>::Trun()
{
	size = 3;
	current = 0;
	trun = new T[size];
}
template <typename T>
Trun<T>::~Trun()
{
	delete[] trun;
}
template <typename T>
int Trun<T>::getCurrentSize()
{
	return size;
}
template <typename T>
void Trun<T>::resize()
{
	T * temp = new T[size + changer];
	for (int i = 0; i<size; i++)
	{
		temp[i] = trun[i];
	}
	delete[] trun;
	trun = temp;
	size += changer;
}
template <typename T>
void Trun<T>::push(T num)
{
	if (getCurrentSize() - current < differCondition)
	{
		resize();
	}

	trun[current++] = num;

}
template <typename T>
T Trun<T>::read()
{
	return trun[0];
}

template <typename T>
void Trun<T>::pop()
{
	if (current > 0)
	{
		T cur = trun[0];
		delete cur;
		for (int i = 0; i<current - 1; i++)
		{
			trun[i] = trun[i + 1];
		}
		current--;
	}
	else {
		cout << "Все изделия готово!! \n";
	}

}
