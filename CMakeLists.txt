cmake_minimum_required(VERSION 3.1)
project(lua-embedding-example)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
add_executable(${PROJECT_NAME} main.cpp)

find_package(Lua REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${LUA_LIBRARIES}
)
