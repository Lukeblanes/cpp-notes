SOURCES := $(wildcard *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))

executable: $(OBJECTS)
	g++ -pedantic -std=c++11 -Wall -g -o a.out $^

%.o: %.cpp
	g++ -pedantic -std=c++11 -Wall -g -o $@ -c $^ -I.

clean:
	rm *.o a.out


