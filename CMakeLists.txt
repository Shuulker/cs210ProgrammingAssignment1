cmake_minimum_required(VERSION 4.3)
project(CS210ProgrammingAssignment1)

set(CMAKE_CXX_STANDARD 20)

add_executable(CS210ProgrammingAssignment1 main.cpp
        Data.h
        Stack.h
        List.h
        ArrayList.h
        LinkedList.h
        Node.h
        Player.h
        Card.h)
