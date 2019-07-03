# test/xfer CMakeLists.txt driver
#
# Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# This file is a part of the XBGAS-RUNTIME package.  For license
# information, see the LICENSE file in the top level directory of
# this distribution.
#

include_directories(${XBGAS_PATH})

file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)

if(BUILD_XFER_TESTING)
foreach(testSrc ${TEST_SRCS})
  # Extract the file name
  get_filename_component(testName ${testSrc} NAME_WE)

  # Add compile target
  add_executable(${testName} ${testSrc})

  # Override the compiler
  set(CMAKE_C_COMPILER "${RISCV_ENV}/bin/riscv64-unknown-elf-gcc")
  set(CMAKE_ASM_COMPILER "${RISCV_ENV}/bin/riscv64-unknown-elf-gcc")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
  set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

  # Add linker deps
  target_link_libraries(${testName} xbrtime m)

  # Drop the exe's in a separate directory
  set_target_properties(${testName} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin)

  # Add the tests for execution
  add_test(NAME ${testName}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin
    COMMAND mpirun -n 2 -bind-to core:2 ${RISCV_ENV}/bin/spike -x512 pk ${CMAKE_CURRENT_SOURCE_DIR}/testBin/${testName})
  set_tests_properties( ${testName} 
	PROPERTIES 
		PASS_REGULAR_EXPRESSION "" 
		ENVIRONMENT "export MPICH_ASYNC_PROGRESS=1")
endforeach(testSrc)
endif()
