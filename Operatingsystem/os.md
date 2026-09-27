<!-- Operating System -->
<!-- 1)Application software  -->
## Application software is a program that helps you do a specific job 
## calculator => calculates , browser => open websites , music player => plays music i.e it works for the user but not for the computer 

<!-- System software -->
## system software is the boss of the software that controls the computer and helps application software run 
## application software cannot directly depend on hardware , system software sits in between and helps example=>operating system , device drivers 

<!-- what is an os -->
## an operating system is a software that:
### => manages all computer resources(CPU , memory , files , devices)
### => acts as a middleman between user programs and hardware 
### => makes program execution easy and efficient 
### --->> decides who uses which toy (CPU , memory) to students(applications)

## when there is no os => apps must talk directly to the hardware so it is very hard to write and maintain

## this leads to resource exploitation => one app may take all the cpu , memory.

## without an os => applications must handle hardware directly , making them complex and one application may monopolize cpu or memory , there will be no memory protection and leads to crashes 

## os is a collection of system software that works together 

## includes process , memory managements , file system , security 

## Functions 
### => access to the hardware 
### => interface between user and hardware 
### resource management 
### abstraction 


# what are the main functions of the os?
### => os acts as an interface between the user and the hardware , it manages system resources and provides isolation and protection among processes 

## OS goals => os always tries to maximize cpu utilization , reduce process starvation , execute higher-priority jobs first 

<!-- types of os -->
# single process os 
## => only one program runs at a a time 
## cpu executes => process A -> finish -> then process B
## oldest type => no multitasking , cpu often idle 
## ====>> a single process os allows only one process to execute at a time from the ready queue
## problems --> no priority handling , starvation possible 

# Batch os 
## => it groups similar jobs into batches , batches are executed one by one , all jobs in a batch run together 
## problems -->> No priority handling , starvation possible , CPU idle during I/O
## ===> prioblems => No priority handling , starvation possible 
## --> cpu is idle in Batch os because when a job performs I/O , the cpu waits instead of executing another job 

# Multiprogramming os 
## keep multiple jobs in memory so cpu is never idle 
## Job A does I/O -> CPU switches to Job B
## ===>> single cpu , context switching , cpu idle time reduced 
## ----->> multiprogramming improves cpu utilization by keeping multiple jobs in memory by switching the cpu to another job when one is waiting for I/O

# Multitasking os 
## extension of multiprogramming 
## ===>> single cpu , time sharing , fast context switching 
## => listen to music , browse internet , write code 
## ====> difference between multitasking and multiprogramming is -> multiprogramming focuses on cpu utilization but multitasking focuses on responsiveness using time sharing 

# Multiprocessing os 
## more than one cpu in one computer => Higher throughput , better reliability , less starvation 
## if one cpu fails , other cpus can continue execution 

# Distribute os
## many computers connected by network together as a system , each node is independent , loosely connected , communcation via network 
## ---> this manages multiple autonomous networked computers and makes them appear as a single system 

# Real time os 
## most strict os --> must respond with fixed time ->> missing deadline can cause failure ----> like satellite launch

<!-- Program  -->
## a program is a compiled executable file stored on disk that contains instructions to perform a specific task.

<!-- Process  -->
## a process is a program in execution , It resides in Ram , it has its own memory and cpu state and resources 
## => when we open chrome -->> chrome process is created 

<!-- Thread -->
## a thread is a single sequence of execution , It is a light weight process , multiple threads exists inside a process , threads share memory and resources 
## --->> basically we can have multiple cooks 

## --> we need threads to do multiple independent tasks at the same time 
## --> threads are called light wieght processes because threads share memory and resources of the process and require less overhead compared to process 


## Multitasking  -> faster 
### => multitasking is the execution of more than one process seemingly at the same time 
### => more than one process , single cpu , uses context switching , each process has seperate memory 
### ==> Multitasking is the ability of an operating system to execute multiple processes concurrently by rapidly switching the CPU among them


# Multithreading  -> faster 
### => multithreading is the division of a single process into multiple threads , each with its own exection path.
### ==> multiple threads inside one process , threads share memory , faster exection.
### Multithreading is a technique where a process is divided into multiple threads that execute concurrently to improve performance and responsiveness.

