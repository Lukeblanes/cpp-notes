SOURCES := $(wildcard *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))

executable: $(OBJECTS)
	g++ -Wall -g -o a.out $^

%.o: %.cpp
	g++ -g -o $@ -c $^ -I.

clean:
	rm *.o a.out


