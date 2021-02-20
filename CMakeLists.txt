cmake_minimum_required(VERSION 3.0.0)
project(SpaceInvader VERSION 0.1.0)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(CTest)
enable_testing()

# add_executable(SpaceInvader src/main.cpp src/AlienInvasion.cpp src/Renderer.cpp src/Controller.cpp src/Settings.cpp src/Ship.cpp src/Bullet.cpp)

file(GLOB_RECURSE alien_SOURCES "src/*.cpp")
add_executable (SpaceInvader ${alien_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


file(COPY src/images DESTINATION .)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image REQUIRED)
include_directories($(SDL2_INCLUDE_DIRS) ${SDL2_IMAGE_INCLUDE_DIRS} src)
target_link_libraries(SpaceInvader PRIVATE SDL2::SDL2main SDL2::SDL2-static)
target_link_libraries(SpaceInvader PRIVATE SDL2::SDL2_image)