#### =======> multithreading is faster because threads share memory and requires less overhead during context switching compared to the process 


## Thread scheduling 
## ==> threads are scheduled based on the priority 
## ==> os assigns time slices 
## ==> even threads inside same process compete for cpu 

# thread context switching 
## => switch between threads of same process is called context switching , memory remains same 
## ==>> Included --->> program counter , registers , stack ; Not included --->> memory address space 


# Process context switching 
## switch between different process is called process context switching and memory changes here 
## included --->> program counter , registers , stack ; result --> slow 


<!-- Thread context switching is faster because it does not involve switching memory address space and preserves CPU cache, unlike process context switching. -->

<!-- Program → stored on disk
Process → program in RAM
Thread → worker inside process
Multitasking → many processes
Multithreading → many threads
Thread switch = fast
Process switch = slow -->

<!-- Components of operating system  -->

# Kernel --> ceo + core team (very powerful)
# user space --> employees and customers(app,users)



# kernel 
### Kernel is the heart of the os , it talks directly to the hardware and does the most important work. If kernel stops --> computer stops 

<!-- Core / heart of OS
First part to load when system starts
Runs in kernel mode (full power)
Controls CPU, memory, disk, devices -->

## ==> the kernel is the core component of the os that directly interacts with hardware and manages critical system resources 

# user space 
## user space is where apps live , apps cannot directly touch hardware 
## they must ask the kernel for help 
## GUI , CLI , Application programs 

<!-- To ensure system security and stability. Direct hardware access could crash the system or corrupt data. -->

# shell(command interpreter)
## a shell is a translator 
### --> you talk -> shell understands --> kernel executes 
## ---> a shell accepts commands from the user , interprets them , gets them executed by kernel 
### ===> A shell is a command interpreter that receives user commands and passes them to the operating system for execution.

<!-- functions of kernel  -->

<!-- 1) process management  -->
## kernel decides which process runs now , which one waits , which one stops 
### responsibilities -->> create and delete processes , schedule processes and threads , suspend and resume processes 


## ---->> what is the role of the kernel in process management ==>> the kernel handles process creation , scheduling , synchronization , suspension and termination 


## ---->> efficiently uses memory , avoid wastage and prevent one process from accessing another process's memory 


## ---->> kernel is a file librarian -->> it knows where files are , who can open them , how they are stored ---->> creates and delete files , creates and delete directories , map files to disk , backup support 
## ---->> It organizes , stores , retrieves and protects files on secondary storage 


## ---->> kernel controls input and output devices and also manages data transfer 


### ------->> spooling allows jobs from faster devices to be queued on disk and processes by slower devices later 

### ----> buffering is temporary storage inside one job 


### --->> buffering is within one job , while spooling manages multiple jobs between devices of different speeds 


### --->> caching ==>> keeps frequently used data closer for fast access example -> cpu cache , browswer cache 


### --->> caching is used to reduce the time and improve performance by storing frequently accessed data in faster memory 


### communication happens using IPC inter process communication

### processes have seperate memory , so need to communicate safely 


<!-- Because processes are isolated with separate memory spaces but may need to exchange data to function correctly. -->

# => IPC methods 1) shared memory 2)message parsing 


<!-- Kernel = heart of OS
User space = apps
Shell = command interpreter
Kernel manages: process, memory, file, I/O
Spooling ≠ buffering ≠ caching
Monolithic = fast, less safe
Microkernel = safe, slow
Hybrid = balanced
User ↔ kernel = IPC -->



<!-- System calls  -->

### applications talk to the kernel using system calls 
 
## a system call is an interface that allows a user-level program to request services from the kernel 

<!-- mkdir => just a wrapper => makes a system call => kernel's file management module creates the directory -->

<!-- when a process is created , the user program makes a system call , the kernel creates the process in kernel space and then returns to the user space -->

<!-- switch from modes(user,kernel) happends through interrupts/traps -->

# implementation of system calls 
## ==>> system calls are implemented in C , low-level parts may use assembly 

## ==> system calls are primarily implemented in C.

## ==> system calls are the only way a process can go from user mode to kernel mode 

### we need system calls because :
### -->> without system calls
<!-- Cannot access I/O devices
Cannot create processes
Cannot communicate directly with other processes
Cannot manage memory -->


