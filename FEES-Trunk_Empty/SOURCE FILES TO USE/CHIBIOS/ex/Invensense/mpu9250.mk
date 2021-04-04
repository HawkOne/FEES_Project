# List of all the LSM6DS0 device files.
MPU9250SRC := $(CHIBIOS)/os/ex/Invensense/mpu9250.c

# Required include directories
MPU9250INC := $(CHIBIOS)/os/hal/lib/peripherals/sensors \
              $(CHIBIOS)/os/ex/Invensense

# Shared variables
ALLCSRC += $(MPU9250SRC)
ALLINC  += $(MPU9250INC)