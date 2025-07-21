cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加源文件
file(GLOB SOURCES "main.cpp")

add_executable(main ${SOURCES})

# 如果有需要链接的库，可以在这里添加
# target_link_libraries(leetcode PRIVATE some_library)

# 增加头文件搜索路径 /usr/include/x86_64-linux-gnu/c++/11/bits/
include_directories(/usr/include/x86_64-linux-gnu/c++/11/bits)