CXX = g++
CXXFLAGS= -std=c++11

#target file
hello_brothers : hello_brothers.o
	$(CXX) $(CXXFLAGS) -o hello_brothers hello_brothers.o

#object file
hello_brothers.o : hello_brothers.cpp
	$(CXX) $(CXXFLAGS) -c hello_brothers.cpp