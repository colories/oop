.SUFFIXES: .cpp .o

OBJECTS = json_object.o json_list.o json_dict.o data/Integer.o data/String.o
MAIN = main.o $(OBJECTS)

CXX = g++

DATA = data
TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)

clean :
	rm -rf $(MAIN) $(TARGET)

json_object.o : json_object.h
json_list.o : json_list.cpp json_list.h
json_dict.o : json_dict.cpp json_dict.h
data/Integer.o : data/Integer.cpp data/Integer.h
data/String.o : data/String.cpp data/String.h