## types ---> 1) process control system calls 2) file menagement system calls 3) device management system calls 4) information maintenance system calls 5)communication management system calls 


<!-- what happens when we turn on a computer -->

## 1) power on => electricity starts flowing 2)cpu wakes up and looks for firmware 3) POST => power on selft test =>before doing anything computer checks its body 4)(bios/uefi) find the bootloader 5) boot loader runs , its job is to load the os kernel 6) finally kernel is loaded into memory , kernel initializes devices , user space programs start , login screen appears 


## ==> BOOTING --->> when the system powers on , the cpuload BIOS/UEFI from ROM , performs POST , locates the bootloader from MBR or EFI partition , executes the bootloader , which loads the os kernel , initializes hardware and starts user space processes 


<!-- 32-bit vs 64-bit -->

## 32-bit OS
### -->> 32-bit registers , can access 2^32 memory addresses , max RAM approx 4gb , processes 4 bytes per instruction cycle 

## 64-bit os 
### 64-bit registers,can access 2^64 memory addresses , theoritical RAM approx 17 billion gb , processes 8 bytes per instruction cycle.

### --->> 64-bit is better because 1)more addressable memory 2)better resource usage 3)better performance 4)compatibility 5) better graphics 

### Because 64-bit systems have larger registers , can process more data per instruction cycle, and efficiently utilize larger memory.



<!--  storage devices basics  -->

# Registers
## --> register are in cpu hands , fastest storage 1)smallest 2)fastest 3)most expensive 4)stores immediate data 

# Cache memory 
## cache is a small desk near cpu 
## 1) stores frequently used data 2) faster than RAM 3) slower than registers 

# Main memory (RAM)
## RAM is the program runs , volatile 

# Secondary memory 
##  secondary memory is storage 1)HDD 2)SSD 3)Non volatile $) slowest 


<!-- speed order ==> Registers > Cache > RAM > Disk -->


## registers are the cpu itself and do not require bus communication 



<!-- Inroduction to process -->

# process vs program 

## program --> compiled code , ready to execute (stored on disk)
## process --> program under execution 

## --> how does os creates a process ---> os loads the program into memory , allocates stack and heap , sets up I/O resources and then transfers control to the programs entry point 

## --> PCB -->> pcb stores all the information required to manage and resume a process including cpu registers , process states and scheduling information 

## process states 
## 1) new --> process is being created 
## 2)Ready --> waiting for cpu 
## 3) RUN --> cpu is exuting it 
## 4) waiting --> waiting for I/O
## 5) terminated --> finished exection

## diff b/w ready and waiting state ==> a ready process is waiting for cpu , whereas a waiting process is waiting for an I/O operation to complete.

## processes checking the cpu whether it is idle or not continously is called busy waiting                           

## JOB QUEUE --> processes in new state , stored in secondary memory , picked by Long-Term scheduler(LTS)
## READY QUEUE --> processes ready to execute , stored in main memory , picked by short-term scheduler(STS)
## WAITING QUEUE -->> process waiting for I/O

## --> degree of multiprogramming is the count of processes that are inside memory at once 
## --> dispatcher is the delivery boy , It gives CPU to the selected process 

## --> dispatcher gives control of the cpu to the process selected by the short term scheduler.

# Swapping 
## --> Swapping is the process of temporarily moving a process from main memory to secondary storage to free up memory, this is done by MTS

# context switching 
## --> cpu changes focus from one process to another 
## --->> what happens is ==>> save current process context to PCB and load next process context from PCB
## it is a overhead Because the CPU does not perform any useful computation during the switch


# orphan process 
## a process whose parent has terminated while the child is still executing 

# Zombie process 
## -->execution completed , entry still in process table , waiting for the parent to read exit status 
### diff b/w zombie and orphan process ------> a zombie process has completed execution but still has a process table entry , where as the orphan process is still running after its parent terminates 


<!-- process scheduling -->

## many processes want cpu , os decides who gets it first 
## CPU scheduler -->> runs when cpu is idle , picks process from the ready queue , done by sts
## once cpu is given , process wont give it back --> non-preemptive 
## os can snatch cpu back --> preemptive 

<!--
Goals of CPU Scheduling
Max CPU utilization
Min Turnaround Time
Min Waiting Time
Min Response Time
Max Throughput -->

