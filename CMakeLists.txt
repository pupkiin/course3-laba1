cmake_minimum_required(VERSION 3.0.0...3.27.6)
project(laba-1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(laba-1 main.cpp Keeper.h Books.cpp Books.h Check.h Fantast.cpp Fantast.h Novel.cpp Novel.h Poet.cpp Poet.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
