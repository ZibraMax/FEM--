cmake_minimum_required(VERSION 3.0.0)
project(FEM_R VERSION 0.1.0)

include(CTest)
enable_testing()

include(FetchContent)

FetchContent_Declare(eigen
	GIT_REPOSITORY https://gitlab.com/libeigen/eigen/
	GIT_TAG 3.4.0)

FetchContent_GetProperties(eigen)

if(NOT eigen_POPULATED)
	FetchContent_Populate(eigen)
	add_subdirectory(${eigen_SOURCE_DIR} ${eigen_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_Declare(json
	GIT_REPOSITORY https://github.com/nlohmann/json.git
	GIT_TAG v3.11.2)

FetchContent_GetProperties(json)

if(NOT json_POPULATED)
	FetchContent_Populate(json)
	add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

set(PROJECT_SOURCES
	main.cpp
	./FEM/FEM.cpp
	./FEM/Geometry/Geometry.cpp
	./FEM/Elements/Element.cpp)

set(PROJECT_HEADERS
	${PROJECT_SOURCE_DIR}/FEM
	${PROJECT_SOURCE_DIR}/FEM/Geometry
	${PROJECT_SOURCE_DIR}/FEM/Elements)

include_directories("${PROJECT_HEADERS}")

add_executable(FEM_R "${PROJECT_SOURCES}")

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
target_link_libraries(FEM_R PRIVATE Eigen3::Eigen)
target_link_libraries(FEM_R PRIVATE nlohmann_json::nlohmann_json)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
