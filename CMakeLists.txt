cmake_minimum_required(VERSION 3.22)
project(trainengine)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(trainengine
        direction.h
        emptyelement.cpp
        emptyelement.h
        field.cpp
        field.h
        fieldelement.cpp
        fieldelement.h
        hundredandthirtylimit.cpp
        hundredandthirtylimit.h
        lightelement.cpp
        lightelement.h
        main.cpp
        railelement.cpp
        railelement.h
        sixtylimitelement.cpp
        sixtylimitelement.h
        switchelement.cpp
        switchelement.h
        thirtylimitelement.cpp
        thirtylimitelement.h
        trainelement.cpp
        trainelement.h)
