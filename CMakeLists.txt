cmake_minimum_required (VERSION 3.0)

project (powerfoo)

include_directories( dependencies/include)


add_library( powerfoo
src/powerfoo.c
)

INSTALL( TARGETS powerfoo DESTINATION "lib")
INSTALL( FILES src/powerfoo.h DESTINATION "include/powerfoo")


