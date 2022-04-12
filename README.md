# CS221 - HW9: TSP project 
Coded by Yik Yin Cheuk and Vaughn Zaayer
## cities.hh
## cities.cc
- Constructor: Stores the vector of pairs as the member cityVect_
- operator >>: Reads from the input istream.
- operator <<: Stores the ordering of coordinates. 
- dist_between: Helper method to be used for the total_path_distance method. 
- total_path_dist: Returns the total path distance for a given ordering of cities.
- reorder: Given a permutation vector as an argument and returns a cities object based on that vector. 
- random_permutation: Returns a random permutation of ints 0 to len-1 then uses the shuffle method on that vector. 
## tsp.cc
