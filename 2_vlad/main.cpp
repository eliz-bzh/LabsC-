//#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <vector>

template<class T>
void merge(std::vector<T>& buf, size_t l, size_t r, size_t m)
{
    if (l >= r || m < l || m > r)
        return;
    if (r == l + 1 && buf[l] > buf[r])
    {
        std::swap(buf[l], buf[r]);
        return;
    }

    std::vector<T> tmp(&buf[l], &buf[l] + (r + 1));

    for (size_t i = l, j = 0, k = m - l + 1; i <= r; ++i)
    {
        if (j > m - l)
        {
            buf[i] = tmp[k++];
        }
        else if(k > r - l)
        {
            buf[i] = tmp[j++];
        }
        else
        {
            buf[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
        }
    }
}

template<class T>
void MergeSort(std::vector<T>& buf, size_t l, size_t r)
{
    // Условие выхода из рекурсии
    if(l >= r)
        return;

    size_t m = (l + r) / 2;

    // Рекурсивная сортировка полученных массивов
    MergeSort(buf, l, m);
    MergeSort(buf, m+1, r);
    merge(buf, l, r, m);
}




int main()
{
    srand(time(NULL));
    int n,m;
    std::cout<<"Input size 1: ";
    std::cin>>n;
    std::cout<<"Input size 2: ";
    std::cin>>m;

    std::vector<int> mas(n);
    for (size_t i = 0; i < n; i++)
    {
        mas[i] = rand() % 20 - 10;
        std::cout << mas[i] << "  ";
    }
    std::cout << std::endl;
    std::vector<int> mas2(m);
    for (size_t i = 0; i < m; i++)
    {
        mas2[i] = rand() % 20 - 10;
        std::cout << mas2[i] << "  ";
    }
    std::cout << std::endl;
    std::vector<int> mas3;
    mas3.reserve(mas.size()+mas2.size());
    mas3.insert(mas3.end(),mas.begin(), mas.end());
    mas3.insert(mas3.end(),mas2.begin(), mas2.end());

    MergeSort(mas3, 0, n+m);
    std::cout << std::endl;
    for (size_t i = 0; i < n+m; i++)
    {
        std::cout << mas3[i] << "  ";
    }
    return 0;
}
