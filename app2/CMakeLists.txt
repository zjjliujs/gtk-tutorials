cmake_minimum_required (VERSION 3.10)
project (app2)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
message(STATUS "----- GTK3_INCLUDE_DIRS: ${GTK3_INCLUDE_DIRS}")
message(STATUS "----- GKT3_LIBRARIES: ${GTK3_LIBRARIES}")
message(STATUS "----- GTK3_LINK_LIBRARIES: ${GTK3_LINK_LIBRARIES}")
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
list(APPEND FC_DEP_LIBS ${GTK3_LIBRARIES})

set(RES_FILE "resources.c")
add_executable (app2 src/main.c src/exampleapp.c src/exampleappwin.c src/${RES_FILE})

#add_definitions (${GTK3_CFLAGS_OTHER})
message(STATUS "----- ${GTK3_CFLAGS_OTHER}")
# -pthread

target_link_libraries (app2 ${FC_DEP_LIBS})

set(RES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_custom_command(OUTPUT  ${RES_DIR}/${RES_FILE}
	COMMAND echo "Generating ${RES_DIR}/${RES_FILE} file..."
	COMMAND glib-compile-resources ${RES_DIR}/exampleapp.gresource.xml --target=${RES_DIR}/${RES_FILE} --sourcedir=${RES_DIR} --generate-source
)
add_custom_target(generateRes ALL DEPENDS ${RES_DIR}/${RES_FILE})
