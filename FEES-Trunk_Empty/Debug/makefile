################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FEES-Trunk_Empty.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
FEES-Trunk_Empty.list \

OBJCOPY_BIN += \
FEES-Trunk_Empty.bin \


# All Target
all: FEES-Trunk_Empty.elf secondary-outputs

# Tool invocations
FEES-Trunk_Empty.elf: $(OBJS) $(USER_OBJS) C:\Users\stefa\Documents\STM32IDE_Workspace\FEES-Trunk_Empty\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "FEES-Trunk_Empty.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\stefa\Documents\STM32IDE_Workspace\FEES-Trunk_Empty\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="FEES-Trunk_Empty.map" -Wl,--gc-sections -static -L"\Core\Inc" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

FEES-Trunk_Empty.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "FEES-Trunk_Empty.list"
	@echo 'Finished building: $@'
	@echo ' '

FEES-Trunk_Empty.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "FEES-Trunk_Empty.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
