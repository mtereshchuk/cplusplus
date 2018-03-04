#ifndef C_PLUS_PLUS_PROMISE_H
#define C_PLUS_PLUS_PROMISE_H

#include "shared_state.h"
#include "future.h"
#include <mutex>

template <typename T>
class promise {

    shared_state <T> *state_ptr;

public:

    promise(promise &&) = default;
    promise &operator= (promise &&) = default;

    promise(promise &) = delete;
    promise &operator= (promise &) = delete;

    promise() {
        state_ptr = new shared_state <T>();
        state_ptr->promise_exists = true;
    }

    ~promise() {
        state_ptr->promise_exists = false;
    }

    future <T> get_future() {
        std::unique_lock <std::mutex> lock(state_ptr->m);
        return future <T>(state_ptr);
    }

    void set(const T &value) {
        std::unique_lock <std::mutex> lock(state_ptr->m);
        if (state_ptr->ready) {
            throw std::runtime_error("value already set");
        }
        state_ptr->value = value;
        state_ptr->ready = true;
        state_ptr->cond_var.notify_one();
    }

    void set(const T &&value) {
        set(value);
    }

    void set_exception(const std::exception_ptr &e) {
        std::unique_lock <std::mutex> lock(state_ptr->m);
        state_ptr->error = e;
    }

};

#endif //C_PLUS_PLUS_PROMISE_H
