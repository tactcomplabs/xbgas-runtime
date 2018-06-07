# test/ CMakeLists.txt driver
#
# Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# This file is a part of the XBGAS-RUNTIME package.  For license
# information, see the LICENSE file in the top level directory of
# this distribution.
#

if(BUILD_ALL_TESTING)
  set(BUILD_INIT_TESTING "ON")
  set(BUILD_ALLOC_TESTING "ON")
  set(BUILD_XFER_TESTING "ON")
endif()

add_subdirectory(init)
add_subdirectory(alloc)
add_subdirectory(xfer)
