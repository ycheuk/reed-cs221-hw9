// CSCI 221 - HW9 (cities.hh)
// Coded by Yik Yin Cheuk and Vaughn Zaayer

/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <random>


// Representation of an ordering of cities
class Cities {
  public:
    // A pair of integral coordinates for each city
    using coord_t = std::pair<int, int>;

    // An ordering of cities. Each value represents a unique index
    // into the current city ordering in some container.
    using permutation_t = std::vector<unsigned int>;

    // Given a permutation, return a new Cities object where the order of the
    // cities reflects the original order of this class after reordering with
    // the given ordering. So for example, the ordering { 1, 0 } simply swaps
    // the first two elements (coordinates) in the new Cities object.
    Cities reorder(const permutation_t& ordering) const;

    // When provided with two city elements, this function will return the distance
    // between the two elements and return it as a double type.
    double dist_between(const coord_t& cityA, const coord_t& cityB) const;

    // For a given permutation of the cities in this object,
    // compute how long (distance) it would take to traverse all the cities in the
    // order of the permutation, and then returning to the first city.
    // The distance between any two cities is computed as the Euclidean
    // distance on a plane between their coordinates.
    double total_path_distance(const permutation_t& ordering) const;


    // Public function to append the list of cities present as a private variable
    void append_city_list(const coord_t& city);

    // Public function to get the list of cities from private cityVect_
    const std::vector<coord_t>& get_city_list() const;


    // Takes the total number of cities w/in the object, and returns a random ordering
    // of 0-total # of cities.
    Cities::permutation_t random_permutation(unsigned len);

  private:
    // Private vector to keep track of all cities
    std::vector<coord_t> cityVect_;
};

// Promises to override << and >> operators for in/out streams
std::istream& operator>>(std::istream& input, Cities& cities);
std::ostream& operator<<(std::ostream& output, Cities& cities);


