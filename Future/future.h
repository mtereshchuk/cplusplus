#ifndef C_PLUS_PLUS_FUTURE_H
#define C_PLUS_PLUS_FUTURE_H

#include "shared_state.h"
#include "promise.h"
#include <mutex>

template <typename T>
class promise;

template <typename T>
class future {

    friend class promise <T>;
    shared_state <T> *state_ptr;
    future(shared_state <T> *ptr) {
        state_ptr = ptr;
    }

public:

    future(future &&) = default;
    future &operator= (future &&) = default;

    future(future const &) = delete;
    future &operator= (future const &) = delete;

    T get() const {
        if (state_ptr->error != nullptr) {
            throw state_ptr->error;
        }
        wait();
        return state_ptr->value;
    }

    bool is_ready() const {
        return state_ptr->ready;
    }

    void wait() const {
        std::unique_lock <std::mutex> lock(state_ptr->m);
        if (state_ptr->ready) {
            return;
        } else if (!state_ptr->promise_exists) {
            throw std::runtime_error("value is not set and promise doesn't exist");
        }
        state_ptr->cond_var.wait(lock);
    }

};

#endif //C_PLUS_PLUS_FUTURE_H
