add_library(src
    Baby_hedgehog.cpp
    Hedgehog.cpp
    Food.cpp
    Lock.cpp
)     

target_include_directories(src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")