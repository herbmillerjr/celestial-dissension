PREFIX=x86_64-w64-mingw32

SDL_INCLUDE=-I/usr/$(PREFIX)/usr/include/SDL2 -Dmain=SDL_main
SDL_LIB=-L/usr/$(PREFIX)/usr/lib -lmingw32 -lSDL2main -lSDL2 -mwindows

CXX=$(PREFIX)-g++
CXXFLAGS=-static-libgcc -static-libstdc++
LDFLAGS=$(SDL_LIB)

EXE=main.exe

all: $(EXE)

	
$(EXE): main.o CD.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(SDL_INCLUDE) $< -o $@
CD.o: CD.cpp
	$(CXX) -c $(CXXFLAGS) $(SDL_INCLUDE) $< -o $@
	
clean:
	rm *.o && rm $(EXE)
	
