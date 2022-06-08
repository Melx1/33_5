cmake_minimum_required(VERSION 3.21)
project(33_5)

set(CMAKE_CXX_STANDARD 20)

set(Boost_INCLUDE_DIR "C:\\boost_1_79_0")
set(Boost_LIBRARY_DIR "C:\\boost_1_79_0\\stage\\lib")
find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(33_5_1 33.5.1.cpp)
add_executable(33_5_2 33.5.2.cpp)
target_link_libraries(33_5_1 ${Boost_LIBRARIES})

if (MINGW)
    target_link_libraries(33_5_1 ws2_32)
endif()