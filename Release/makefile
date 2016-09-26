################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
blink_led.lss \

FLASH_IMAGE += \
blink_led.hex \

EEPROM_IMAGE += \
blink_led.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: blink_led.elf secondary-outputs

# Tool invocations
blink_led.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,blink_led.map -mmcu=atmega328p -o "blink_led.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

blink_led.lss: blink_led.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S blink_led.elf  >"blink_led.lss"
	@echo 'Finished building: $@'
	@echo ' '

blink_led.hex: blink_led.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex blink_led.elf  "blink_led.hex"
	@echo 'Finished building: $@'
	@echo ' '

blink_led.eep: blink_led.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex blink_led.elf  "blink_led.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: blink_led.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p blink_led.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) blink_led.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
