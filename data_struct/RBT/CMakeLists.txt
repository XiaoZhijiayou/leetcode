message(STATUS "Configuring RBT library")

if(MSVC)
    add_compile_options("/utf-8")
endif()

# 定义项目名称
project(RBT)


add_library(RBT STATIC RBTree.cpp RBT.hpp)

# 打印当前源目录（调试信息）
message(STATUS "Current source directory: ${CMAKE_CURRENT_SOURCE_DIR}")


target_include_directories(BST PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})