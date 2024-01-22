cmake_minimum_required(VERSION 3.18)

#option(LIBUSB_STATIC "The Location of the libusb-1.0.a file" "/usr/lib/aarch64-linux-gnu/libusb-1.0.a")
set(LIBUSB_STATIC  /usr/lib/aarch64-linux-gnu/libusb-1.0.a CACHE PATH "The Location of the libusb-1.0.a/lib file")
set(LIBUSB_INCLUDE /usr/include/libusb-1.0/ CACHE PATH "The Location of the libusb-1.0 header files")
set(WPILIB_INCLUDE /usr/local/include/wpilib CACHE PATH "The Location of the wpilib headers")
set(WPILIB_SHARED /usr/local/lib/wpilib CACHE PATH "The Location of the wpilib so/dll files")
set(FREENECT_INCLUDE /usr/include/libfreenect CACHE PATH "The Location of the libfreenect header files")
set(FREENECT_SHARED /usr/lib CACHE PATH "The Location of the libfreenect a/lib/dll/so files")
project(allegro)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
include_directories(${PROJECT_NAME} PUBLIC ./include)
add_executable(${PROJECT_NAME} ./src/main.cpp ./src/Logger.cpp ./src/Kinect.cpp)
#wpilib
target_link_directories(${PROJECT_NAME} PUBLIC ${WPILIB_SHARED})
include_directories(${WPILIB_INCLUDE})
#libusb
include_directories(${LIBUSB_INCLUDE})
target_link_libraries(allegro ${LIBUSB_STATIC})

#freenect
target_link_directories(${PROJECT_NAME} PUBLIC ${FREENECT_SHARED})
include_directories(${FREENECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} freenect)

#NetworkTables
target_link_libraries(${PROJECT_NAME} ntcore)
