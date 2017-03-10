cmake_minimum_required(VERSION 2.8)

project(hana_trails)

# Set clang
SET (CMAKE_C_COMPILER             "/usr/bin/clang-3.9")
SET (CMAKE_C_FLAGS                "-Wall -std=c99")
SET (CMAKE_C_FLAGS_DEBUG          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_CXX_COMPILER         "/usr/bin/clang++-3.9")
SET (CMAKE_CXX_FLAGS            "${CMAKE_CXX_FLAGS} -Wall")
SET (CMAKE_CXX_FLAGS            "${CMAKE_CXX_FLAGS} -std=c++14")
SET (CMAKE_CXX_FLAGS            "${CMAKE_CXX_FLAGS} -stdlib=libc++")
SET (CMAKE_CXX_FLAGS            "${CMAKE_CXX_FLAGS} -I${CMAKE_SOURCE_DIR}/hana/include")
SET (CMAKE_CXX_FLAGS_DEBUG      "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE    "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

macro(create_exe NAME)
   get_filename_component (TARGET ${NAME} NAME_WE)
   add_executable(${TARGET} ${NAME})
endmacro()

file(GLOB file_list "${CMAKE_SOURCE_DIR}/src/*.cc")
foreach(file ${file_list})
   create_exe(${file})
endforeach()

#Examples from http://www.boost.org/doc/libs/1_63_0/libs/hana/doc/html/index.html
