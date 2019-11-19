.SUFFIXES: .cpp .o

OBJECTS = Integer.o Float.o Complex.o

CXX = g++
COMPILE = test.o $(OBJECTS)
TEST = test

$(TEST) : $(COMPILE)
	$(CXX) -o $(TEST) $(COMPILE)

clean :
	rm -rf $(TEST) $(COMPILE)


test.o : test.cpp Integer.h Float.h Complex.h
Integer.o : Integer.cpp Integer.h Float.h Complex.h
Float.o : Float.cpp Integer.h Float.h Complex.h
Complex.o : Complex.cpp Integer.h Float.h Complex.h
