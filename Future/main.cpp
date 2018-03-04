#include <iostream>
#include "promise.h"
#include "future.h"
#include <thread>

promise <int> p;

void thread_func1() {
    p.set(10);
    //p.set(11);
}
void thread_func2() {
    std::cout << p.get_future().get();
}

int main() {
    std::thread th1(thread_func1);
    std::thread th2(thread_func2);
    th1.join();
    th2.join();
    return 0;
}