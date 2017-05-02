cmake_minimum_required (VERSION 3.0)

project (powerfoo)


if( NOT DEPENDENCIES_DIR)
   execute_process( COMMAND mulle-bootstrap paths -m dependencies
                 WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
                 OUTPUT_VARIABLE DEPENDENCIES_DIR
                 OUTPUT_STRIP_TRAILING_WHITESPACE)
   message( STATUS "DEPENDENCIES_DIR is ${DEPENDENCIES_DIR} according to mulle-bootstrap")
   set( DEPENDENCIES_DIR "dependencies")
endif()


set( CMAKE_LIBRARY_PATH "${DEPENDENCIES_DIR}/lib")
include_directories( BEFORE SYSTEM
"${DEPENDENCIES_DIR}/include"
)

find_library( FOO_LIBRARY NAMES "foo")
message( STATUS "FOO_LIBRARY is ${FOO_LIBRARY}")

add_library( powerfoo
src/powerfoo.c
)

target_link_libraries( powerfoo
${FOO_LIBRARY}
)


INSTALL( TARGETS powerfoo DESTINATION "lib")
INSTALL( FILES src/powerfoo.h DESTINATION "include/powerfoo")


