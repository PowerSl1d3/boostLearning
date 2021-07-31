cmake_minimum_required(VERSION 3.19)
project(GettingConfigurationParameters)

set(CMAKE_CXX_STANDARD 17)

find_package( Boost REQUIRED program_options )

add_executable(GettingConfigurationParameters main.cpp)

target_link_libraries( GettingConfigurationParameters PUBLIC ${Boost_LIBRARIES})