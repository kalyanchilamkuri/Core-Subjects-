
# Process => is a program under execution

## .cpp => compiler => compiler => executable => program

## How OS creates the process?

### load the program and static data to memory (static data is data used for initialization)
### Allocate run-time stack (part of memory used for local variable,function arguement and return values)
### Allocate heap (part of memory used for dynamic allocation)
### I/O related task ()

# Process communication 

## Independent vs Cooperative Processes
## *Independent Process*:
### Doesn’t affect or get affected by any other process.
### Doesn’t share data with others.
### Cooperative Process:
### Can affect or be affected by others.
### Shares data.
### Example: Producer-Consumer problem.

## cooperative processes need IPC to share data/Info
### Two models of IPC

## *Message parsing*
### it works like email , one process sends using a system call another receives , suitable when processes dont share memory
## *Shared memory*
### memory region is shared , both processes read/write in it,faster but needs synchronization(eg:semaphores)

## *Swapping and dispatcher*

### moving process in/out of main memory to/from disk(external memory), happens wehn main memory is full or high-priority process comes , suspended processes are in the "suspended ready" state
### Dispatcher is module that hands over cpu a selected process , works closely with sts and also responsible for context switching , Dispatcher latency : time taken to stop one process and start another

## *Types of schedulers*

### *Long Term Scheduler*

### controls degree of multiprogramming(how many processes in memory) and picks jobs from the secondary memory to bring into main memory

### *short term scheduler*

### picks processes from the ready queue and gives cpu access , called frequently must be fast

### *Medium term scheduler*

### swaps processes out of memory when overloaded , may bring them back later

<!-- Process Life cycle and states  -->

### new => program is being converted into a process
### ready => in memory , waiting for cpu
### run => executing on cpu
### waiting(blocked) => waiting for I/O resource
### Terminated => finished
### suspended ready => in secondary memory

<!-- Transitions:
From Ready → Run (by STS).
Run → Terminated when done.
Run → Ready if time quantum is over.
Run → Wait if IO is needed.
Wait → Ready after IO is complete. -->

## *PCB*

### pcb is also called as task control block , data structure to store everything about a process , it is created when a process starts and deleted on termination

### pcb contains process id,state, stack , priority l program counter, cpu registers, memory info,IO info

### PCB helps the os to pause/resume processes efficiently

## *Queues in process scheduling*

### *Job queue*
### holds new processes in secondary memory, manages by LTS
### *Ready queue*
### holds processes ready for cpu , it is managed by sts
### *waiting queue*
### holds processes waiting for I/O

<!-- Process Creation Steps -->

<!-- Load program + static data
Allocate stack and heap
Handle IO
OS hands control to main() -->

<!-- Summary Flow:
Program is created → becomes Process (NEW)
Goes to Job Queue → LTS brings it to memory → becomes READY
STS dispatches to CPU → RUNNING
Depending on execution, can:
Finish → TERMINATED
Need IO → WAITING
Preempted (quantum over) → READY again
Swapped out → Suspend states -->

## *what is program counter*

### program counter is a special cpu register that stores the address of the next instruction that needs to be executed in a process

 <!-- How It Works During Execution:
When a process is running, the CPU fetches the instruction from the address stored in the PC.
It executes the instruction.
Then, the PC is automatically updated to point to the next instruction.
🔁 This continues in a cycle:
Fetch → Execute → Increment PC -->
<!-- 
During Context Switching:
When a process is paused (e.g., time slice is over or it's waiting for I/O), the value of the PC is saved in the PCB (Process Control Block).

When the process is resumed, the PC value is restored from the PCB, and the process continues from exactly where it left off. -->

<!-- Context switching is the process of saving the state of a currently running process and restoring the state of another process, so the CPU can switch from one process to another. -->

<!-- 
Why do we do context switching?
Because:
A process may be waiting for I/O.
Time slice is over in round-robin scheduling.
A higher-priority process just arrived. -->





