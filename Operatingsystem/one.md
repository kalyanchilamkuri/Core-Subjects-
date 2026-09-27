# Types of Operating Systems

## 1. Goals of an Operating System

- **High-priority task execution:** Give priority to important tasks when required.
- **Maximum CPU utilization:** Keep the CPU busy as much as possible.
- **No starvation:** Ensure that every process gets a chance to execute.

## 2. Single-Process Operating System

- Only one program is loaded into memory and executed at a time.
- No multitasking or switching between multiple applications.
- If a program crashes or hangs, the whole system may be affected.

## 3. Batch Operating System

- A Batch OS groups similar jobs into batches and executes them one after another without user interaction.
- Jobs are processed automatically in a sequence.

**Advantages:**
- Efficient for repetitive tasks.
- Reduces the need for manual interaction.
- Allows multiple jobs to be processed in batches.

**Examples:**
- Payroll processing
- Bank statement generation

## 4. Multiprogramming Operating System

- A Multiprogramming OS keeps multiple jobs in memory at the same time.
- When one job waits for I/O, the CPU switches to another job.
- The main goal is to **keep the CPU busy and avoid idle time.**

**How it works:**

1. CPU executes Job A.
2. Job A requests I/O and enters the waiting state.
3. CPU switches to Job B.
4. While Job A waits for I/O, Job B uses the CPU.

**Features:**
- Usually works with a single CPU.
- Uses context switching.
- Does not require user interaction.
- Improves CPU utilization and throughput.

## 5. Multitasking Operating System

- Multitasking is an extension of multiprogramming.
- It allows multiple programs to run seemingly at the same time.
- It uses time-sharing and frequent context switching.

**How it works:**

- The CPU uses scheduling, such as Round Robin.
- Each process gets a small time slice (e.g., 10 ms).
- After its time slice ends, the CPU switches to another process.
- Fast switching makes it appear that multiple programs are running simultaneously.

**Example:**

Running a browser, music player and code editor at the same time.

**Features:**
- Supports multiple applications.
- Uses context switching.
- Allows users to interact with multiple programs.
- Improves responsiveness.

## 6. Distributed Operating System

- A Distributed OS manages a group of independent computers connected through a network.
- It makes these computers appear to users as a single, unified system.

**Example:**

Multiple computers work together to process different parts of a large task, while the user sees one system.

**Features:**

1. **Fault tolerance:** If one node fails, other nodes may continue working.
2. **Resource sharing:** Shares resources such as CPU, RAM and GPU across computers.
3. **Scalability:** More machines can be added to increase computing capacity.
4. **Performance:** Tasks can be divided among multiple machines and processed in parallel.
5. **Transparency:** Users do not need to know which machine is processing a particular task.

## 7. Real-Time Operating System (RTOS)

- An RTOS is designed to process data and respond to events within a specific time limit.
- Its main goal is not just fast execution, but **predictable execution within deadlines**.

There are two main types of RTOS.

### A. Hard Real-Time Operating System

- Missing a deadline is unacceptable.
- Even a single missed deadline may cause the system to fail.
- Used in systems where late responses can have dangerous consequences.

**Example:** A deadline-critical control system.

### B. Soft Real-Time Operating System

- Missing a deadline is undesirable but not catastrophic.
- The system continues to work, but its performance or quality may decrease.

**Example:** A multimedia system where a delayed frame can reduce video quality.

---

## Quick Revision

| OS type | Main purpose |
|---|---|
| Single-process OS | Execute one program at a time |
| Batch OS | Execute grouped jobs without user interaction |
| Multiprogramming OS | Maximize CPU utilization |
| Multitasking OS | Run multiple applications seemingly simultaneously |
| Distributed OS | Manage multiple computers as one system |
| Hard RTOS | Meet deadlines without missing them |
| Soft RTOS | Meet deadlines where occasional delays are tolerable |