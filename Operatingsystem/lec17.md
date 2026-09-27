
🚀 Goal: Synchronize threads and avoid problems like race conditions, busy waiting, and deadlocks.

part-1:conditional variables - wait for a condition to happen

What is a conditional variable?

A conditional variable is a synchronization tool that lets a thread sleep (wait) until some condition becomes true. Another thread signals that it's okay to continue.

✅ Key Points:
*   It works with a lock — a thread must acquire the lock first before waiting.
*   The thread goes to sleep using `wait()` and releases the lock while sleeping.
*   Another thread calls `notify()` or `notify_all()` when the condition is satisfied.
*   The waiting thread wakes up, automatically reacquires the lock, and resumes.
✅ It works with a lock — a thread must acquire the lock first before waiting.
💤 The thread goes to sleep using wait() and releases the lock while sleeping.
🔔 Another thread calls notify() or notify_all() when the condition is satisfied.
🔄 The waiting thread wakes up, automatically reacquires the lock, and resumes


#include <iostream>
#include <thread>
#include <bits/stdc++.h>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

void worker() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [] { return ready; }); // Wait until "ready" is true
    cout << "Worker thread running\n";
}

void notifier() {
    this_thread::sleep_for(chrono::seconds(1)); // Simulate work
    lock_guard<mutex> lock(mtx);
    ready = true;
    cv.notify_one(); // Wake up one waiting thread
}

int main() {
    thread t1(worker);
    thread t2(notifier);

    t1.join();
    t2.join();
}


Semaphores => count how many threads can enter

what is a semaphore?

A semaphore is an integer-based synchronization primitive used to control access to a shared resource

2 types:
1)binary semaphore  => acts like lock 
2)counting semaphore => controls like multiple resource access

Key functions:
wait(S) or P(S)
=> ties to decrease the count (access resource)
=> if (S==0), thread blocks (sleeps)

signal(S) or V(S)
=> increases the semaphore count(releases resource)
=> vakes up one blocked thread , if any

code for couting semaphore


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore {
    std::mutex mtx;
    std::condition_variable cv;
    int count;

public:
    Semaphore(int value) : count(value) {}

    void wait() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return count > 0; });
        count--;
    }

    void signal() {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        cv.notify_one();
    }
};

// Shared semaphore
Semaphore sem(2); // Only 2 threads allowed at a time

void accessResource(int id) {
    sem.wait();
    std::cout << "Thread " << id << " in critical section\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " exiting\n";
    sem.signal();
}

int main() {
    std::thread t1(accessResource, 1);
    std::thread t2(accessResource, 2);
    std::thread t3(accessResource, 3);
    std::thread t4(accessResource, 4);

    t1.join(); t2.join(); t3.join(); t4.join();
}

```

### Semaphore at the OS Level:

=> when a thread calls wait():
*) Its moved to the wait queue(not using cpu)
*) OS puts it in the waiting state

=> when another thread calls signla()
*) OS uses a `wakeup()` call to move one waiting thread to the ready queue.
*) That thread will run when the scheduler picks it.

## Final Summary:

=> conditional variables are great when a thread must wait for something to happen (like a flag turning true)
=> semaphores are great when you want to limit concurrent access to a resource 
=> both help avoid busy waiting , save cpu time and prevent race conditions

