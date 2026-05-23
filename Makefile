CXX = g++
CXXFLAGS = -g -O2 -Wall -Wextra -Wpedantic -Werror --std=c++20

graph_traversal: graphFML.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f graph_traversal
