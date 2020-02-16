Question 4. Consider a scenario where there are N processes to be completed. All the processes have a unique number assigned to them from 1 to N. Now, you are given two things:
The ideal order in which all the processes should have been executed.
The calling order in which all the processes are called.
For example, let's say that there are 3 processes. The ideal order is: 1 -> 3 -> 2. However, the calling order of the processes is: 3 -> 2 -> 1. Since the ideal order has process #1 to be executed firstly, the calling ordered is changed, i.e., the first element has to be pushed to the last place. Changing the position of the element takes 1 unit of time. Now, the new calling order is: 2 - 1. Since the ideal order has process #1 to be executed firstly, the calling ordered has to be changed again, i.e., the first element has to be pushed to the last place. The new calling order is thus: 1 - 3 - 2. Since the first element of the calling order is now same as the ideal order, that process will be executed and it will be popped out which also takes 1 unit of time. In this way all processes are changed according to ideal order and executed. Executing a process and changing the position takes 1 unit of time. Objective is to compute total time in executing all the input processes.
Input format:
The first line a number N, denoting the number of processes. The second line contains the calling order of the processes. The third line contains the ideal order of the processes.
Output format:
Print the total time taken for the entire queue of processes to be executed.

Sample Input:
3
3 2 1
1 3 2
Output:
5
