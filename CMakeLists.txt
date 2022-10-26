cmake_minimum_required(VERSION 3.21)
project(ProjectAED_G24)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectAED_G24 main.cpp Schedule.cpp Schedule.h Student.cpp Student.h UniClass.cpp UniClass.h Menu.cpp Menu.h Application.cpp Application.h SaveData.cpp SaveData.h bst.h)
