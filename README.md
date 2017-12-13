# Introduction

Class Project for CSCE 629 Analysis of Algorithms, Fall 2017.

Github Repository located at: https://github.com/caffrey26/network-optimization

This project implements a network routing protocol, Max-Bandwidth-Path problem: to ﬁnd a path of the maximum bandwidth between two vertices in a given weighted undirected graph. 
Following parts were implemented: 

1. Random graph generation: a.) 5000 vertices, with average degree of 8. b.) 5000 vertices, with each vertex being adjacent to about 20% of the other vertices.
2. An algorithm for Max-Bandwidth-Path based on a modiﬁcation of Dijkstra’s algorithm without using a heap structure; 
3. An algorithm for Max-Bandwidth-Path based on a modiﬁcation of Dijkstra’s algorithm using a heap structure for fringes;
4. An algorithm for Max-Bandwidth-Path based on a modiﬁcation of Kruskal’s algorithm, in which the edges are sorted by HeapSort.

The program also captures the run time of the algorithms for comparison, and prints the max bandwidth path.

## Authors             

Rahul Saini (rssaini @ tamu . edu)


## Build Project
In a terminal window with the directory changed to project directory, run the following command:
> g++ -std=c++11 *.cpp -o a.exe

This will produce the executable file in a.out

### Run Project        

> ./a.out

> returns the max bandwidth path, along with the time taken by the three algorithms


