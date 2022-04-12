// CSCI 221 - HW9 (cities.cc)
// Coded by Yik Yin Cheuk and Vaughn Zaayer

#include "cities.hh"
#include <vector>

std::istream& operator >> (std::istream& in, Cities& cities_ls){
    int x;
    while(input >> x) { // While stream is not done
        Cities::coord_t pair;
        pair.first = x;
        input >> pair.second;
        cities_ls.city_elements_.push_back(pair);
    }
    return input;
}

std::ostream& operator << (std::ostream& os, Cities& cities_ls){
    for(Cities::coord_t elm: cities_ls.city_elements_){
        output << elm.first << "\t" << elm.second << "\n";
    }
    return output;
}

// Used to calculate the distance between two city's coordinates
double Cities::dist_between(coord_t cityA, coord_t cityB) const {
  return std::hypot(static_cast<double>(cityA.first-cityB.first), static_cast<double>(cityA.second-cityB.second));
}

// Returns the total path distance from the given list of cities
double Cities::total_path_distance(const permutation_t& ordering) const {
  auto cityPath = reorder(ordering).cityElements;
  // The total distance to traverse the cities in the order given by the permutation
  double distance = dist_between(cityPath.at(0), cityPath.at(cityPath.size()-1));
  // Loop the distance between cities
  for (unsigned int i = 1; i < cityPath.size(); i++){
      distance += totalDistance(cityPath.at(i), cityPath.at(i - 1));
  }
  return distance;
}

Cities Cities::reorder(const permutation_t& ordering) const {
  std::vector<coord_t> newOrder;
  for (int i : ordering){
    newOrder.push_back(cityVect_[i]);
  }
  return Cities(newOrder);
}

Cities::permutation_t
Cities::random_permutation(unsigned len) const{
  // Create the ordered vector
  std::vector<unsigned int> permuted_nums;
  for (unsigned int i = 0; i < len; i++)
  {
      permuted_nums.push_back(i);
  }
}

// Creates vector of coordinates
Cities::Cities(std::vector<coord_t> cities)
  :cityVect_(cities)
{}
