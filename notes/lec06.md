2-10-20
# Lecture 6 - 

## Multiprocessor Scheduling
Adding more CPUs does not make that single application run faster
* It is required to rewrite the application to run in parallel, using **threads**.

Two things we need to take into consideration when designing a multiprocessor scheduler.
* Cache affinity
* Scalability - how do I avoid using the same data structure acaross multiple processes - ensureing all CPUs run in parallell and never have to merge into the same lane.

Cache coherence solution: *bus snooping*

Cache affinity is simply preventing any given process from running acorss multiple CPUs.

Thus we implement the Multi-queue Multiprocessor Scheduling (MQMS)

## Completely Fair SCheduler
CFS changes or removes time-slice allotment.
* In previous discussions of schedulers, weve always assuemd we knew the value of the time slice. In the CFS this value is completely dynamic and based on the number of processes in your system.
* Assign each process a proprotion of the processor (this could change very 100 ms)
* Yields constant fairness but a variable switching rate.

Simple concept - Goal is to be as fair as possible.

If n processes at a given time:
* Each process receives 1/n of the processors time.
* Would be scheduled for infitely small durations. (1 / infinit)
* In any measurable period, all n processes would run for the same amount of time.

Assume there are two processes:
* Unix model - run one process for 5ms and another for 5ms
* Each process receiveds 100% of the processor.
* IDEAL System: perfect multitasking processor
    * Run both processes sumultaneaously for 10 ms
    * Each at 50% power - called perfect multitasking

Why does IDEAL not really work? It is hard to control and tell the process to use half the CPU. Therefore, we will continue to use the Unix model.

CFS ranks processes absed on their worth and need for process time.

Processes with high priority run before those with a lower priority.

Linux has two priority ranges
* Nice value: ranges form -20 to +19 (Deafult is 0)
* High values of nice means lower priority
* Real-time priority: ranges from 0 to 99
* Higher values mean higher priority
* Real-time jobs always executes before standard (nice) processes

This commmand shows niceness of process:
```
ps ax -eo pid,ni,rtprio,cmd
```

We are going to look primarily at

### Linux CFS
Assume targeted latency is 20 ms

**targeted latency** - minimum amount of time  - idealized to an infinitely small duration - required for every runnable task to get at least one turn on the processor.

**Minimum Granularity** - smposes a floor on the timeslice assigned to each process.

For example: run 1 ms to ensure there is a ceiling on the incurred switching costs

Not completely fair when the number of processes grows so large.
