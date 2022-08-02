#include "ThreadPool.h"
#include <iostream>
void print()
{
    for(int i=0;i<10;++i)
    {
        std::cout << std::this_thread::get_id() << " ## "<< i << endl;
    }
}
int main()
{
    cout<< std::this_thread::get_id() << " concurrency=" << std::thread::hardware_concurrency()<<endl;
    ThreadPool tp;
    tp.submit(print);
    tp.submit(print);
    tp.submit(print);

    return 0;
}