
# *concurrency*

## running multiple instruction sequences at the same time is called concurrency , In os when multiple threads of a process run in parallel it happens.

## thread
### a thread is like a small task inside a program , its a single flow of execution , its an independent path inside a process also called a lightweight process and helps in parallelize a program 

## Thread scheduling 
### threads are run based on their priority and even if all threads are "alive" , the OS gives time slices to run them one by one (preemptive multitasking)

## Thread context switching
### when switching fron one thread to another thread
### *)os saves the stateof the current thread , switches to another thread of the same process , memory space doesnt chane but program counter,registers,and stack are saved *) It's is faster than process switching *) the cpu cache is preserved, making it more efficient

## how does each thread get cpu time?
### every thread has its own program counter(pc) and scheduler decides which thread runs next , os uses the thread's pc to resume execution

## I/O or time quantum(TQ) based context switching 
### like pcb , threads also has tcb , os used tcb during context switching of threads

## Does multi-threading help in single cpu?
### No gain, cox => cpu run onlyone thread at a time and extra overhead due to contextswitching

## Benefits of multithreading 
### *) responsiveness :- App doesnt freeze , multiple tasks run together 
### *) resource sharing :- efficient , threads use shared memory
### *) economy: less costly than creating multiple processes
### **) easier to manage memory and resources , utilizes cpu better by doing parallel work and efficient when threads of the same process share data


