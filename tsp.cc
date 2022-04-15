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

  std::ifstream readStream;
  readStream.open(filename);
  if(!readStream) {
    std::cerr << "Failed to open provided file \n";
    return 1;
  }
  Cities map;

  readStream >> map;    // Reads in the cities from the given file
  readStream.close();

  std::cout << map.get_city_list().size() << std::endl;

  double max = 1000000; // Iterates over a fixed number

  

  double shortestLen = 999999999999;
  // Generates a new random permutation

  std::ofstream outfile ("shortest.tsv");

  for(int i = 0; i < max; i++) {
    Cities::permutation_t order = map.random_permutation(map.get_city_list().size());
    Cities city = map.reorder(order);
    // Evaluates distance to travel the cities along this ordering;
    double newLen = map.total_path_distance(order);
    if(newLen < shortestLen) {
        shortestLen = newLen;
        std::cout << i << "\t" << shortestLen << "\n";
        outfile << i << "\t" << shortestLen << "\n";
    }


  }


  outfile << shortestLen << std::endl;
  outfile.close();


}


