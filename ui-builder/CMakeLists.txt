cmake_minimum_required (VERSION 3.10)
project (ui-builder)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
message(STATUS "----- GTK3_INCLUDE_DIRS: ${GTK3_INCLUDE_DIRS}")
message(STATUS "----- GKT3_LIBRARIES: ${GTK3_LIBRARIES}")
message(STATUS "----- GTK3_LINK_LIBRARIES: ${GTK3_LINK_LIBRARIES}")
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
list(APPEND FC_DEP_LIBS ${GTK3_LIBRARIES})

add_executable (ui-builder src/main.c)

#add_definitions (${GTK3_CFLAGS_OTHER})
message(STATUS "----- ${GTK3_CFLAGS_OTHER}")
# -pthread

target_link_libraries (ui-builder ${FC_DEP_LIBS})

message("CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

set(RES_FILE "builder.ui")
add_custom_command(OUTPUT  ${RES_FILE}
	COMMAND echo "Generating builder.ui file..."
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/src/${RES_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${RES_FILE}
	COMMENT  "This is a test"
)
add_custom_target(copyRes ALL DEPENDS ${RES_FILE})
