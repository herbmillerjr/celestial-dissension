PREFIX=x86_64-w64-mingw32

SDL_INCLUDE=-I/usr/$(PREFIX)/usr/include -Dmain=SDL_main
SDL_LIB=-L/usr/$(PREFIX)/usr/lib -lmingw32 -lSDL2main -lSDL2 -mwindows

CXX=$(PREFIX)-g++
CXXFLAGS=-static-libgcc -static-libstdc++ $(SDL_INCLUDE)
LDFLAGS=$(SDL_LIB)

EXE=main.exe

all: $(EXE)

	
$(EXE): main.o
	$(CXX) $< $(LDFLAGS) -o $@
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@
	
clean:
	rm *.o && rm $(EXE)
	