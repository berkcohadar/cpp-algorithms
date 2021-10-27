# Contributors
Berk COHADAR
Aleyna CEYLAN
Ayca Ege KAYHAN


-INFO-

Our project's aim is to calculate the efficiency of some sorting and searching algorithms. 
These algorithms are quick sort, bubble sort, merge sort, heap sort, selection sort, insertion 
sort, linear search, binary search and lastly, jump search. Our aim is to calculate the time 
spent and operations (swaps etc.) made on each algorithm with the same amount of elements. 

SORTING:

When comparing 10.000 elements;

While quick sort, merge sort and heap sort is quite close to each other in terms of time consumption; 
bubble sort, selection sort and insertion sort is much slower when compare. The algorithms are tested 
with different order styles, and they show different results for different orders. For example, 
bubble sort and insertion sort make no operations when the data is already sorted, however they 
make huge amount of operations when the data is sorted in reversed order. Additionally, selection 
sort makes SIZE-1 operations every time no matter what the order type is. 



When comparing 1.000.000 elements;

Bubble sort, selection sort and insertion sort do not work because of their huge amount of swap 
operations. On the other hand, merge sort, quick sort and heap sort works really well. We can see 
the efficiency difference here between these algorithms, not like with 10 thousand elements. 
We see that the most efficient sort algorithm is merge sort, then quick sort, and then heap sort.

SEARCHING:

For searching algorithms with 1 million elements, all three algorithms are very close to each in terms of time consumption; 
however, the number of operations made in these algorithms differ. Binary search is the most effective 
and linear search is the least in terms of operation amount. Additionally, jump search's operation 
amount differs according to the wanted value. 
