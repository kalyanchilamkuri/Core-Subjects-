# Program, Process, and Thread

## 1. Program

- A program is a set of instructions stored on disk, ready to be executed.
- It is a passive entity because it is not currently running.

## 2. Process

- A process is a program in execution.
- It resides in RAM and has its own memory space.
- It contains code, data, and execution-related information such as registers.

## 3. Thread

- A thread is a lightweight unit of CPU execution inside a process.
- Threads share the resources of their process but have their own execution state.

**Threads share:**
- Code
- Data
- Open files
- Address space

**Each thread has its own:**
- Registers
- Stack
- Program Counter (PC)

---

# Multitasking vs Multithreading

| Multitasking | Multithreading |
|---|---|
| Runs multiple processes at a time. | Runs multiple threads within a process. |
| Context switching happens between processes. | Context switching can happen between threads. |
| Can work on a single CPU. | Can work on a single CPU. |
| Each process has a separate memory space. | Threads share the memory space of the same process. |
| Example: Running MS Word and Chrome at the same time. | Example: MS Word handling autosave and formatting using different threads. |

---

# Advantages of Threads

1. **Responsiveness**
   - The UI remains responsive while background tasks are running.

2. **Resource Sharing**
   - Threads share the same process memory and resources.
   - There is no need to duplicate these resources for each thread.

3. **Economical**
   - Threads are lightweight compared to processes.
   - They require fewer resources.

4. **Faster Context Switching**
   - Switching between threads is generally faster than switching between processes.

5. **Scalability**
   - Threads can make better use of multicore processors.
   - Multiple threads can run in parallel on different CPU cores.

---

# Thread Scheduling

- The OS schedules threads based on their priority and scheduling policy.
- Each thread gets a time slice, similar to a process.
- On a single-core CPU, threads take turns using the CPU.
- On a multicore CPU, multiple threads can run in parallel if they are scheduled on different cores.

---

# Quick Revision

| Concept | Key Point |
|---|---|
| Program | Instructions stored on disk |
| Process | A program in execution |
| Thread | A unit of CPU execution within a process |
| Process memory | Separate for each process |
| Thread memory | Shared within the same process |
| Thread stack | Private to each thread |
| Thread registers | Private to each thread |
| Multitasking | Multiple processes |
| Multithreading | Multiple threads within a process |
| Thread scheduling | OS decides when threads get CPU time |