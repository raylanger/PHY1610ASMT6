# Makefile for gameof1d
#
# Part of assignment 3 for 2024 PHY1610
#
CXX=g++
CXXFLAGS=-O3 -march=native

all: ASMT6

ASMT6: main.o eps.o vectors.o solver.o output.o
	$(CXX) $(LDFLAGS) -o $@ $^ -lopenblas -llapacke -lnetcdf -lnetcdf_c++4

main.o: main.cpp solver.h vectors.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

vectors.o: vectors.cpp vectors.h eps.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

solver.o: solver.cpp solver.h vectors.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

output.o: output.cpp output.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

eps.o: eps.cpp eps.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

.PHONY: all clean

clean:
	$(RM) ASMT6 main.o vectors.o solver.o eps.o output.o