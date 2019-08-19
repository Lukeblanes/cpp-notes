# OLD VERSION
# OBJECTS := hitable_list.o main.o sphere.o vec3.o


# 13 - We can use wildcard to obtain all CPP files
# we can't do OBJ := *.o
# we can use a makefile function 
SOURCES := $(wildcard *.cpp)

# Way to use sources as a way to get the .o
# Notice that there are no spaces, it's literal substitution
# 14 - with subst we change all .cpp in SOURCES to .o 
OBJECTS := $(subst .cpp,.o,$(SOURCES))

executable: $(OBJECTS)
	g++ -o $@ $^

%.o: %.cpp
	gcc -o $@ -c $^ -I.

clean:
	rm *.o a.out

# objective that are called down here are usually without dependencies
# To see what SOURCES and OBJECTS has
# 15 - We can create objectives for debugging purposes
info:
	$(info $(SOURCES))
	$(info $(OBJECTS))



