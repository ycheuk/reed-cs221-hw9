CXX = g++
FLAGS = -Wall -Wextra -pedantic -Werror -std=c++17 -g 

cities_test: cities.o tsp.o
	$(CXX) $(CXXFLAGS) -o tsp tsp.o cities.o 

cities.o: cities.cc cities.hh
	$(CXX) $(CXXFLAGS) -c cities.cc cities.hh

tsp.o: tsp.cc
	$(CXX) $(CXXFLAGS) -c tsp.cc

.PHONY: clean
clean:
	rm -f *.o 
