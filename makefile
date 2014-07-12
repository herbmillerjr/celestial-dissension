PREFIX=x86_64-w64-mingw32

SDL_INCLUDE=-I/usr/$(PREFIX)/usr/include/SDL2 /usr/$(PREFIX)/usr/local/include/SDL2 -Dmain=SDL_main
SDL_LIB=/usr/$(PREFIX)/usr/lib -lmingw32 -lSDL2main -lSDL2 -mwindows

CXX=$(PREFIX)-g++
CXXFLAGS=-static-libgcc -static-libstdc++ -std=c++11
LDFLAGS=-L/usr/$(PREFIX)/usr/local/lib:$(SDL_LIB)

EXE=main.exe

all: $(EXE)

	
$(EXE): Logger.o CD.o main.o MenuItem.o Background.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@
Logger.o: Logger.cpp
	$(CXX) -c $(CXXFLAGS) $(SDL_INCLUDE) $< -o $@
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(SDL_INCLUDE) $< -o $@
CD.o: CD.cpp
	$(CXX) -c $(CXXFLAGS) $(SDL_INCLUDE) $< -o $@
MenuItem.o: MenuItem.cpp
	$(CXX) -c $(CXXFLAGS) $(SDL_INCLUDE) $< -o $@
Background.o: Background.cpp
	$(CXX) -c $(CXXFLAGS) $(SDL_INCLUDE) $< -o $@
	
clean:
	rm *.o && rm $(EXE)
	
