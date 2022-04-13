// CSCI 221 - HW9 (cities.cc)
// Coded by Yik Yin Cheuk and Vaughn Zaayer

#include "cities.hh"
#include <vector>
#include <iostream>
#include <algorithm>

void Cities::append_city_list(const coord_t& city) {
  cityVect_.push_back(city);
}

/*
std::vector<Cities::coord_t> get_city_list() {
  return cityVect_;
}
*/

// Used to calculate the distance between two city's coordinates
double Cities::dist_between(const coord_t& cityA, const coord_t& cityB) const {
  // Thank you Gabe for telling me there was a better method :)
  return std::hypot(static_cast<double>(cityA.first-cityB.first), static_cast<double>(cityA.second-cityB.second));
}

std::istream& operator >> (std::istream& input, Cities& cities){
    int x;
    while(input >> x) { // While stream is not done
        Cities::coord_t pair;
        pair.first = x;
        input >> pair.second;
        cities.append_city_list(pair);
    }
    return input;
}

std::ostream& operator << (std::ostream& output, Cities& cities){
    for(Cities::coord_t elm: cities.get_city_list()){
        output << elm.first << "\t" << elm.second << "\n";
    }
    return output;
}

// Returns total path distance
double Cities::total_path_distance(const permutation_t& ordering) const {
  auto cityPath = reorder(ordering).cityVect_;
  // The total distance to traverse the cities in the order given by the permutation
  double distance = dist_between(cityPath.at(0), cityPath.at(cityPath.size()-1));
  // Loop the distance between cities
  for (unsigned int i = 1; i < cityPath.size(); i++){
      distance += dist_between(cityPath.at(i), cityPath.at(i - 1));
  }
  return distance;
}

Cities Cities::reorder(const permutation_t& ordering) const {
  auto newOrder = new Cities();
  std::vector<coord_t> permutedElmts;
  for (int i : ordering){
      permutedElmts.push_back(this->cityVect_.at(i));
  }
  for (long unsigned int i = permutedElmts.size(); i < (this->cityVect_.size()); i++){
      permutedElmts.push_back(this->cityVect_.at(i - 1));
  }
  newOrder->cityVect_ = permutedElmts;
  return *newOrder;
}

Cities::permutation_t random_permutation(unsigned len){
  // Create ordered vector
  Cities::permutation_t permuted_nums;
  for (unsigned int i = 0; i < len; i++) {
      permuted_nums.push_back(i);
  }
  // Time-based seed
  unsigned genSeed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng(genSeed);

  // Shuffle function
  std::shuffle(permuted_nums.begin(),permuted_nums.end(), rng);
  return permuted_nums;
}
