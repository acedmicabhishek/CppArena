#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>
#include <chrono>
#include <numeric>

// 1. std::thread
void thread_function() {
    std::cout << "Hello from thread!\n";
}

void thread_with_args(int i, double d, const std::string& s) {
    std::cout << "Thread arguments: " << i << ", " << d << ", " << s << "\n";
}

// 2. Mutexes (std::mutex, std::lock_guard, std::unique_lock)
std::mutex mtx;
int shared_data = 0;

void increment_shared_data() {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++shared_data;
    }
}

// 3. Condition Variables (std::condition_variable)
std::condition_variable cv;
std::mutex cv_mtx;
bool ready = false;
int processed_data = 0;

void worker_thread() {
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(cv_mtx);
    cv.wait(lk, [] { return ready; });

    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    processed_data = 100; // process the data
    std::cout << "Worker thread signals data processing completed\n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
}

// 4. Atomics (std::atomic)
std::atomic<int> atomic_counter(0);

void atomic_increment() {
    for (int i = 0; i < 10000; ++i) {
        atomic_counter++;
    }
}

// 5. Futures and Promises (std::future, std::promise)
void produce_value(std::promise<int>&& int_promise) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int_promise.set_value(42);
}

// 6. std::async
int async_task() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 99;
}

int main() {
    // 1. std::thread
    std::cout << "--- std::thread ---\n";
    std::thread t1(thread_function);
    std::thread t2(thread_with_args, 1, 3.14, "test");
    t1.join();
    t2.join();
    std::cout << "\n";

    // 2. Mutexes
    std::cout << "--- Mutexes ---\n";
    std::vector<std::thread> mutex_threads;
    for (int i = 0; i < 10; ++i) {
        mutex_threads.emplace_back(increment_shared_data);
    }
    for (auto& t : mutex_threads) {
        t.join();
    }
    std::cout << "Shared data: " << shared_data << "\n";
    std::cout << "\n";

    // 3. Condition Variables
    std::cout << "--- Condition Variables ---\n";
    std::thread worker(worker_thread);
    {
        std::lock_guard<std::mutex> lk(cv_mtx);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();

    {
        std::unique_lock<std::mutex> lk(cv_mtx);
        cv.wait(lk, [] { return processed_data != 0; });
        std::cout << "Back in main(), data = " << processed_data << '\n';
    }
    worker.join();
    std::cout << "\n";

    // 4. Atomics
    std::cout << "--- Atomics ---\n";
    std::vector<std::thread> atomic_threads;
    for (int i = 0; i < 10; ++i) {
        atomic_threads.emplace_back(atomic_increment);
    }
    for (auto& t : atomic_threads) {
        t.join();
    }
    std::cout << "Atomic counter: " << atomic_counter << "\n";
    std::cout << "\n";

    // 5. Futures and Promises
    std::cout << "--- Futures and Promises ---\n";
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::thread producer(produce_value, std::move(p));
    std::cout << "Waiting for the promised value...\n";
    std::cout << "Promised value: " << f.get() << "\n";
    producer.join();
    std::cout << "\n";

    // 6. std::async
    std::cout << "--- std::async ---\n";
    std::future<int> async_future = std::async(std::launch::async, async_task);
    std::cout << "Doing other work while async task runs...\n";
    std::cout << "Async task result: " << async_future.get() << "\n";

    return 0;
}