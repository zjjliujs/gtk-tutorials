cmake_minimum_required (VERSION 3.10)
project (tutorial-gtk)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    message(STATUS "----- GTK3_INCLUDE_DIRS: ${GTK3_INCLUDE_DIRS}")
    message(STATUS "----- GKT3_LIBRARIES: ${GTK3_LIBRARIES}")
    message(STATUS "----- GTK3_LINK_LIBRARIES: ${GTK3_LINK_LIBRARIES}")
    include_directories(${GTK3_INCLUDE_DIRS})
    link_directories(${GTK3_LIBRARY_DIRS})
    list(APPEND FC_DEP_LIBS ${GTK3_LIBRARIES})
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    #export PKG_CONFIG_PATH="$(brew --prefix libffi)/lib/pkgconfig/"
    set(ENV{PKG_CONFIG_PATH} /usr/local/opt/libffi/lib/pkgconfig)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    message(STATUS "----- GKT3_LIBRARIES: ${GTK3_LIBRARIES}")
    message(STATUS "----- GTK3_LINK_LIBRARIES: ${GTK3_LINK_LIBRARIES}")
    include_directories(${GTK3_INCLUDE_DIRS})
    list(APPEND FC_DEP_LIBS ${GTK3_LINK_LIBRARIES})
endif()

add_executable (tutorial-gtk src/main.c)

message(${CMAKE_CURRENT_SOURCE_DIR}/drawable/demo.png)
message(${CMAKE_CURRENT_BINARY_DIR}/drawable/demo.png)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/drawable/demo.png
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawable/demo.png ${CMAKE_CURRENT_BINARY_DIR}/drawable/demo.png
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/drawable/demo.png)

add_custom_target(run ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/drawable/demo.png)

#file(COPY
#    ${CMAKE_CURRENT_SOURCE_DIR}/drawable/demo.png
#    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/drawable/)

#add_definitions (${GTK3_CFLAGS_OTHER})
message(STATUS "----- ${GTK3_CFLAGS_OTHER}")
# -pthread

target_link_libraries (tutorial-gtk ${FC_DEP_LIBS})
