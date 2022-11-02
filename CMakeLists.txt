cmake_minimum_required(VERSION 3.0.0)
project(FEM_R VERSION 0.1.0)

include(CTest)
enable_testing()

set(PROJECT_SOURCES
	main.cpp
	./FEM/FEM.cpp)

set(PROJECT_HEADERS
	${PROJECT_SOURCE_DIR}/FEM)

include_directories("${PROJECT_HEADERS}")

add_executable(FEM_R "${PROJECT_SOURCES}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
