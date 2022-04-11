CXX = g++
FLAGS = -Wall -Wextra -pedantic -Werror -std=c++17 -g

cities_test: cities.o 
	$(CXX) $(CXXFLAGS) -o tsv cities.o 

cities.o: cities.cc cities.hh
	$(CXX) $(CXXFLAGS) -c cities.cc

.PHONY: clean
clean:
	rm -f *.o 
