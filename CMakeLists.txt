cmake_minimum_required(VERSION 3.5.0)

project(adaptive-traffic-light-alg LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Boost REQUIRED COMPONENTS system)

set(PROJECT_SOURCES
        src/main.cpp
        src/traffic-light.h
        src/traffic-light.cpp
        src/event.h
        src/event.cpp
        src/crossroad-manager.h
        src/crossroad-manager.cpp
        src/stage.cpp
        src/stage.h
        src/circular-list.h
        src/circular-list.cpp
        src/utils.h
        src/constants.h
        src/constants.cpp)

add_executable(alg ${PROJECT_SOURCES})
target_include_directories(alg PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(alg ${Boost_LIBRARIES})
		
