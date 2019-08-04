LIBS=-lai
LINK_FLAGS=-shared -fPIC -L$(ARNOLD_PATH)/bin

GPP_COMPILE=g++ -Wall -Wextra -std=c++11 -O2 -I$(ARNOLD_PATH)/include

# linking
all: simple.o
	g++ simple.o -o ../shaders/simple.dylib $(LINK_FLAGS) $(LIBS)

# files to compile
simple.o: simple.cpp
	$(GPP_COMPILE) -c simple.cpp -o simple.o 

# utilities
clean:
	rm -rf *.o
.PHONY: clean
