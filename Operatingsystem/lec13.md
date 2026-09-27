### process scheduling is the heart of the multitasking ,
### in a multi-programming os -> many processes are kept in memory at once , cpu switches from one to another to increase productivity and when one process waits(for I/O or time quantum over),OS switches to another , this switching is called scheduling.

## cpu scheduler

### cpu scheduler picks the next process , works when cpu becomes idle , pickes one from the ready queue , this job is done by the sts

## Non-preemptive scheduling

### once a process gets the cpu,it wont be interrupted , it runs till it finishes or goes to I/O , can lead to starvation, low cpu utilization due to idle times

## Premptive scheduling

### process can forcibly removed from the cpu , happens when time quantum expires , a higher priority process arrives benefits: less startvation and better cpu utilization

# Goals of cpu utilization 
<!-- ✅ 5. Goals of CPU Scheduling
Goal	What it means
🧠 Max CPU Utilization	Keep CPU busy as much as possible
⏱️ Min Turnaround Time	Finish processes faster
⏳ Min Wait Time	Less time spent in ready queue
⌛ Min Response Time	Quick first response
⚙️ Max System Throughput	More processes completed per second -->

<!-- ✅ 6-12. Important Scheduling Terms
Let’s connect the dots between all these:

Term	Definition	Formula
AT (Arrival Time)	When process enters ready queue	-
BT (Burst Time)	Time needed by CPU	-
CT (Completion Time)	When process finishes	-
TAT (Turnaround Time)	CT – AT	Time from arrival to end
WT (Wait Time)	TAT – BT	Time spent waiting
RT (Response Time)	First response delay	First CPU – AT
Throughput	No. of processes done per second	More = Better -->


#  FCFS – First Come, First Serve
<!-- Whichever process comes first, runs first.

🔸 Simple Rule:
Based on arrival time.

Non-preemptive.

🔸 Problem: Convoy Effect
If one long process comes first, it blocks all others.

Even small processes wait for long.

Bad resource usage.

🧠 Interview Tip:

“FCFS is easy to implement but leads to poor average performance because of convoy -->


# *convoy effect*

## convoy effect happens when one long proces blocks many shortes ones , causing poor resource utilization and longer waiting times ...so we use round robin method and srtf to reduce convoy effect i.e using premptive scheduling


