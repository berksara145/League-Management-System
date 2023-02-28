cmake_minimum_required(VERSION 3.23)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)


set(PROJECT_HEADERS
        LeagueManagementSystem.h
        Team.h
        Player.h
        )
set(PROJECT_SOURCES
        Team.cpp
        Player.cpp
        LeagueManagementSystem.cpp
        main.cpp main.h)

add_executable(untitled1 ${PROJECT_SOURCES} ${PROJECTS_HEADERS})
