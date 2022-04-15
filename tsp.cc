// CSCI 221 - HW9 (tsp.cc)
// Coded by Yik Yin Cheuk and Vaughn Zaayer

#include "cities.hh"
#include <fstream>
#include <iostream>
#include <cassert>

// Performs the actual search
int main(int argc, char** argv) {
  if(argc != 2) { // Make sure there is 2 arguements (1 is the program name, 2 is the input file)
    std::cerr << "No File Provided\n";
      return 1;
  }

  std::string filename = argv[1];

  std::ifstream readStream;
  readStream.open(filename);
  if(!readStream) { // If the file name is invalid, stop the program
    std::cerr << "Failed to open provided file \n";
    return 1;
  }
  
  Cities map;           // Declare the initial city object for the file

  readStream >> map;    // Reads in the cities from the given file
  readStream.close();

  double max = 1000000; // Iterates over a fixed number

  

  double shortestLen = 999999999999;
  // Generates a new random permutation

  std::ofstream outfile ("shortest.tsv");   // Initializes the output stream to "shortest.tsv"

  Cities::permutation_t shortestPermutation;

  for(int i = 0; i < max; i++) {
    // Generate a random order of cities
    Cities::permutation_t order = map.random_permutation(map.get_city_list().size());
    // Sort the city list into the random order in a new Cities object
    Cities city = map.reorder(order);
    // Evaluates distance to travel the cities along this ordering;
    double newLen = map.total_path_distance(order);
    if(newLen < shortestLen) {
        // If this path is the shortest found so far, save both the city order and the length
        shortestPermutation = order;
        shortestLen = newLen;
        std::cout << i << "\t" << shortestLen << "\n";
    }
  }

  // Reorder the cities into the shortest order found
  Cities shortestPath = map.reorder(shortestPermutation);
  for(auto city : shortestPath.get_city_list()) {
    // Put each city coordinate in the shortest order into shortest.tsv
    outfile << city.first << "\t" << city.second << "\n";
  }

  outfile.close();


}


