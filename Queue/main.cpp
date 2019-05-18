#include <iostream>
#include <random>
#include <time.h>
#include "queue.h"

int main()
{
    srand(time(NULL));
    NodeQueue<int> Queue;
    int size;
    std::cout<<"Input size Queue: ";
    std::cin>>size;
    for(int i = 0; i != size; ++i)
    {
        Queue.push_back(rand()%10);
    }
    Queue.print();
    std::cout<<Queue.front()<<std::endl; //первый элемент нашего списка
    std::cout<<Queue.min_el()<<std::endl; // мин элемент
    std::cout<<Queue.accumulate([](int a){return a>0;})<<std::endl;
    //сумма элементов
    return 0;
}
