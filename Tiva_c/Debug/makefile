################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./GPIO.obj" \
"./GPIO_config.obj" \
"./GPT.obj" \
"./GPT_config.obj" \
"./SCB.obj" \
"./SCB_config.obj" \
"./SCHEDULAR.obj" \
"./SYSTICK.obj" \
"./SYSTICK_config.obj" \
"./UART_config.obj" \
"./UART_program.obj" \
"./adc.obj" \
"./main.obj" \
"./tm4c123ge6pm_startup_ccs.obj" \
"./Inc/APP/AutonomousCar/AutonomousCar.obj" \
"./Inc/APP/Calc/calc.obj" \
"./Inc/APP/Calc/calc_main.obj" \
"./Inc/APP/StopWatch/stopWatch.obj" \
"./Inc/HAL/KEYPAD/keypad.obj" \
"./Inc/HAL/LCD/lcd.obj" \
"./Inc/HAL/MOTOR/motor.obj" \
"./Inc/HAL/SWITCH/switch.obj" \
"./Inc/HAL/ULTRASONIC/ultrasonic.obj" \
"./Inc/LIB/delay.obj" \
"../tm4c123ge6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Inc/APP/AutonomousCar/subdir_vars.mk
-include Inc/APP/Calc/subdir_vars.mk
-include Inc/APP/StopWatch/subdir_vars.mk
-include Inc/HAL/KEYPAD/subdir_vars.mk
-include Inc/HAL/LCD/subdir_vars.mk
-include Inc/HAL/MOTOR/subdir_vars.mk
-include Inc/HAL/SWITCH/subdir_vars.mk
-include Inc/HAL/ULTRASONIC/subdir_vars.mk
-include Inc/LIB/subdir_vars.mk
-include subdir_rules.mk
-include Inc/APP/AutonomousCar/subdir_rules.mk
-include Inc/APP/Calc/subdir_rules.mk
-include Inc/APP/StopWatch/subdir_rules.mk
-include Inc/HAL/KEYPAD/subdir_rules.mk
-include Inc/HAL/LCD/subdir_rules.mk
-include Inc/HAL/MOTOR/subdir_rules.mk
-include Inc/HAL/SWITCH/subdir_rules.mk
-include Inc/HAL/ULTRASONIC/subdir_rules.mk
-include Inc/LIB/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Tiva_c.out \

EXE_OUTPUTS__QUOTED += \
"Tiva_c.out" \

BIN_OUTPUTS += \
Tiva_c.hex \

BIN_OUTPUTS__QUOTED += \
"Tiva_c.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Tiva_c.out"

# Tool invocations
Tiva_c.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GE6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"Tiva_c.map" --heap_size=0 --stack_size=512 -i"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/lib" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="Tiva_c_linkInfo.xml" --rom_model -o "Tiva_c.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Tiva_c.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armhex"  -o "Tiva_c.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "GPIO.obj" "GPIO_config.obj" "GPT.obj" "GPT_config.obj" "SCB.obj" "SCB_config.obj" "SCHEDULAR.obj" "SYSTICK.obj" "SYSTICK_config.obj" "UART_config.obj" "UART_program.obj" "adc.obj" "main.obj" "tm4c123ge6pm_startup_ccs.obj" "Inc\APP\AutonomousCar\AutonomousCar.obj" "Inc\APP\Calc\calc.obj" "Inc\APP\Calc\calc_main.obj" "Inc\APP\StopWatch\stopWatch.obj" "Inc\HAL\KEYPAD\keypad.obj" "Inc\HAL\LCD\lcd.obj" "Inc\HAL\MOTOR\motor.obj" "Inc\HAL\SWITCH\switch.obj" "Inc\HAL\ULTRASONIC\ultrasonic.obj" "Inc\LIB\delay.obj" 
	-$(RM) "GPIO.d" "GPIO_config.d" "GPT.d" "GPT_config.d" "SCB.d" "SCB_config.d" "SCHEDULAR.d" "SYSTICK.d" "SYSTICK_config.d" "UART_config.d" "UART_program.d" "adc.d" "main.d" "tm4c123ge6pm_startup_ccs.d" "Inc\APP\AutonomousCar\AutonomousCar.d" "Inc\APP\Calc\calc.d" "Inc\APP\Calc\calc_main.d" "Inc\APP\StopWatch\stopWatch.d" "Inc\HAL\KEYPAD\keypad.d" "Inc\HAL\LCD\lcd.d" "Inc\HAL\MOTOR\motor.d" "Inc\HAL\SWITCH\switch.d" "Inc\HAL\ULTRASONIC\ultrasonic.d" "Inc\LIB\delay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

