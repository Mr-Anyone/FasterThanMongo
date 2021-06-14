cmake_minimum_required(VERSION 3.10)
project(FasterThanMongo)
set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES src/main.cpp )
add_library(Data STATIC src/data.cpp)

add_executable(FasterThanMongo ${SOURCE_FILES})

target_link_libraries(FasterThanMongo PRIVATE Data)
target_include_directories(FasterThanMongo PRIVATE ${PROJECT_SOURCE_DIR}/include)

install(TARGETS FasterThanMongo DESTINATION bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION include)
install(TARGETS Data LIBRARY DESTINATION lib RUNTIME DESTINATION include)

set(CPACK_GENERATOR NSIS)
set(CPACK_PACKAGE_NAME "FasterThanMongodb")
set(CPACK_PACKAGE_VENDOR "lmaolmao123.net")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "This is a database that is really bad :(")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "FasterThanMongo")
SET(CPACK_NSIS_MODIFY_PATH ON)

include(CPack)