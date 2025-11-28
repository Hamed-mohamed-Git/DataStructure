cmake_minimum_required(VERSION 4.0)
project(linkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(linkedList main.cpp
        List/List.cpp
        List/List.h
        CursorList/CursorList.h
        Node/Node.h
        utils/InputHelper.h
        cursorList/CursorList.cpp)
