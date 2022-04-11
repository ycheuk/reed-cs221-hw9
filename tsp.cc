// CSCI 221 - HW9 (tsp.cc)
// Coded by Yik Yin Cheuk and Vaughn Zaayer

#include "cities.hh"

// Performs the actual search
int main(int argc, char** argv) {
  if(argc != 2) {
    std::cerr << "No File Provided\n";
      return 1;
  }
