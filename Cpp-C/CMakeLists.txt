cmake_minimum_required(VERSION 2.8)

project(Elektron-SDK)

set(CMAKE_CONFIGURATION_TYPES Debug Release) # TODO: ReleaseAssert

if(MSVC)
    set(ELEK_C_FLAGS "")
    set(ELEK_DEFINITIONS WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
else()
    set(ELEK_C_FLAGS -m64)
    set(ELEK_DEFINITIONS _SVID_SOURCE=1 COMPILE_64BITS Linux x86_Linux_4X x86_Linux_5X LinuxVersion=5 _iso_stdcpp_ _BSD_SOURCE=1 _POSIX_SOURCE=1 _POSIX_C_SOURCE=199506L _XOPEN_SOURCE=500  _POSIX_PTHREAD_SEMANTICS _GNU_SOURCE)
endif()

if(MSVC)
    add_subdirectory(Eta/Utils/Libxml2)
endif()
add_subdirectory(Eta/Impl)
add_subdirectory(Ema/Src/Access)


