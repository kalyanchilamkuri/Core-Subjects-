
## shortest job first(sjf) - non-preemptive

### pick the process with the smallest burst time(BT) and run it completely before picking the next shortest job

### Advantages => gives minimum averaeg waiting time for a given set of processes and good throughput if jobs are small

### Disadvantages => starvation -> long jobs might never run if short ones keep arriving and needs BT estimation which is hard in real systems and can cause convoy effect if first job is too long

## shortest job first(sjf) - preemptive

### if a new job arrives with BT less than the remaining time of current job,the cpu switched.

### Advantages => lowest average waiting time , no convoy effect and less starvation than non-preemptive 

### Disadvantages => still needs BT estimation and short jobs always preempt long ones -> starvation possible

## Priority scheduling - Non preemptive

### each process gets a priority number (lower number = higher priority) and highest priority job runs next

### Advantages => useful when some tasks are truely more urgent and simple to implement 

### disadvantages => starvation: low-priority jobs might never run and sjf is just a special case of this.

### solution for this is Aging=> gradually increase priority ofwaiting jobs(eg:+1 for every 15 minutes)

## Round Robin (RR)

### like fcfs, but each process get a time slice(TQ) , if not finished , goes back to the end of the queue

### advantages => fair and responsive , no starvation and no convoy effect

### Disadvantages => if TQ is too small => too many context switches and if TQ is too large it acts like fcfs,delayssmall tasks


## Multilevel Queue scheduling

### the ready queue is split into multiple queues and each queue is for a specific type of process => like system processes , interactive (fore ground) processes , batch (back ground) processes 

### Key features => each process is permanently assigned to one queue base on priority , process type , memory needs and each queue uses its own scheduling algorithm , between queues there will be fixed priority preemptive scheduling

## Advantages 
### good seperation of concerns and guarantees fast response for high priority processes 

## Disadvantages
### Inflexible => process cannot move between queues and starvation for lower-priority queues and convoy affect can happen


## Multi-level feedback queue

### An improved version of MLQ - allows processes to move between queues => it is dynamic , more flexible and smart

### key features=>
### *) multiple queues like mlq , but processes can move between queues based on behavior --> cpu-bound processes => gradually move down , I/O bound or interactive => stay or move up

### => a process starts in a high priority queue , if it used too much cpur time (exceeds its time quantum) => it is moved to a lower priority queue , if it waits too long(aging),it may be promoted to a higher-priority queue

## *Advantages*
### less starvation , flexible and responsive to process behavior 

## *Disadvantages*
### complex to implement , difficult to tune 

