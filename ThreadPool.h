#include "ThreadSafe_Queue.h"
#include "JoinThreads.h"
#include <atomic>
#include <functional>
#include <thread>
#include <vector>
using namespace std;
class ThreadPool
{
    std::atomic_bool done;
    ThreadSafe_Queue<std::function<void()>> work_queue;
    std::vector<std::thread> threads;
    JoinThreads joiner;

    void worker_thread()
    {
        while(!done)
        {
            std::function<void()> task;
            if(work_queue.try_pop(task))
            {
                task();
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }
public:
    ThreadPool() : done(false), joiner(threads)
    {
        unsigned const thread_count = std::thread::hardware_concurrency();
        try
        {
            for(unsigned i = 0; i<thread_count; ++i)
            {
                threads.push_back(std::thread(&ThreadPool::worker_thread, this));
            }
        }
        catch(...)
        {
            done = true;
            throw;
        }
    }

    ~ThreadPool()
    {
        done = true;
    }

    template<typename FunctionType>
    void submit(FunctionType f)
    {
        work_queue.push(std::function<void()>(f));
    }
};