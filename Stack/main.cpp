#include <iostream>
#include <iterator>
#include <random>
#include "Stack.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    Stack<int> St;
    int n;
    std::cout<<"Input size stack: ";
    std::cin>>n;
    for(int i = 0; i!=n; ++i)
    {
        St.push(i);
    }
    St.print();
    std::cout<<St.top()<<std::endl;//выводит последний элемент
    St.pop();//удаляет последний элемент
    St.print();
    std::cout<<St.accumulate([](int a){return a> 0;})<<std::endl;
    return 0;
}
