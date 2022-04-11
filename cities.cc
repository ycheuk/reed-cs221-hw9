// CSCI 221 - HW9 (cities.cc)
// Coded by Yik Yin Cheuk and Vaughn Zaayer

#include "cities.hh"
#include <vector>

// Returns the distance between two city coord pairs
double Cities::dist_between(cityA, cityB) const {
  // Cast as doubles so hypot returns doubles
  return std::hypot(static_cast<double>(cityA.first-cityB.first), static_cast<double>(cityA.second-cityB.second));
}

double Cities::total_path_distance(const permutation_t& ordering) const {
  auto cityPath = reorder(ordering).cityElements;
  // Distance between first and last points
  double distance = dist_between(cityPath.at(0), cityPath.at(cityPath.size()-1));
  // Loop the distance between cities
  for (unsigned int i = 1; i < cityPath.size(); i++)
  {
      distance += totalDistance(cityPath.at(i), cityPath.at(i - 1));
  }
  return distance;
}

Cities Cities::reorder(const permutation_t& ordering) const {
  std::vector<coor_t> newOrder
  for (int i : order){
    newOrder.push_back(cityVect_[i]);
  }
  return Cities(newOrder);
}

Cities::permutation_t random_permutation(unsigned len){
  std::vector<unsigned int> perm;
  unsigned i = 0;
  while (i < len){
    perm.push_back(i);
    i++;
  }
}
