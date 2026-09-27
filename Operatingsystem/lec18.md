
Producer-consumer problem

What's the idea?

There are 2 types of threads: producer and consumer:

what's the idea?

There are two types of threads:producer and consumer,and they both share a fixed-size buffer.

producer:- generates data/items and puts then into the buffer
consumer:- takes data/items from the buffer and processes it 

They must be synchronized , so they dont mess with the buffer..

producer should not produce if the buffer is full 
consumer should not consume if the buffer is empty 


=> the main issue is how to make sure that both producer and consumer dont interfere with each other while accessing the shared buffer 
*)if producer adds data when buffer is full => error 
*)if consumer remioves the data when the buffer is empty => problem occurs
*)if both access at same time => race condition

---

we need synchronization to :
*)avoid overflow and underflow
*)prevent race conditions


how to solve?
*)mutex/lock => to give exclusive access to buffer
*)semaphores => to count available/filled slots in buffer

code:(using semaphores in c++ pseudocode)

lets say the buffer size is N

semaphore mutex = 1;       // for critical section (mutual exclusion)
semaphore empty = N;       // counts empty slots
semaphore full = 0;        // counts full slots

producer code:-

do {
    produce_item(item);        // Step 1: Produce something

    wait(empty);               // Step 2: Wait for empty space
    wait(mutex);               // Step 3: Lock the buffer

    insert_item(item);         // Step 4: Put item in buffer

    signal(mutex);             // Step 5: Unlock buffer
    signal(full);              // Step 6: Increase full count
} while(true);

consumer code:-

do {
    wait(full);                // Step 1: Wait for items
    wait(mutex);               // Step 2: Lock the buffer

    remove_item(item);         // Step 3: Remove item from buffer

    signal(mutex);             // Step 4: Unlock buffer
    signal(empty);             // Step 5: Increase empty count

    consume_item(item);        // Step 6: Use the item
} while(true);



