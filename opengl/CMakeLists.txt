cmake_minimum_required (VERSION 3.10)
project (opengl)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
message(STATUS "GTK3_INCLUDE_DIRS: ${GTK3_INCLUDE_DIRS}")
message(STATUS "GTK3_LIBRARIES: ${GTK3_LIBRARIES}")
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
list(APPEND FC_DEP_LIBS ${GTK3_LIBRARIES})
message(STATUS "FC_DEP_LIBS: ${FC_DEP_LIBS}")

#########################################################
# FIND GLEW
#########################################################
pkg_check_modules(GLEW REQUIRED glew)
message(STATUS "GLEW_INCLUDE_DIRS: ${GLEW_INCLUDE_DIRS}")
message(STATUS "GLEW_LIBRARY_DIRS: ${GLEW_LIBRARY_DIRS}")
message(STATUS "GLEW_LIBRARIES: ${GLEW_LIBRARIES}")
message(STATUS "GLEW_LDFLAGS : ${GLEW_LDFLAGS}")
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
list(APPEND FC_DEP_LIBS ${GLEW_LIBRARIES})
message(STATUS "FC_DEP_LIBS: ${FC_DEP_LIBS}")

add_executable (opengl src/main.c)
target_link_libraries (opengl ${FC_DEP_LIBS})
