// реализовать стек (см предыдущую лабу) с использованием ооп

//см ссылки в telegram(лекции 9-11)

#include <iostream>

using namespace std;
template <typename T>
class Queue
{
    public:
        Queue();
        ~Queue();
        void push(T);
        T read();
        void pop();
        int getCurrentSize(); //skolko v ocherede
        bool isEmpty();
    private:
        void resize();
        int size;
        int current;
        T * queue;
        const int changer = 20;
        const int differCondition = 2;                                          //условие увеличения очередь
};

template <typename T>
Queue<T>::Queue()
{
    size = 5;
    current = 0;
    queue = new T[size];
}
template <typename T>
Queue<T>::~Queue()
{
    delete [] queue;
}
template <typename T>
int Queue<T>::getCurrentSize()
{
    return size;
}
template <typename T>
void Queue<T>::resize()
{
    T * temp = new T[size+changer];
    for (int i=0; i<size; i++)
    {
        temp[i] = queue[i];
    }
    delete [] queue;
    queue = temp;
    size += changer;
}
template <typename T>
void Queue<T>::push(T num)
{
    if (getCurrentSize() - current < differCondition)
    {
        resize();
    }
    
    queue[current++] = num;
    
}
template <typename T>
T Queue<T>::read()
{
    return queue[0];
}

template <typename T>
void Queue<T>::pop()
{
    if (current > 0)
    {
        T cur = queue[0];
        delete cur;
        for (int i=0; i<current-1; i++)
        {
            queue[i] = queue[i+1];
        }
        current--;
    } else {
        cout << "EMPTY QUEUE\n";
    }
    
}
