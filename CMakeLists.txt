cmake_minimum_required(VERSION 3.2)
#3.16

project(app VERSION 0.0.1)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package (Threads)
find_package(PQXX)

include_directories (${PostgreSQL_INCLUDE_DIRS})

add_executable(app 
    src/main.cpp 
    src/address.cpp
    src/db/postgres.cpp
    src/scaner.cpp
)
#target_link_libraries (${OUT_TARGET} ${SQLite3_LIBRARIES})
target_link_libraries(app
         Threads::Threads
         pqxx
)