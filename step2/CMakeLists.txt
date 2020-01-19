cmake_minimum_required (VERSION 3.10)
project (step2)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
message(STATUS "----- GTK3_INCLUDE_DIRS: ${GTK3_INCLUDE_DIRS}")
message(STATUS "----- GKT3_LIBRARIES: ${GTK3_LIBRARIES}")
message(STATUS "----- GTK3_LINK_LIBRARIES: ${GTK3_LINK_LIBRARIES}")
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
list(APPEND FC_DEP_LIBS ${GTK3_LIBRARIES})

add_executable (step2 src/main.c)

message(${CMAKE_CURRENT_SOURCE_DIR}/drawable/demo.png)
message(${CMAKE_CURRENT_BINARY_DIR}/drawable/demo.png)

set(RES_FILE "drawable/demo.png")

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${RES_FILE}
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${RES_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${RES_FILE}
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${RES_FILE}
)

add_custom_target(run ALL
	DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${RES_FILE})

#add_definitions (${GTK3_CFLAGS_OTHER})
message(STATUS "----- ${GTK3_CFLAGS_OTHER}")
# -pthread

target_link_libraries (step2 ${FC_DEP_LIBS})
