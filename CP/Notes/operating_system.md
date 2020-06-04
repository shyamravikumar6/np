<background style="color:#fffa28;" ></background>

# operating system 

## wating TIME 
it is the time when the process has  waited for the last and final turn in any scheduling.

![](https://media.geeksforgeeks.org/wp-content/uploads/round-robin-1.jpg)


### Alogrithm for RR 
```
  Create an array rem_bt[] to keep track of remaining
   burst time of processes. This array is initially a 
   copy of bt[] (burst times array)
2- Create another array wt[] to store waiting times
   of processes. Initialize this array as 0.
3- Initialize time : t = 0
4- Keep traversing the all processes while all processes
   are not done. Do following for i'th process if it is
   not done yet.
    a- If rem_bt[i] > quantum
       (i)  t = t + quantum
       (ii) bt_rem[i] -= quantum;
    c- Else // Last cycle for this process
       (i)  t = t + bt_rem[i];
       (ii) wt[i] = t - bt[i]
       (ii) bt_rem[i] = 0; // This process is over
```
```
// C++ program for implementation of RR scheduling 
#include<iostream> 
using namespace std; 

// Function to find the waiting time for all 
// processes 
void findWaitingTime(int processes[], int n, 
			int bt[], int wt[], int quantum) 
{ 
	// Make a copy of burst times bt[] to store remaining 
	// burst times. 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; // Current time 

	// Keep traversing processes in round robin manner 
	// until all of them are not done. 
	while (1) 
	{ 
		bool done = true; 

		// Traverse all processes one by one repeatedly 
		for (int i = 0 ; i < n; i++) 
		{ 
			// If burst time of a process is greater than 0 
			// then only need to process further 
			if (rem_bt[i] > 0) 
			{ 
				done = false; // There is a pending process 

				if (rem_bt[i] > quantum) 
				{ 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					t += quantum; 

					// Decrease the burst_time of current process 
					// by quantum 
					rem_bt[i] -= quantum; 
				} 

				// If burst time is smaller than or equal to 
				// quantum. Last cycle for this process 
				else
				{ 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					t = t + rem_bt[i]; 

					// Waiting time is current time minus time 
					// used by this process 
					wt[i] = t - bt[i]; 

					// As the process gets fully executed 
					// make its remaining burst time = 0 
					rem_bt[i] = 0; 
				} 
			} 
		} 

		// If all processes are done 
		if (done == true) 
		break; 
	} 
} 

// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int n, 
						int bt[], int wt[], int tat[]) 
{ 
	// calculating turnaround time by adding 
	// bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

// Function to calculate average time 
void findavgTime(int processes[], int n, int bt[], 
									int quantum) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	// Function to find waiting time of all processes 
	findWaitingTime(processes, n, bt, wt, quantum); 

	// Function to find turn around time for all processes 
	findTurnAroundTime(processes, n, bt, wt, tat); 

	// Display processes along with all details 
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 

	// Calculate total waiting time and total turn 
	// around time 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
} 

// Driver code 
int main() 
{ 
	// process id's 
	int processes[] = { 1, 2, 3}; 
	int n = sizeof processes / sizeof processes[0]; 

	// Burst time of all processes 
	int burst_time[] = {10, 5, 8}; 

	// Time quantum 
	int quantum = 2; 
	findavgTime(processes, n, burst_time, quantum); 
	return 0; 
} 
```
```

    Completion Time: Time at which process completes its execution.
    Turn Around Time: Time Difference between completion time and arrival time. Turn Around Time = Completion Time – Arrival Time
    Waiting Time(W.T): Time Difference between turn around time and burst time.
    Waiting Time = Turn Around Time – Burst Time
```

## Race condition 
- When more than one processes are executing the same code or accessing the same memory or any shared variable in that condition there is a possibility that the output or the value of the shared variable is wrong so for that all the processes doing race to say that my output is correct this condition known as
race condition.

- Several processes access and process the manipulations over the same data concurrently, then the outcome depends on the particular order in which the access takes place. 

## Critical Section Problem

- Critical section is a code segment that can be accessed by only one process at a time. Critical section contains shared variables which need to be synchronized to maintain consistency of data variables.
critical section problem.
![](https://www.geeksforgeeks.org/wp-content/uploads/gq/2015/06/critical-section-problem.png)


#### conditon to follow the Critical section 

- Any solution to the critical section problem must satisfy three requirements:

 -    Mutual Exclusion : If a process is executing in its critical section, then no other process is allowed to execute in the critical section.
   
   -  Progress  : If no process is executing in the critical section and other processes are waiting outside the critical section, then only those processes that are not executing in their remainder section can participate in deciding which will enter in the critical section next, and the selection can not be postponed indefinitely.
   
   -  Bounded Waiting : A bound must exist on the number of times that other processes are allowed to enter their critical sections after a process has made a request to enter its critical section and before that request is granted.

# Peterson’s Solution
Peterson’s Solution is a classical software based solution to the critical section problem.

In Peterson’s solution, we have two shared variables:

    boolean flag[i] :Initialized to FALSE, initially no one is interested in entering the critical section
    int turn : The process whose turn is to enter the critical section.

  ![](https://www.geeksforgeeks.org/wp-content/uploads/gq/2015/06/peterson.png)


  ## Semaphores

  A Semaphore is an integer variable, which can be accessed only through two operations wait() and signal().
There are two types of semaphores : Binary Semaphores and Counting Semaphores

   - <B>Binary Semaphores :</B> They can only be either 0 or 1. They are also known as mutex locks, as the locks can provide mutual exclusion. All the processes can share the same <color="Red" mutex /> semaphore that is initialized to 1. Then, a process has to wait until the lock becomes 0. Then, the process can make the mutex semaphore 1 and start its critical section. When it completes its critical section, it can reset the value of mutex semaphore to 0 and some other process can enter its critical section.
   
- <B><i> Counting Semaphores: </i></B> They can have any value and are not restricted over a certain domain. They can be used to control access to a resource that has a limitation on the number of simultaneous accesses. The semaphore can be initialized to the number of instances of the resource. Whenever a process wants to use that resource, it checks if the number of remaining instances is more than zero, i.e., the process has an instance available. Then, the process can enter its critical section thereby decreasing the value of the counting semaphore by 1. After the process is over with the use of the instance of the resource, it can leave the critical section thereby adding 1 to the number of available instances of the resource.

true


# <B><span style="color:red">Semaphores in Process Synchronization</span></B>

- First, look at two operations which can be used to access and change the value of the semaphore variable.

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Semaphores_1.png)

Some point regarding P and V operation

    P operation is also called wait, sleep or down operation and V operation is also called signal, wake-up or up operation.
    Both operations are atomic and semaphore(s) is always initialized to one.Here atomic means that variable on which read, modify and update happens at the same time/moment with no pre-emption i.e. in between read, modify and update no other operation is performed that may change the variable.
    A critical section is surrounded by both operations to implement process synchronization.See below image.critical section of Process P is in between P and V operation.

```
struct semaphore { 
	enum value(0, 1); 

	// q contains all Process Control Blocks (PCBs) 
	// corresponding to processes got blocked 
	// while performing down operation. 
	Queue<process> q; 

} P(semaphore s) 
{ 
	if (s.value == 1) { 
		s.value = 0; 
	} 
	else { 
		// add the process to the waiting queue 
		q.push(P) 
			sleep(); 
	} 
} 
V(Semaphore s) 
{ 
	if (s.q is empty) { 
		s.value = 1; 
	} 
	else { 

		// select a process from waiting queue 
		q.pop(); 
		wakeup(); 
	} 
} 
```
### Counting semaphore 

```
struct Semaphore { 
	int value; 

	// q contains all Process Control Blocks(PCBs) 
	// corresponding to processes got blocked 
	// while performing down operation. 
	Queue<process> q; 

} P(Semaphore s) 
{ 
	s.value = s.value - 1; 
	if (s.value < 0) { 

		// add process to queue 
		// here p is a process which is currently executing 
		q.push(p); 
		block(); 
	} 
	else
		return; 
} 

V(Semaphore s) 
{ 
	s.value = s.value + 1; 
	if (s.value <= 0) { 

		// remove process p from queue 
		q.pop(); 
		wakeup(p); 
	} 
	else
		return; 
} 
```


## Deadlocks 
- <B><span style="font-size:25	px">conditions for the deadlock</span></B> 

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2015/06/deadlock.png)

 
- Deadlock can arise if following four conditions hold simultaneously (Necessary Conditions)
Mutual Exclusion: One or more than one resource are non-sharable (Only one process can use at a time)

<B><span style="color:#ff3de4;">Hold and Wait:<span></B> A process is holding at least one resource and waiting for resources.
No Preemption: A resource cannot be taken from a process unless the process releases the resource.
Circular Wait: A set of processes are waiting for each other in circular form.




##  <B><span style="color:orange;">Eliminate Hold and wait

    Allocate all required resources to the process before the start of its execution, this way hold and wait condition is eliminated but it will lead to low device utilization. for example, if a process requires printer at a later time and we have allocated printer before the start of its execution printer will remain blocked till it has completed its execution.
    The process will make a new request for resources after releasing the current set of resources. This solution may lead to starvation.

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2015/06/holdnwait.png)