<!-- AT → Arrival Time
BT → Burst Time
CT → Completion Time
TAT = CT − AT
WT = TAT − BT
Response Time → first CPU allocation delay -->

<!-- FCFS  -->
## fist come first serve 

## convoy effect --->> convoy effect occurs when a long cpu burst process blocks many short cpu burst processes , leading to poor performance 



<!-- LTS  -->
## --> lts selects the processes from the job queue and loads them into main memory , there by controlling the degree of multiprogramming 
## --> picks processes from job Queue , loads them from disk-ram , controls the degree of multiprogramming 

<!-- MTS -->
## mts temporarily removes processes from the main memory through swapping to reduce memory and improve system performance 

<!-- STS -->
## selects one of the ready processes and allocates the cpu to it for execution

<!-- | Scheduler | Queue Used        | Memory     | Speed  | Main Role       |
| --------- | ----------------- | ---------- | ------ | --------------- |
| LTS       | Job Queue         | Disk → RAM | Slow   | Admit processes |
| MTS       | Swapped processes | RAM ↔ Disk | Medium | Swapping        |
| STS       | Ready Queue       | RAM → CPU  | Fast   | CPU allocation  | -->


## pcb is a data structure maintained by the os that stores all the information about a process 
## 1) process ID , process state , program counter , cpu registers

<!-- During context switching, the OS saves the current process state into its PCB and restores the next process’s state from its PCB. -->

<!-- Concurrency  -->

## ==> Concurrency is the ability of the OS to manage multiple threads or processes that are executing in overlapping time periods. 

## ---> happens when => multiple threads or processes exist and os switches cpu between them.

## => The operating system schedules threads by assigning CPU time slices based on priority

## Because threads share the same memory space and do not require switching address spaces.


## TCB stores thread ID , thread statre , program counter , registers , stack pointer 

<!-- Q: Does multithreading improve performance on a single CPU system?
A:No. On a single CPU, threads execute sequentially and only add context switching overhead. -->


<!-- Benefits of Multithreading ⭐⭐
✅ Benefits:
Responsiveness
Resource sharing
Economy (cheaper than processes)
Better utilization of multi-core CPUs -->


## critical section is the part of the code where shared resources are accessed and modified 

## race condition -->> race condition occurs when multiple threads access shared data concurrently and the final result depends on the order of execution 

## --> A race condition occurs when multiple threads access shared data simultaneously and the outcome depends on execution order.

<!-- Solutions to Race Condition
1️⃣ Atomic operations
Execute in one CPU cycle
No interruption
2️⃣ Mutual Exclusion (Locks / Mutex)
Only one thread enters CS
3️⃣ Semaphores
Control access to shared resources -->


<!-- Program Counter -->

## ==>> the program counter is a cpu register that stores the address of the next instruction to be executed 

## it tells the cpu what to execute next , automatically updates after each instruction.
## changes during : function calls , loops , jumps , context switching 


<!-- Program counter and context switching -->

## --> cpu stops one process and later comes back , pc helps the cpu remember where it stopped 
## --> pc value of running process -----> saved in pcb
## --> another process runs 
## --> when first process resumes -----> pc restored from pcb 

### --> without pc => process restarts from beginnning 


# => a program counter is a cpu register that holds the address of the next instruction to be executed 
# => to allow the process to resume execution from the exact point , where it was paused during context swtiching , pc stored in pcb 


<!-- Dispatcher -->

## the dispatcher is an os module that hands over the control of the cpu to the process selected by the STS

## ----->> dispatcher performs 1) context switching 2) switching to user mode 3) jumping to the correct instruction(using pc)

## dispatcher functions ==>> it performs context switching , switches to user mode , and starts execution of the selected process 

<!-- | Program Counter            | Dispatcher             |
| ------------------------------- | ---------------------- |
| CPU register                    | OS module              |
| Stores next instruction address | Allocates CPU          |
| Used during execution           | Used during scheduling |
| Stored in PCB                   | Uses PCB               | -->



## many processes want one cpu , cpu scheduling decides who runs now and who waits 

## 1)-> SJF (NON-PREEMPTIVE)
### --> schedules the process with smallest BT runs first , once cpu is given then it can be taken back 
## pros -> convoy effect possible , starvation of long jobs 

