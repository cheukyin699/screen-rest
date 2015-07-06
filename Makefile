CXX := g++
CXXFLAGS := -c -Os
LD := g++
LDFLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -Os

EXE := screen_rest
OBJ := obj/Main.o
SRC := src/Main.cpp

.PHONY: all clean

all: $(EXE)

clean:
	rm -f $(OBJ) $(EXE)

$(EXE): obj/ $(OBJ)
	$(LD) -o $@ $(OBJ) $(LDFLAGS)

obj/:
	mkdir $@

obj/%.o: src/%.cpp src/%.h
	$(CXX) $(CXXFLAGS) -o $@ $<

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
