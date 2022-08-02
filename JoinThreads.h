#include <vector>
#include <thread>
class JoinThreads
{
public:
    explicit JoinThreads(std::vector<std::thread>& threads_) : threads(threads_)
    {}
    ~JoinThreads()
    {
        for(unsigned int i = 0; i< threads.size(); ++i)
        {
            if(threads[i].joinable())
            {
                threads[i].join();
            }
        }
    }
private:
    std::vector<std::thread>& threads;
};