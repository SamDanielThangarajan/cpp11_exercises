cmake_minimum_required(VERSION 2.8)

project(cpp_play_programs)

# Set clang
#SET (CMAKE_C_COMPILER             "/usr/bin/clang-3.9")
SET (CMAKE_C_FLAGS                "-Wall -std=c++11")
#SET (CMAKE_C_FLAGS_DEBUG          "-g")
#SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
#SET (CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
#SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")
#
#SET (CMAKE_CXX_COMPILER         "/usr/bin/clang++-3.9")
SET (CMAKE_CXX_FLAGS            "${CMAKE_CXX_FLAGS} -Wall")
SET (CMAKE_CXX_FLAGS            "${CMAKE_CXX_FLAGS} -std=c++14")
#SET (CMAKE_CXX_FLAGS            "${CMAKE_CXX_FLAGS} -stdlib=libc++")
#SET (CMAKE_CXX_FLAGS            "${CMAKE_CXX_FLAGS} -I${CMAKE_SOURCE_DIR}/hana/include")
#SET (CMAKE_CXX_FLAGS_DEBUG      "-g")
#SET (CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
#SET (CMAKE_CXX_FLAGS_RELEASE    "-O4 -DNDEBUG")
#SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

macro(subdirlist result curdir)
   file(GLOB children RELATIVE ${curdir} ${curdir}/*)
   set(dirlist "")
   foreach(child ${children})
      if(IS_DIRECTORY ${curdir}/${child})
         list(APPEND dirlist ${child})
      endif()
   endforeach()
   set(${result} ${dirlist})
endmacro()


macro(create_exe NAME)
   get_filename_component (TARGET ${NAME} NAME_WE)
   add_executable(${TARGET} ${NAME})
endmacro()

macro(create_exe_for_dir NAME)
   file(GLOB file_list "${CMAKE_SOURCE_DIR}/${NAME}/*.cc")
   set(${NAME}_sources "")
   foreach(file ${file_list})
      set(${NAME}_sources ${${NAME}_sources} ${file})
   endforeach()
   message(STATUS ${NAME})
   message(STATUS ${${NAME}_sources})
   message(STATUS "----------------------")
   add_executable(${NAME} ${${NAME}_sources})
endmacro()


# Create executables on the parent level */programs
file(GLOB file_list "${CMAKE_SOURCE_DIR}/*.cc")
foreach(file ${file_list})
   create_exe(${file})
endforeach()


# Create executables for the subdirectories
subdirlist(SUBDIRS ${CMAKE_SOURCE_DIR})
foreach(subdir ${SUBDIRS})
   create_exe_for_dir(${subdir})
ENDFOREACH()




#Examples from http://www.boost.org/doc/libs/1_63_0/libs/hana/doc/html/index.html
