ARNOLD_PATH=/Users/miyehn/Documents/github/Arnold-5.4.0.0-darwin
LIBS=-lai
LINK_FLAGS=-shared -fPIC -L$(ARNOLD_PATH)/bin
GPP_COMPILE=g++ -Wall -Wextra -std=c++11 -O2 -I$(ARNOLD_PATH)/include

# linking
shaders/mynDiffuse.dylib: objs/diffuse_node.o objs/diffuse_bsdf.o
	g++ objs/diffuse_node.o objs/diffuse_bsdf.o -o $@ $(LINK_FLAGS) $(LIBS)

# files to compile
objs/diffuse_node.o: src/diffuse_node.cpp
	$(GPP_COMPILE) -c src/diffuse_node.cpp -o $@
objs/diffuse_bsdf.o: src/diffuse_bsdf.hpp src/diffuse_bsdf.cpp
	$(GPP_COMPILE) -c src/diffuse_bsdf.cpp -o $@

# utilities
clean:
	rm -rf objs/*
	rm -rf shaders/*
	rm -rf templates/*.pyc
.PHONY: clean
