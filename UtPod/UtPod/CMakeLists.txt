cmake_minimum_required(VERSION 3.13)
project(UtPod)

set(CMAKE_CXX_STANDARD 11)

add_executable(UtPod UtPodDriver.cpp UtPodDriver.h UtPod.cpp UtPod.h Song.cpp Song.h)