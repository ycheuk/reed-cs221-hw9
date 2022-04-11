// CSCI 221 - HW9 (cities.cc)
// Coded by Yik Yin Cheuk and Vaughn Zaayer

#include "cities.hh"
#include <vector>

// Returns the distance between two city coord pairs
double Cities::dist_between(cityA, cityB) const {
  // Cast as doubles so hypot returns doubles
  return std::hypot(static_cast<double>(cityA.first-cityB.first), static_cast<double>(cityA.second-cityB.second));
}

// Returns the total path distance from the given list of cities
double Cities::total_path_distance(const permutation_t& ordering) const {
  auto cityPath = reorder(ordering).cityElements;
  // The total distance to traverse the cities in the order given by the permutation
  double distance = dist_between(cityPath.at(0), cityPath.at(cityPath.size()-1));
  // Loop the distance between cities
  for (unsigned int i = 1; i < cityPath.size(); i++)
  {
      distance += totalDistance(cityPath.at(i), cityPath.at(i - 1));
  }
  return distance;
}

Cities Cities::reorder(const permutation_t& ordering) const {
  auto permuted_cities = new Cities();
  std::vector<coor_t> newOrder = {} // Empty vector
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