## 2)-> SJf (PREEMPTIVE)
### -> schedules the process with smallest BT runs , cpu can be preempted , no convoy effect , less starvation than non-preemptive
### premptive sjf is optimal ==> because executing the shorter jobs first reduces the waiting time of the short processes more than it increase the waiting time of the long process 

## 3)-> priority scheduling 
### -> process with higher priority are generally given the cpu 
### non - preemptive --->> priority proportional to 1/BT
### preemptive --->> higher priority arriving process takes cpu , may cause indefinite starvation 
### ---< increase priority of waiting process slowly ....like +1 every 15 minutes 


### --->> starvation occurs when low-priority processes never get cpu , it is solved using ageing which gradually increase the priority 

## 4)Round-Robin
### -> round robin is preemptive , it has a fixed time quantum 
### -> advantages => very low starvation , no convoy effect , best for time sharing systems , easy to implement
### -> disadvantage => small TQ -> too many context switches 

### --->> Round robin is used in time - sharing systems because it ensures fairness by giving each process a fixed time slice and prevents starvation 

## 5) MLQ(convoy effect) and MLFQ 
### => in mlq there are mutliple queues with fixed priority between queues, each queue has its own algorithm .
### Queue type -->> system processes (highest) , interactive / foreground / batch/background
### problems ==>> starvation , convoy effect , inflexible 

### --->> mlq causes starvation because lower-priority queues are scheduled only after higher - priority queues are completely empty 


## MLFQ
### =>it is similar to the mlq but processes can move between queues , I/O bound-> stay up , CPU-bound -> move down , long waiting -> move UP 
### advantage ==>> less starvation , flexible.

<!-- MLQ and MLFQ -->
## ----->> mlq has fixed queues with no movement , while mlfq allows processes to move between queues based on behaviour , reducing starvation 

<!-- | Algorithm | Preemptive | Starvation | Convoy Effect | Complexity |
| --------- | ---------- | ---------- | ------------- | ---------- |
| FCFS      | ❌          | ❌          | ✅             | Simple     |
| SJF       | ❌          | ✅          | ❌             | Complex    |
| SRTF      | ✅          | Less       | ❌             | Complex    |
| Priority  | ✅/❌        | ✅          | ❌             | Medium     |
| RR        | ✅          | ❌          | ❌             | Simple     |
| MLQ       | ❌          | ✅          | ✅             | Medium     |
| MLFQ      | ✅          | ❌          | ❌             | Complex    | -->

<!-- SJF → minimum WT but starvation
Priority → ageing solves starvation
RR → fairness + no starvation
MLQ → fixed queues → starvation
MLFQ → flexible queues → best practical -->

<!-- Race condition  -->
## a race condition occurs when multiple threads access shared data concurrently and the final result depends on the order of the execution 

<!-- solutions are 1)atomic operations 2)mutual exclusion (locks or mutex) 3) semaphores -->


## petersons solution --> works only for 2 threads 

## MUTEX/Locks

<!-- disadvantages -->

### 1) busy waiting , dead lock , hard debugging , starvation 


























































<!-- Condtional variables and semaphores  -->

### when multiple threads run together , they share data , they may enter critical sections and we must coordinate them safely --> this is called synchronization

## condition variable 
### => condition variable allows a thread to sleep until a specific condition becomes true, avoiding busy waiting. 
### => It is always used with a lock/mutex
### => lock is required with condition variables to protect shared data and to avoid race conditions 
### => when a thread calls wait() , the thread releases the lock , goes to waiting state and reacquires the lock when it is signaled 

# Semaphore 
## => a semaphore is an integral value variable which is represented by an integer value ,  used to control the access to the shared variable 
## => semaphore -> many resources , mutex -> 1 resource
## => semaphore = number of available resources , multiple threads may enter the critical section concurrently 

### 1) binary semaphore --> only one thread allowed , has value 0/1 , also called as mutex lock
### 2) counting semaphore --> controls access to finite instances of a resource 


<!-- Q1: How do semaphores avoid busy waiting?
A:By blocking the thread and placing it in a waiting queue instead of repeatedly checking the semaphore value

Q2: What happens when signal() is called on a semaphore?
A:It increments the semaphore and wakes up one blocked thread, moving it to the ready state. -->



<!-- Dining philosopher problem  -->

