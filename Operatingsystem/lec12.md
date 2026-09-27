
### degree of multiprogramming => no:of processes that can exist in the ready queue

### long term scheduler increased the degree of multiprogramming 

# *Process*

### a process is just a program in execution i.e before execution it is just a program(static) after execution starts, it becomes a process(dynamic)

# *context switching*

### when the cpu switches from running one process to another, this switch is called context switching i.e

<!-- os saves thee state of the current process in its pcb and loads the state of the next process from its pcb then it resumes execution of the new process ==>> this includes saving program counter, cpu registers , stack pointers -->

# *orphan process*

### a process becomes orphan when its parent process terminates before it does 

<!-- int main() {
    if (fork() == 0) {
        sleep(5); // Child sleeps
        // By the time it wakes, parent has exited
    }
} -->

# *zombie process*

### a process becomes zombie when:
### it finishes execution,but its parent hasn't read its exit status yet , so it stays in the process table with a dead status until the parent does a wait()

## why do zombies exist?
### os keeps a record of a process's exit status so the parent can read it , until parent reads it , the child hangs around like a zombie

## when is it cleaned up?
### as soon as parent process calls wait(), the zombie is reaped and removed from the process table

<!-- Concept	Key Point
Process	        A running program (has code, data, registers)
Context Switch	CPU saves one process's state and loads another’s
Orphan Process	Child with dead parent, adopted by init
Zombie Process	Dead child, but not yet cleaned up by parent -->






