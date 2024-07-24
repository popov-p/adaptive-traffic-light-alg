cmake_minimum_required(VERSION 3.5.0)

project(adaptive-traffic-light-alg LANGUAGES CXX)

set(PROJECT_SOURCES
	main.cpp
	traffic-light.h
        traffic-light.cpp
        phase.h
        phase.cpp
        event.h
        event.cpp
        crossroad-manager.h
        crossroad-manager.cpp
        stage.cpp
        stage.h
        circular-list.h
        circular-list.cpp)

add_executable(alg
		${PROJECT_SOURCES})
		