## -> imagine there are 5 philosophers , 1 bowl of noodles , 5 forks (1 between each other)
### --> a philosopher needs two forks to eat , a philosopher can pick only one fork at a time , so if a fork is already picked then it cannot be taken.. so deadlock happens 

## semaphore based solution 

<!-- wait(left_fork)
wait(right_fork)
eat
signal(left_fork)
signal(right_fork) -->

## if all the philosophers are hungry then every philosopher picks left fork but every philosopher cannot eat and deadlock occurs as no one release the fork 
## Because each philosopher may hold one fork and wait indefinitely for the other, creating circular wait.

# DeadLock conditions 

### --> mutual exclusion => fork can be held by one philosopher => only one process can use resource at time 
### --> Hold and wait => holding one fork , wait for another => holding one resource and waiting for another 
### --> No premption => resources cannot be forcibly taken => you cannot snatch resource from another one 
### --> circular wait => circular dependency of forks 

## -> solution --> atmost 4 philosopher can sit --> so one can get 2 forks and he can give after he has finished eating (NO circular waiting)
## -> solution --> atomic pickup of forks --> philosopher can take both the forks or non of the forks  (No hold and wait)

#### --->> using semaphores can also leads to the deadlock what we should do is correct design using semaphores 

# DeadLock 

## -->> a deadlock is situation where two or more processes are waiting indefinetely for resources help by each other , so no of them can proceed
## -->> when deadlock occurs processes never finish , resources are locked forever , other processes cant start , system performance degrades 

<!-- 1) Deadlock prevention  -->

## -> a)Mutual Exclusion --> allow sharing is possible , read-only files are shareable , cannot fully eliminate (some resources are non shareable)
## -> b)Hold and wait --> process must request all the resources at once (or) request resources only when holding none --> low resource utilization 
## -> c)No preemption --> if process cant get what it requires then take away what it holds
## -> d)Circular wait --> (most practical) -> assign order to the resources , always request resources in same order 
## By enforcing an ordering on resource acquisition so processes request resources in a fixed order , circular wait can be removes

<!-- Deadlock avoidance -->

## -> a)a safe state guarantees no deadlock , while an unsafe state may lead to the deadlock 

<!-- Bankers algorithm -->

## -> checks if granting request keeps system safe 
## => If yes --> allocate else Don't allocate 
## => used for deadlock avoidance 

### -> It is used for deadlock avoidance by ensuring the system remains in a safe state after resource allocation.

<!-- Deadlock detection -->

## --> a) single instance resource ==> wait for graph --> nodes are processes and edges are resources ==> if cycle exists then deadlocks exists
## --> b) multiple instance resource ==> similar to bankers algorithm 


<!-- Deadlock recovery -->
## once deadlock is detected then break it 
## --> a) process termination ==> kill one by one process until deadlock break or kill all the processes that are in deadlock 
## --> b) Resource preemption ==> take resource from one process , give it to another


<!-- Deadlock → infinite waiting
4 conditions → ME + H&W + NP + CW
Prevention → break a condition
Avoidance → safe state (Banker)
Detection → wait-for graph
Recovery → kill process / preempt resource -->

<!-- why memory management is needed -->

## => we have multiple processes in the main memory (ready queue) to keep the cpu utilization high we need memory management.
## => memory management is the function of the operating system that manages the primary memory by keeping track of every memory location , allocating the memory to processes and ensuring the protection and isolation among the processes 

## Logical Address(virtual address) => address seen by a program not real memory
## a logical address is an address generated by the cpu during program execution , It represents a reference to memory used by a process and doesnot correspond directly to a physical  memory location 

## physical address (actual location in RAM) (main memory)
## physical address is an address that refers to a specific location in the main memory . It is the address used by the memory hardware to access the data 

## Memory Management Unit (MMU)
## It is a translator between program and RAM , The memory management is a hardware device that performs runtime mapping of logical addresses generated by the cpu to physical addresses in main memory

## Address Translation 
## convert fake address -> Real address 
## process of converting a logical (virtual) address generated by the cpu into a physical address using the MMU 

## Relocation Register (Base register)
## tells where a process starts in RAM 
## the relocation register contains the value of the smallest physical address of the memory region allocated to a process .It is added to the logical address to obtain the physical address






















