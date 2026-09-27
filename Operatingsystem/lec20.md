# Reader-Writer Problem

The **Reader-Writer Problem** is a synchronization issue that occurs when:

- Multiple readers want to read shared data.
- One or more writers want to update the same shared data.

---

## 🧠 Main Rules

| Case             | Allowed? | Why?                          |
|------------------|:--------:|-------------------------------|
| Many Readers     | ✅ Yes   | No one is modifying           |
| Many Writers     | ❌ No    | Race condition                |
| Reader + Writer  | ❌ No    | Reader may read incomplete/invalid data |

---

## Goal

- Allow multiple readers to read at the same time.
- Allow only one writer at a time.
- Do **not** allow multiple writers at the same time.

---

## Problem 1: Reader Priority

- If a reader is reading, new readers can still read.
- Writers must wait until all readers are done.

---

### Example Code: Reader-Writer with Reader Priority

```cpp
#include <bits/stdc++.h>
using namespace std;

mutex mtx;              // protects readCount
shared_mutex rwLock;    // shared for readers, exclusive for writers
int readCount = 0;

void reader(int id) {
    while (true) {
        // Entry Section
        mtx.lock();
        readCount++;
        if (readCount == 1)
            rwLock.lock(); // First reader locks shared resource
        mtx.unlock();

        // Reading
        cout << "Reader " << id << " is reading\n";
        this_thread::sleep_for(chrono::milliseconds(1000));

        // Exit Section
        mtx.lock();
        readCount--;
        if (readCount == 0)
            rwLock.unlock(); // Last reader releases
        mtx.unlock();

        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void writer(int id) {
    while (true) {
        rwLock.lock(); // Writer waits until no reader/writer

        // Writing
        cout << "Writer " << id << " is writing\n";
        this_thread::sleep_for(chrono::milliseconds(1500));

        rwLock.unlock(); // Writer done

        this_thread::sleep_for(chrono::milliseconds(1500));
    }
}

int main() {
    thread r1(reader, 1);
    thread r2(reader, 2);
    thread w1(writer, 1);
    thread w2(writer, 2);

    r1.join(); r2.join();
    w1.join(); w2.join();

    return 0;
}
```

---

### Logic Recap

- `readCount` keeps track of the number of readers.
- First reader locks the shared resource (`rwLock.lock()`).
- Last reader unlocks it (`rwLock.unlock()`).
- Writer gets access only when no readers are active.
- If new readers keep coming, writers may starve forever.  
  This is called **Writer Starvation**.

---

## 🧪 Problem 2: Writer Priority

- If a writer is waiting, **no new reader is allowed to enter**.
- This prevents writer starvation.



int readCount ← 0                  // number of active readers
mutex mtx                         // protects readCount
semaphore wrt ← 1                 // controls access to the shared resource


reader code:
Reader() {
    while (true) {
        wait(mtx)                    // lock to update readCount
        readCount ← readCount + 1
        if readCount == 1:
            wait(wrt)               // first reader locks the shared resource
        signal(mtx)                 // release lock

        // --- Critical Section ---
        Read the shared data
        // ------------------------

        wait(mtx)
        readCount ← readCount - 1
        if readCount == 0:
            signal(wrt)             // last reader releases the lock
        signal(mtx)

        // Optional: Sleep or delay
    }
}


writer code:

Writer() {
    while (true) {
        wait(wrt)                    // lock the shared resource

        // --- Critical Section ---
        Write or modify the shared data
        // ------------------------

        signal(wrt)                  // release the lock

        // Optional: Sleep or delay
    }
}
