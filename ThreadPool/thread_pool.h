#ifndef C_PLUS_PLUS_THREAD_POOL_H
#define C_PLUS_PLUS_THREAD_POOL_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <type_traits>
#include <iterator>

class Thread_pool {

    std::atomic_bool working;
    std::vector <std::thread> threads;
    std::mutex m;
    std::queue <std::function <void()>> tasks;
    std::condition_variable cond_var;

    void taskGiver() {
        while (working) {
            std::unique_lock <std::mutex> lock(m);
            while (working && tasks.empty()) {
                cond_var.wait(lock);
            }
            if (!tasks.empty()) {
                std::function <void()> curFn = (std::function<void()> &&) tasks.front();
                tasks.pop();
                lock.unlock();
                curFn();
            }
        }
    }

public:

    Thread_pool(size_t numOfThreads) {
        working = true;
        for (size_t i = 0; i < numOfThreads; ++i) {
            threads.push_back(std::thread(taskGiver, this));
        }
    }

    void execute(std::function <void()> const &task) {
        std::unique_lock <std::mutex> lock(m);
        tasks.push(task);
        cond_var.notify_one();
    }

    ~Thread_pool() {
        working = false;
        cond_var.notify_all();
        for (auto &i : threads) {
            i.join();
        }
    }
};

#endif //C_PLUS_PLUS_THREAD_POOL_H