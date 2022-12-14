cmake_minimum_required(VERSION 3.16)

set(ADDON_NAME Core)

project(${ADDON_NAME})

set(SOURCE_FILES "")
set(HEADER_FILES "")
set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/shaderc/libshaderc/include
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/SPIRV-Cross
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/stb
)
set(LIBRARIES
    PRIVATE common
    PRIVATE shaderc
    PRIVATE spirv-cross-cpp
)

File(GLOB_RECURSE SOURCE_FILES src/*.cpp )
File(GLOB_RECURSE HEADER_FILES src/*.h   )

add_subdirectory(deps)

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# !!! "CHANGE ONLY IF NEEDED" ZONE !!!
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
set(${ADDON_NAME}_MODE patch CACHE STRING "Mode says how addon should be added.")


# !!!!!!!!!!!!!!!!!!!!!!!!!!!!
# !!! "DO NOT CHANGE" ZONE !!!
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!
set(${ADDON_NAME}_SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)
set(${ADDON_NAME}_HEADER_FILES ${HEADER_FILES} PARENT_SCOPE)
set(${ADDON_NAME}_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
set(${ADDON_NAME}_LIBRARIES    ${LIBRARIES}    PARENT_SCOPE)

IF(${ADDON_NAME}_MODE STREQUAL "static")
    add_library(${ADDON_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
    link_libraries(${ADDON_NAME} ${LIBRARIES})
    include_directories(${ADDON_NAME} ${INCLUDE_DIRS} ..)
ENDIF()

# Add the addon to the list of addons to build
set(ADDONS ${ADDONS} ${ADDON_NAME} PARENT_SCOPE)