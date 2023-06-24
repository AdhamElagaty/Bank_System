cmake_minimum_required(VERSION 3.25)
project(Bank_System)

set(CMAKE_CXX_STANDARD 23)

add_executable(Bank_System main.cpp Validation.cpp Validation.h Person.cpp Person.h Client.cpp Client.h Employee.cpp Employee.h Admin.cpp Admin.h Password.cpp Password.h Client_DataSourceInterface.h Employee_DataSourceInterface.h Admin_DataSourceInterface.h)
