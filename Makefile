CXX = g++
FLAGS = -Wall -Wextra -pedantic -Werror -std=c++17 -g

cities_test: cities.o tsv.o
	$(CXX) $(CXXFLAGS) -o tsv tsv.o cities.o 

cities.o: cities.cc cities.hh
	$(CXX) $(CXXFLAGS) -c cities.cc cities.hh

tsv.o: tsv.cc
	$(CXX) $(CXXFLAGS) -c tsv.cc

.PHONY: clean
clean:
	rm -f *.o 
