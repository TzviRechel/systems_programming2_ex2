# 316289495
# tzvirechel@gmail.com

CXX=clang++
CXXFLAGS=-std=c++11 -Werror
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

run: main
	./$^

main: Graph.o Algorithms.o main.o
	$(CXX) $(CXXFLAGS) $^ -o main

test: Graph.o Algorithms.o Test.o
	$(CXX) $(CXXFLAGS) $^ -o test	

Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) --compile Graph.cpp -o Graph.o

Algorithms.o: Algorithms.cpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) --compile Algorithms.cpp -o Algorithms.o
	
main.o: main.cpp Algorithms.hpp Graph.hpp
	$(CXX) $(CXXFLAGS) --compile main.cpp -o main.o

Test.o: Test.cpp
	$(CXX) $(CXXFLAGS) --compile Test.cpp -o Test.o

valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f *.o main test

	