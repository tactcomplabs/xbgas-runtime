# xBGAS Top-Level CMake Description
#
# Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# This file is a part of the XBGAS-RUNTIME package.  For license
# information, see the LICENSE file in the top level directory of
# this distribution.
#

cmake_minimum_required (VERSION 2.6)
project(xbgas-runtime C CXX ASM)

#------------------------------------------------------------------------
#-- COMPILER OPTIONS
#------------------------------------------------------------------------

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -O0 -Wall -DXBGAS_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -Wall")

#------------------------------------------------------------------------
#-- TOP LEVEL PATHS
#------------------------------------------------------------------------
if(NOT XBGAS_PATH)
  set(XBGAS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/xbgas-runtime")
  message(STATUS "XBGAS_PATH set to ${XBGAS_PATH}")
endif()

#------------------------------------------------------------------------
#-- FIND PACKAGES
#------------------------------------------------------------------------

# Find all the relevant packages
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the doxygen-ized API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

set( RISCV_ENV "$ENV{RISCV}" )
if(RISCV_ENV)
  message(STATUS "RISCV environment set to ${RISCV_ENV}.")
else()
  message(FATAL_ERROR "RISCV environment variable is not set.")
endif()

#------------------------------------------------------------------------
#-- DOCUMENTATION
#------------------------------------------------------------------------

# Doxygen config
if(BUILD_DOCUMENTATION)
  if( NOT DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is required to build the documentation.")
  endif()

  set(doxyfile ${CMAKE_CURRENT_SOURCE_DIR}/doxygen/xbgas-runtime.conf)

  add_custom_target(doc
                    COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    COMMENT "Generating API documentation with Doxygen"
                    VERBATIM)

  install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxygen/html DESTINATION share/doc)
  install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxygen/man DESTINATION share/man)

  message(STATUS "Enabling developer documentation")
endif()

#------------------------------------------------------------------------
#-- TESTING
#------------------------------------------------------------------------
# Enable testing
enable_testing()

#------------------------------------------------------------------------
#-- SUBDIRECTORIES
#------------------------------------------------------------------------
# Add our subdirectories
add_subdirectory( src )
add_subdirectory( test )


#-- EOF
