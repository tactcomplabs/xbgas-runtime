# src/xbgas-runtime CMakeLists.txt driver
#
# Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# This file is a part of the XBGAS-RUNTIME package.  For license
# information, see the LICENSE file in the top level directory of
# this distribution.
#

#-- override the default compiler/assembler
set(CMAKE_C_COMPILER "${RISCV_ENV}/bin/riscv64-unknown-elf-gcc")
set(CMAKE_ASM_COMPILER "${RISCV_ENV}/bin/riscv64-unknown-elf-gcc")

#-- ensure we're using C11
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(XBGASSrcs
xbrtime.h
xbrtime-version.h
xbrtime-types.h
xbrtime-macros.h
xbrtime-alloc.h
xbrtime-api.h
xbrtime-collectives.h
xbrtime-atomics.h
xbrtime_init.c
xbrtime_ctor.c
xbrtime_util.c
xbrtime_api.c
xbrtime_alloc.c
xbrtime_barrier.c
xbrtime_collectives.c
xbrtime_atomics.c
xbrtime_ctor_asm.s
xbrtime_util_asm.s
xbrtime_api_asm.s
xbrtime_atomics_asm.s
)

include_directories( . )
add_library( xbrtime STATIC ${XBGASSrcs} )

install(TARGETS xbrtime DESTINATION lib )
install(DIRECTORY ./ DESTINATION include
        FILES_MATCHING PATTERN "*.h*")

# EOF
