cmake_minimum_required(VERSION 3.3)
project(CWork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp basis/SingleLinkedList.cpp basis/SingleLinkedList.h basis/DoubleLinkedList.cpp basis/DoubleLinkedList.h Sentence.cpp Sentence.h Text.cpp Text.h Vector.cpp Vector.h basis/SingleLinkedList.cpp basis/SingleLinkedList.h basis/DoubleLinkedList.cpp basis/DoubleLinkedList.h Util.h Util.cpp)
add_executable(CWork ${SOURCE_FILES})