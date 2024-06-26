cmake_minimum_required(VERSION 3.9)

project(SRCNN_cpp LANGUAGES CXX)

set(i_want_openmp OFF)
set(i_want_avx ON)
set(EXECUTABLE_OUTPUT_PATH "..")
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -ftree-vectorize -march=native -mavx -mfma")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -march=native -mtune=native -mavx2")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DIM2COL=1") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBLOCK_SIZE_X=512")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBLOCK_SIZE_Y=512")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBLOCK_SIZE_Z=512")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSEFLOAT=1")
if(i_want_avx)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DISX86=1")
endif()

# include OpenCV
find_package(OpenCV REQUIRED)

include_directories(src)
add_executable(SRCNN_cpp 
    main.cpp 
    src/srcnn.cpp
    src/gaussian.cpp)

target_link_libraries(SRCNN_cpp ${OpenCV_LIBS})
