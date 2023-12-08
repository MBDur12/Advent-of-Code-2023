CXX := g++
CXXFLAGS := -std=c++11 -Wall

SRC ?= main.cpp
UTILS_SRC := utils.cpp

# Output executable name
TARGET := advent

OBJ := $(SRC:.cpp=.o)
UTILS_OBJ := $(UTILS_SRC:.cpp=.o)

$(TARGET): $(OBJ) $(UTILS_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Phony target to clean up the generated files
.PHONY: clean
clean:
	rm -f $(OBJ) $(UTILS_OBJ) $(TARGET)
