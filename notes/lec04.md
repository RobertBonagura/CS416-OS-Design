2-3-20 - ch 7 - 9
# CPU Virtualization: Two Components
### Dispatcher (previous lectures)

##  OS Scheduler (today)
### Policy to determine which process gets CPU when

### State transitions
Running, Ready or Blocked

## Vocab
**workload** - set of job descriptions (arrival time, run_time)
* job - View as current CPU burst of a process

Processes are alternated between CPU and I/O, and move between ready and blocked queues.

The Scheduler is logic that decides which ready job to run.

## Scheduling Performance Metrics
There are alot of Scheduling Performance Metrics:
* Minimize turnaround time
    * Overall application runtime
    * Completion_time - arrival_time
* Minimize response time
    * Amount of time for process to begin
    * Doe not need the job to complete
    * initial_Schedule_time - arrival_time
        * initial _scuedule_time is when the process is moved from the ready state to the running state.
* Minimize time process is waiting in ready queue
    * mostly specific to I/O data
* Maximize throughput
    * Prioritizing many jobs to complete per unit of time
    * **Latency** is time taken to send packet from source A to destination B, independent of how many packets are being sent.
    * **Throughput** is how many packets can be sent simultaenously, which is a result of bandwidth.
    * If I keep increasing the number of users in the case of scheduling, at a certain limit I will need to wait - which means latency may increase.
* Maximizie resource utilization
    * Not caring about performance, throughput, or latency
    * Instead, focusing on keeping expensive devices busy -  not really used much, except by maybe for hackers
* Minimize overhead
    * Reduce number of context swithces
* Maximize fairness
    * High number of context-switches, though may not be most efficient in terms of overhead.

## Scheduling Basics

####  Workload Assumptions for Scheduling Algorithm examples:
1. Each job runs for the same amount of time
2. All jobs arrive at the same time
3. All jobs only use the CPU (no I/O)
4. The runetime of each is known

### FIFO - First In, First Out
Run jobs in arrival_time order

turnaround_time = completion_time - arrival_time

### Workload Assumptions
1. ~~Each job runs for the same amount of time~~
2. All jobs arrive at the same time
3. All jobs only use the CPU (no I/O)
4. The runetime of each is known 

FIFO is not good approach if out first job is the biggest, as it slows down all other processes

### SFJ - Shortest Job First
Choose job with smallest run_time

### Workload Assumptions
1. ~~Each job runs for the same amount of time~~
2. ~~All jobs arrive at the same time~~
3. All jobs only use the CPU (no I/O)
4. The runetime of each is known 

If the jobs come at staggerd times, a short job may come after a long job has already started. 

This is where introduce the context switch

### STCF - Shortest Time to Completion First
When a job arrives that is shorter than the currenlty running job, switch to the shorter job.

So far we have only looked at turn-around time, not really response time though. One in particular that enahnces response time is Round Robin


### RR - Round Robin 
Run for some specific amount of time, context switch and repeat.

response_time = first_run_time - arrival_time

#### Response vs Turnaround
In a simple example, RR can run in same turnaround_time as FIFO, with a siginficant cut in response_time.

#### When is RR worse?
* If average turnaround time with equal jobs lengths is horrible
* If one job is much more important than another
* If cost of swithcing is expensive.

#### When is RR better
Works well when you dont know actual run time of msot jobs, which is true in most cases.
