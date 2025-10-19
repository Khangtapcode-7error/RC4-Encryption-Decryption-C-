CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall -Iinclude
SRC = src/RC4.cpp
OBJ = $(SRC:.cpp=.o)
LIB = librc4.a

all: $(LIB) encrypt decrypt

$(LIB): $(OBJ)
	ar rcs $@ $^

src/RC4.o: src/RC4.cpp include/RC4.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

encrypt: $(LIB)
	$(CXX) $(CXXFLAGS) encrypt/main.cpp -L. -lrc4 -o rc4_encrypt

decrypt: $(LIB)
	$(CXX) $(CXXFLAGS) decrypt/main.cpp -L. -lrc4 -o rc4_decrypt

clean:
	rm -f src/*.o $(LIB) rc4_encrypt rc4_decrypt

.PHONY: all clean encrypt decrypt
