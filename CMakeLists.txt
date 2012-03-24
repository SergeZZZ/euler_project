cmake_minimum_required(VERSION 2.8)

find_package(Boost REQUIRED COMPONENTS date_time)
include_directories(${Boost_INCLUDE_DIRS})
include_directories ("${PROJECT_SOURCE_DIR}/include")

add_executable(problem3 src/problem3.cpp)
target_link_libraries(problem3 ${Boost_DATE_TIME_LIBRARY})

