2-6-20
# CPU Virtualizatin: Scheduling (continued)
Questions answered in this lecture:

## Preemptive Scheduling
We looked at some examples that are not preemptive
* FIFO and SJF

A preemptive scheduler is one that can stop the current job when neccessary if a new job enters.

#### Review of Scheduling Basics (from last lectures slides)

Because we can not assume we know how long any given process will run, we need a smarter, fancier scheduler to handle this.

## MLFQ - Multi-Level Feedback Queue
Must support two job types with distinct goals
* **interactive** programs care about **response time**
* **batch** programs care about **turn-around time**

Approach: Must have multiple levels of round-robin, where each level has higher priority than lower levels and preempts them.

MLFQ has a number of disitinct queues - Each assigned a different proority level.

## Priorities
* Rule 1: If priority(A) > priority(B) , A runs
* Rule 2: If priority(A) == priority(B), A & B run in RR

Problem with implemenintng only ehse two rules is that **starvation** can occur, where low priority processes will never run.

Let us use the processes **hirstory**, so using past behavior of process to determine future priority.

* Rule 3: Prrocesses start at top priority
* Rule 4: If job uses whole slice, demoet process (longer time slices drop to lower priorities)

Rules 3 and 4 help prevent starvation, but do not prevent it completely.

Also can not prevent *gaming the system*.

We want to find a scheduler to introduce some *fairness*. Basic fix would be to periodically boost priority of all jobs.

*Question: Does MLFQ fix this issue?*

## Lottery Scheduling
Goal - Fair scheduler, note necccessarily to optimze turnaround or response time.

Guarantee that each job obtain a certain percentage of CPU time.

Approach:
* Give process lottery tickets
* Whoever wins runs
* higher priority => more tickets

Ticekts:
* represent the share of a resource that a process should recieve.
* perecent of tickets represent share of CPU resources.

The scheduler picks a winning ticket, and CPU resources are devoted to that process for a some given period of time.

### Lottery example
Uses a link list to hold jobs to prevent starvation

Other things (Ticekt transfers, ticket currencies, ticket inflation) in OSTEP book - not covered in lecture though.

The problem is that Lottery Scheduling is not scalable in systems with multiple processors.

## Multiprocessor Scheduling
Adding more CPU's does not make that single application run faster.
* Instead, it makes sense to reqrite applications to be written using threads.

### Single CPU with cache
#### Cache Coherence
To prevent cache data inconsistency problem
Bus snooping, where each cache pays attention to 

## Cache Affinity
Keep a process on the same CPU if at all possible.
* A process builds up a fair bit of state in the cahse of the CPU
* The next time the process runs, it will run faster if some of its state is already present in the cache of the CPU

A mulitiprocessor scheduler should consider **cache affinity** when making its scheduling decision.


If you put all jobs that need to be scheduled into a single queue.
* Each CPU simply picks the next job form the globally shared queue
* Cons
    * Some forms of locking have to be inserted -> lack of scalability
    * No cahce affinity

#### Scheduling Cache Affinity
See photo on slide.

## MQMS - Multi-Queue Multiprocessor Scheduler

Provides more scalability and cache affinity.

## CFS - Completely Fair Scheduler
CFS is built over MQMS

CFS changes or removes time-slice allotment - depends isntead on number of jobs present in system.