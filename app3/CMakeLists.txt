cmake_minimum_required (VERSION 3.10)
project (app3)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
message(STATUS "GTK3_INCLUDE_DIRS: ${GTK3_INCLUDE_DIRS}")
message(STATUS "GKT3_LIBRARIES: ${GTK3_LIBRARIES}")
message(STATUS "GTK3_LINK_LIBRARIES: ${GTK3_LINK_LIBRARIES}")
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
list(APPEND FC_DEP_LIBS ${GTK3_LIBRARIES})

message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
set(RES_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(RES_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(RES_FILE "resources.c")
set(UI_FILE "window.ui")
set(UI_CONFIG_FILE "exampleapp.gresource.xml")

add_executable (app3 src/main.c src/exampleapp.c src/exampleappwin.c ${RES_DIR}/${RES_FILE})

#add_definitions (${GTK3_CFLAGS_OTHER})
message(STATUS "${GTK3_CFLAGS_OTHER}")
# -pthread

target_link_libraries (app3 ${FC_DEP_LIBS})

pkg_get_variable(RES_COMPILER gio-2.0 glib_compile_resources)
message(STATUS "RES_COMPILER: ${RES_COMPILER}") 

add_custom_command(OUTPUT ${RES_DIR}/${UI_FILE} ${RES_DIR}/${RES_FILE}
	COMMAND echo "Copy ${UI_FILE} ..."
	COMMAND ${CMAKE_COMMAND} -E copy ${RES_SRC_DIR}/${UI_FILE} ${RES_DIR}/${UI_FILE}
	COMMAND echo "Generating ${RES_DIR}/${RES_FILE} ..."
	COMMAND ${RES_COMPILER}  ${RES_SRC_DIR}/${UI_CONFIG_FILE} --target=${RES_DIR}/${RES_FILE} --sourcedir=${RES_SRC_DIR} --generate-source
	DEPENDS ${RES_SRC_DIR}/${UI_FILE} ${RES_SRC_DIR}/${UI_CONFIG_FILE}
)

add_custom_target(generateRes ALL DEPENDS ${RES_DIR}/${RES_FILE})
