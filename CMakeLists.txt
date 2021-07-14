cmake_minimum_required(VERSION 3.20)
project(celestial_dissension)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (UNIX)
	INCLUDE(FindPkgConfig)
	PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
endif (UNIX)

if (WIN32)
	find_package(SDL2 REQUIRED)
endif (WIN32)

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

target_include_directories(cd SYSTEM PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(cd ${SDL2_LIBRARIES} SDL2::SDL2 SDL2::SDL2main)

install(TARGETS cd RUNTIME DESTINATION bin)
