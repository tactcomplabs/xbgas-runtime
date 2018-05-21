# src/xbgas-runtime CMakeLists.txt driver
#
# Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# CoreGen can not be copied and/or distributed without the
# express permission of Tactical Computing Laboratories, LLC
#

#-- override the default compiler/assembler
set(CMAKE_C_COMPILER "${RISCV_ENV}/bin/riscv64-unknown-elf-gcc")
set(CMAKE_ASM_COMPILER "${RISCV_ENV}/bin/riscv64-unknown-elf-gcc")

set(XBGASSrcs
)

include_directories( . )
add_library( xbrtime STATIC ${XBGASSrcs} )

# EOF
