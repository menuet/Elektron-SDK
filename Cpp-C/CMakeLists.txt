cmake_minimum_required(VERSION 2.8)

project(Elektron-SDK)

set(CMAKE_CONFIGURATION_TYPES Debug Release) # TODO: ReleaseAssert

add_subdirectory(Eta/Utils/Libxml2)
add_subdirectory(Eta/Impl)
add_subdirectory(Ema/Src/Access)


