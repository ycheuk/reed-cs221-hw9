// CSCI 221 - HW9 (tsp.cc)
// Coded by Yik Yin Cheuk and Vaughn Zaayer

#include "cities.hh"
#include <fstream>
#include <iostream>
#include <cassert>

// Performs the actual search
int main(int argc, char** argv) {
  if(argc != 2) {
    std::cerr << "No File Provided\n";
      return 1;
  }

  std::string filename = argv[1];


  std::cout << filename << std::endl;
  std::ifstream readStream;
  readStream.open(filename);
  if(!readStream) {
    std::cerr << "Failed to open provided file \n";
    return 1;
  }
  Cities map;

  readStream >> map;    // Reads in the cities from the given file
  readStream.close();

  int max = 1000000; // Iterates over a fixed number

  std::cout << "TSP pass" << std::endl;

  // Generates a new random permutation
  for(int i = 0; i < max; i++) {
    Cities::permutation_t order = map.random_permutation(map.get_city_list().size());
    Cities city = map.reorder(order);
    // Evaluates distance to travel the cities along this ordering;
    double newLen = map.total_path_distance(order);
    double shortestLen;
    if(newLen < shortestLen) {
        shortestLen = newLen;
        std::cout << i << "\t" << shortestLen << "\n";
    }

    std::ofstream outfile ("shortest.tsv");
    outfile << shortestLen;
    outfile.close();

  }
}
