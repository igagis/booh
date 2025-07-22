cmake_minimum_required(VERSION 3.25)

set(name booh)
project(${name})

# !!! find_package must go after project() declaration !!!
# Otherwise VCPKG does not set the CMAKE_PREFIX_PATH to find packages.
find_package(myci CONFIG REQUIRED)

set(srcs)
myci_add_source_files(srcs
    DIRECTORY
        ../../src/${name}
    RECURSIVE
)

myci_declare_application(${name}
    GUI
    SOURCES
        ${srcs}
    RESOURCE_DIRECTORY
        ../../res
    DEPENDENCIES
        ruisapp::ruisapp-opengl
)
