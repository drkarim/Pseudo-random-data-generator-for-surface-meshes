cmake_minimum_required(VERSION 2.8)
 
PROJECT(t_scalar)


 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(RandomScalar RandomScalar.cxx)
 

target_link_libraries(RandomScalar ${VTK_LIBRARIES})
