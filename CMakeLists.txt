cmake_minimum_required (VERSION 3.8)
project (software-renderer VERSION 0.1)

set(SOURCES
	${PROJECT_SOURCE_DIR}/src/main.cpp
)

set(INCLUDE_DIRS
	PUBLIC ${PROJECT_SOURCE_DIR}/src/
)

include(${PROJECT_SOURCE_DIR}/cmake/tga.cmake)

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

add_executable (${PROJECT_NAME} 
	${SOURCES} 
	${TGA_SOURCES} 
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
	add_definitions(-DDEBUG)
else()
	set_target_properties(${PROJECT_NAME} PROPERTIES 
    LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")
endif()

target_include_directories(${PROJECT_NAME}
	PUBLIC ${INCLUDE_DIRS}
	PUBLIC ${TGA_INCLUDE_DIRS}
)