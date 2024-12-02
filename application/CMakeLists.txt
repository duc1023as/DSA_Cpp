project(application)

file(GLOB SOURCES
    *.h
    **/*.h
    *.cpp
    **/*.cpp
)

foreach(FILE_NAME ${SOURCES})
    message("FILE NAME: ${FILE_NAME}")
endforeach()

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE LinkedList)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)