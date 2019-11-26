.SUFFIXES: .cpp .o

CXX = g++
COMPILE = fibonacci.o
MAIN = fibonacci

$(MAIN) : $(COMPILE)
	$(CXX) -o $(MAIN) $(COMPILE)

clean : 
	rm -rf $(MAIN) $(COMPILE)

fibonacci.o : fibonacci.cpp
