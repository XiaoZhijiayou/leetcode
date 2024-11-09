message(STATUS "Configuring AVL library")
if(MSVC)
    add_compile_options("/utf-8")
endif()

# 定义项目名称
project(AVL)

# 创建静态库 AVL，包含 AVL.cpp 和 AVL.h
add_library(AVL STATIC AVL.cpp AVL.h)

# 打印当前源目录（调试信息）
message(STATUS "Current source directory: ${CMAKE_CURRENT_SOURCE_DIR}")

# 设置包含目录，使得其他目标可以找到 AVL.h
target_include_directories(AVL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
