SOURCES := $(wildcard *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))

executable: $(OBJECTS)
	g++ -o a.out $^ 

%.o: %.cpp
	gcc -o $@ -c $^ -I.

clean:
	rm *.o a.out


