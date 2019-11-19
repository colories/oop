.SUFFIXES: .cpp .o

OBJECTS = vehicle.o car.o bike.o

CXX = g++
COMPILE = main.o $(OBJECTS)
MAIN = main

$(MAIN) : $(COMPILE)
	$(CXX) -o $(MAIN) $(COMPILE)

clean:
	rm -rf $(MAIN) $(COMPILE)

main.o : main.cpp
vehicle.o : vehicle.cpp vehicle.h
car.o : car.cpp car.h
bike.o : bike.cpp bike.h

