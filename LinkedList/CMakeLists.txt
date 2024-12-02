project(LinkedList)

file(GLOB SOURCES
    *.h
    **/*.h
    *.cpp
    **/*.cpp
)

foreach(FILE_NAME ${SOURCES})
    message("FILE NAME: ${FILE_NAME}")
endforeach()

add_library(${PROJECT_NAME} INTERFACE ${SOURCES})
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)