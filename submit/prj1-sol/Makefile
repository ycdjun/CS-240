CXX = g++
CXXFLAGS = -g -Wall -std=c++17

TARGET = wordcounts

wordcounts: wordcounts.cc
	$(CXX) wordcounts.cc -o wordcounts

.phony: clean
clean:
	rm -f *~ *.o $(TARGET)

