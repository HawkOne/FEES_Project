# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/LASERNAV_STM32F4-FEES/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/LASERNAV_STM32F4-FEES

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
