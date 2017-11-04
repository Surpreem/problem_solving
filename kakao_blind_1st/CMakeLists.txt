cmake_minimum_required(VERSION 3.7.2)
project(kakao_blind_1st CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Compiler    version(MS)  version(cmake)
# ----------  -----------  --------------
# VS 2015     14           1900
# VS 2017     15           1910

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories("${CMAKE_SOURCE_DIR}/../third_party/catch/include")
include_directories("${CMAKE_SOURCE_DIR}/src")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

message(STATUS "Setting Compiler options")
if(MSVC)
    add_definitions(-D_WIN32_WINNT=0x0601)
    add_definitions(-D_UNICODE -DUNICODE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
    if(MSVC_VERSION GREATER_EQUAL 1910)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
    endif()
elseif(GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic -Werror")
endif()

add_subdirectory(test/problem01)
add_subdirectory(test/problem02)
add_subdirectory(test/problem03)
add_subdirectory(test/problem04)
add_subdirectory(test/problem05)
add_subdirectory(test/problem06)
add_subdirectory(test/problem07)
