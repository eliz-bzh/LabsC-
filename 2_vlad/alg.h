#ifndef ALG_H_INCLUDED
#define ALG_H_INCLUDED
#include <algorithm>
#include <iostream>
#define print_contenier(first, last) std::for_each (first, last, [](int value) {std::cout << value << " ";});
#include <chrono>
#include <thread>
#include <cmath>
#include <iostream>

void merge (int* first, int* middle, int* last)
{
  int n = last - first;
  std::cout<<"merge part, n= " << n<<"\n";
  std::cout<<"merge part, middle= " << *middle << "\n";
  std::cout<<"merge part, last= "<<*last << "\n";
  int* deck = new int[n];

  int* left = first;
  std::cout<<"merge part, left = first " << *left<< "\n";
  int* right = middle;
  std::cout << "merge part, right = middle " << *right << "\n";
  for (int* d = deck; d!=deck+n;++d){
    if (left == middle) *d = *right++;
    else if (right==last ) *d=*left++;
    else if (*left < *right) *d = *left++;
    else *d = *right++;}

  int *d = deck;
  while (first != middle) *first++ = *d++;
  while (middle != last) *middle++ = *d++;

  delete[] deck;
}


void mergesort (int* first, int* last)
{
  int n = last - first;
  if (n <= 1) return;
  std::cout << "n= " << n;
  int* middle = first + n/2;
  std::cout << "first = "<< *first << "middle = "<< *middle<<"\n";
  mergesort (first, middle);
  mergesort (middle, last);
  merge (first, middle, last);
}




template<class Iter>
void random(Iter arr, int size)
{
    for (int i=0; i!=size; i++)
    {
        arr[i] = std::rand()%10;
    }
}
template<class Iter>
void print(Iter arr, int size)
{
    for(int i = 0; i!=size; ++i)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
//главная функция


#endif // ALG_H_INCLUDED
