#ifndef C_PLUS_PLUS_SHARED_STATE_H
#define C_PLUS_PLUS_SHARED_STATE_H

#include <atomic>
#include <mutex>
#include <condition_variable>

template <typename T>
struct shared_state {
    T value;
    std::atomic_bool ready, promise_exists;
    std::exception_ptr error;
    std::mutex m;
    std::condition_variable cond_var;
    state() {
        ready = false;
        promise_exists = false;
    }
};

#endif //C_PLUS_PLUS_SHARED_STATE_H
