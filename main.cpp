#include "ThreadPool.h"
#include "QuickSort.h"
#include <iostream>
using namespace std;
void printThreadId()
{
    for(int i=0;i<10;++i)
    {
        std::cout << std::this_thread::get_id() << " ## "<< i << endl;
    }
}

template<typename T>
void print(const T& t)
{
    for(auto&& elem : t)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // cout<< std::this_thread::get_id() << " concurrency=" << std::thread::hardware_concurrency()<<endl;
    // ThreadPool tp;
    // tp.submit(printThreadId);
    // tp.submit(printThreadId);
    // tp.submit(printThreadId);
    std::list<int> input = {5,3,6,1,2,4,8};
    print(parallel_quick_sort(input));
    return 0;
}