cmake_minimum_required(VERSION 2.6)
project(celestial_dissension)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

#file(COPY assets DESTINATION .)

add_executable(cd
	Abstracts.hpp
	CD.hpp
	CD.cpp
	Context.hpp
	Context.cpp
	ContextSDL.cpp
	Logger.hpp
	Logger.cpp
	Menu.hpp
	Menu.cpp
	main.cpp
)

target_link_libraries(cd ${SDL2_LIBRARIES})

install(TARGETS cd RUNTIME DESTINATION bin)

