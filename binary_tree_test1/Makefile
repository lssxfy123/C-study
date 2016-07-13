CXX=g++
CFLAGS = -fno-inline -Wall -fPIC

SOURCE=$(wildcard *.cpp)
OBJECT=$(SOURCE:%.cpp=%.o)
TARGET = test

.PHONY:all clean

all:$(OBJECT) $(TARGET)
$(OBJECT):%.o:%.cpp
	$(CXX) $(CFLAGS) -c $<
$(TARGET):
	$(CXX) $(CFLAGS) -o $@ $(OBJECT)

clean:
	rm -rf $(OBJECT)
	rm -rf $(TARGET)

