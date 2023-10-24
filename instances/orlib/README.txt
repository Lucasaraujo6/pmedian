OR-Library
J E Beasley
OR-Library is a collection of test data sets for a variety of OR problems.

A full list of the test data sets available in OR-Library can be found here.

p-median - uncapacitated
There are currently 40 data files.

These data files are the 40 test problems from Table 2 of
J.E.Beasley "A note on solving large p-median problems" European
Journal of Operational Research 21 (1985) 270-273.

Test problems 1, 2, ..., 40 from Table 2 of that paper are 
available in files pmed1, pmed2, ..., pmed40 respectively.

The format of these data files is:
number of vertices, number of edges, p
for each edge: the end vertices and the cost of the edge

As noted in the above paper Floyd's algorithm needs to be applied
to the cost matrix given by the data file in order to obtain
the complete allocation cost matrix.

------------------------------------------------------------------
My thanks (2/May/95) to Professor Avella of Universita di Salerno 
for pointing out that it is unclear (due to the presence of
multiple edges in these data files) how to generate the
complete allocation cost matrix. Accordingly in psuedo-code
it is:

Let n be the number of vertices
Set c(i,j)=infinity for i=1,...,n j=1,...,n.
    c(i,i)=0 for i=1,...,n
Read each edge line in the data file IN TURN:
   if the three numbers in the line are i,j,k then
   set c(i,j)=k and c(j,i)=k
Then subject the matrix c to Floyd's algorithm to get a
symmetric allocation cost matrix.

The effect of this is that in the event of edge (i,j) having
different costs in the data file only the last such cost is used.

Apologies for any confusion.
------------------------------------------------------------------

The value of the optimal solution for each of these data files 
is given in the file pmedopt.

The largest file is pmed40 of size 250Kb (approximately).
The entire set of files is of size 3200Kb (approximately).
