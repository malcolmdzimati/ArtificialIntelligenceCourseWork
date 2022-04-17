The manhattan heuristic, looks at each of the numbers current position and compares it to
the position of the same number in the goal state and it calculates the distance between the
two. It does this for every number and sums the total and that is the total heuristic of the
entire puzzle. The Manhattan distance/heuristic never overestimates the optimal heuristic as
every tile will have to be moved at least the number of spots in between itself and its correct
position.

Children were generated in left, right, up down. And for the assignment customer data
structures were used with each implementation having their own variation. With most
combining hash sets for O(1) lookup and queues, priority queues or dequeue for ordered
insertion and deletion each with custom hash functions and customer comparative functions
to allow for object comparative based on heuristics. The data puzzles were stored in a one
dimensional array of integers. Source code provided for further inspection if required.
