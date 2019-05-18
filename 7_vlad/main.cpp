#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void a()
{
    std::set<int> set1{4,3,5,6};
    std::set<int> set2 {2,4,5,6};
    std::set<int> result;
    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          std::inserter(result, result.begin()));
    if(result.empty())
        std::cout << "empty" << std::endl;
    else
    {
        std::for_each(result.begin(), result.end(), [](int value){std::cout << value << " " ;});
    }
}

void b()
{
    std::vector<int> n{1,2,3,4,0,0,0,0};
    std::vector<int> insert{1,2,3,4,5};
    n.insert(n.begin()+(n.size()/2), insert.begin(), insert.end());
    std::for_each(n.begin(), n.end(), [](int value){std::cout << value << " " ;});
}
int main()
{
    std::vector<int> v;
    int size = 7;
    for(int i = 0; i != size; ++i)
    {
        v.push_back(-15);
    }
    std::cout <<"Size: "<< v.size() << std::endl;
    std::for_each(v.begin(), v.end(), [](int value){std::cout << value << " " ;});
    std::cout << std::endl;
    int i = v.back() + 2;
    v.back() = i;
    std::cout <<"Size: "<< v.size() << std::endl;
    std::for_each(v.begin(), v.end(), [](int value){std::cout << value << " " ;});
    std::cout<<std::endl;
    std::cout<<std::endl;
    //общие
    a();
    std::cout<<std::endl;
    b();
    return 0;
}