### process and threads 

- A thread is a path of execution within a process. A process can contain multiple threads. 

<B> what is multi-threading?
 A thread is also known as lightweight process. The idea is to    achieve parallelism by dividing a process into multiple threads. For example, in a browser, multiple tabs can be different threads. MS Word uses multiple threads: one thread to format the text, another thread to process inputs, etc. More advantages of multithreading are discussed below

- Process vs Thread?
 The primary difference is that threads within the same process run in a shared memory space, while processes run in separate memory spaces.
 Threads are not independent of one another like processes are, and as a result threads share with other threads their code section, data section, and OS resources (like open files and signals). But, like process, a thread has its own program counter (PC), register set, and stack space.

## User level thread 	Kernel level thread
- User thread are implemented by users. 	kernel threads are implemented by OS.
- OS doesn’t recognized user level threads. 	
- Kernel  threads are recognized by OS.
Implementation of User threads is easy. 	
- Implementation of Kernel thread is complicated.
Context switch time is less. 	
- Context switch time is more.
Context switch requires no hardware support. 	
- Hardware support is needed.
- If one user level thread perform blocking operation then entire process will be blocked. 	
- If one kernel thread perform blocking operation then another thread can continue execution.
- User level threads are designed as dependent threads. 	Kernel level threads are designed as independent        threads.
- Example : Java thread, POSIX threads. 	Example : Window Solaris.



 ## Resource Allocation graph 
 So, resource allocation graph is explained to us what is the state of the system in terms of processes and resources. Like how many resources are available, how many are allocated and what is the request of each process. 

 ![](https://media.geeksforgeeks.org/wp-content/uploads/Slide2.jpg)
 

### partion allocation 
Fixed partition 
This is the oldest and simplest technique used to put more than one processes in the main memory. In this partitioning, number of partitions (non-overlapping) in RAM are fixed but size of each partition may or may not be same. As it is contiguous allocation, hence no spanning is allowed. Here partition are made before execution or during system configure. 

![](https://media.geeksforgeeks.org/wp-content/uploads/444-4.png)







Disadvantages of Fixed Partitioning –

    Internal Fragmentation:
    Main memory use is inefficient. Any program, no matter how small, occupies an entire partition. This can cause internal fragmentation.
    External Fragmentation:
    The total unused space (as stated above) of various partitions cannot be used to load the processes even though there is space available but not in the contiguous form (as spanning is not allowed).
    Limit process size:
    Process of size greater than size of partition in Main Memory cannot be accommodated. Partition size cannot be varied according to the size of incoming process’s size. Hence, process size of 32MB in above stated example is invalid.
    Limitation on Degree of Multiprogramming:
    Partition in Main Memory are made before execution or during system configure. Main Memory is divided into fixed number of partition. Suppose if there are n1 partitions in RAM and n2 are the number of processes, then n2 <= n1 condition must be fulfilled. Number of processes greater than number of partitions in RAM is invalid in Fixed Partitioning.


### Logical and Physical Address in operating system
- 	<B>The logical address is virtual address as it does not exist physically, therefore, it is also known as Virtual Address. This address is used as a reference to access the physical memory location by CPU. The term Logical Address Space is used for the set of all logical addresses generated by a program’s perspective.
The hardware device called Memory-Management Unit is used for mapping logical address to its corresponding physical address. 

### Relocation 

The available memory is generally shared among a number of processes in a multiprogramming system, so it is not possible to know in advance which other programs will be resident in main memory at the time of execution of his program. Swapping the active processes in and out of the main memory enables the operating system to have a larger pool of ready-to-execute process.

![](https://media.geeksforgeeks.org/wp-content/uploads/aas6.png)

## paging in operating systems

- Paging is a memory management scheme that eliminates   the  need for contiguous allocation of physical memory.  This scheme permits the physical address space of a  process to be non – contiguous.

    <i>Logical Address or Virtual Address (represented in bits):</i> An address generated by the CPU
    Logical Address Space or Virtual Address Space( represented in words or bytes): The set of all logical addresses generated by a program
    Physical Address (represented in bits): An address actually available on memory unit
    Physical Address Space (represented in words or bytes): The set of all physical addresses corresponding to the logical addresses.



	## virtual memory in operating systems 
	- Virtual Memory is a storage allocation scheme in which secondary memory can be addressed as though it were part of main memory. The addresses a program may use to reference memory are distinguished from the addresses the memory system uses to identify physical storage sites, and program generated addresses are translated automatically to the corresponding machine addresses.	

	### Demand Paging 
		The process of loading the page into memory on demand (whenever page fault occurs) is known as demand paging.
The process includes the following steps :

![](https://media.geeksforgeeks.org/wp-content/uploads/VirtualDiagram-1.png)

virtual_mem

    * If CPU try to refer a page that is currently not available in the main memory, it generates an interrupt indicating memory access fault.

    * The OS puts the interrupted process in a blocking state. For the execution to proceed the OS must bring the required page into the memory.

    The OS will search for the required page in the logical address space.

    * The required page will be brought from logical address space to physical address space. The page replacement algorithms are used for the decision making of replacing the page in physical address space.
    The page table will updated accordingly.
	
    * The signal will be sent to the CPU to continue the program execution and it will place the process back into ready state


### Cache Memory in Computer Organization

- Cache memory increases the accessing speed of   CPU.




- It is not a technique but a memory unit i.e a  storage device. In cache memory, recently used  data is copied. Whenever the program is ready to  be executed, it is fetched from main memory and  then copied to the cache memory. But, if its copy  is already present in the cache memory then the program is directly executed.


## Inverted page table in operating systems 


  - Most of the Operating Systems implement a separate pagetable for each process, i.e. for ‘n’ number of processes running on a Multiprocessing/ Timesharing operating system, there are ‘n’ number of pagetables stored in the memory. Sometimes when a process is very large in size and it occupies virtual memory then with the size of the process, it’s pagetable size also increases substantially.



### Inverted Page table 
```
- An alternate approach is to use the Inverted Page Table structure that consists of one-page table entry for every frame of the main memory. So the number of page table entries in the Inverted Page Table reduces to the number of frames in physical memory and a single page table is used to represent the paging information of all the processes. 
```