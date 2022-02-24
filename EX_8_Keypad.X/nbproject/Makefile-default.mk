#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/EX_8_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/EX_8_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../pic24_code_examples/lib/src/pic24_timer.c ../pic24_code_examples/lib/src/dataXfer.c ../pic24_code_examples/lib/src/pic24_util.c ../pic24_code_examples/lib/src/dataXferImpl.c ../pic24_code_examples/lib/src/pic24_flash.c ../pic24_code_examples/lib/src/pic24_spi.c ../pic24_code_examples/lib/src/pic24_i2c.c ../pic24_code_examples/lib/src/pic24_ecan.c ../pic24_code_examples/lib/src/pic24_configbits.c ../pic24_code_examples/lib/src/pic24_serial.c ../pic24_code_examples/lib/src/pic24_adc.c ../pic24_code_examples/lib/src/pic24_clockfreq.c ../pic24_code_examples/lib/src/pic24_uart.c ../pic24_code_examples/lib/src/pic24_stdio_uart.c ../main_ex8_keypad.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1815454428/pic24_timer.o ${OBJECTDIR}/_ext/1815454428/dataXfer.o ${OBJECTDIR}/_ext/1815454428/pic24_util.o ${OBJECTDIR}/_ext/1815454428/dataXferImpl.o ${OBJECTDIR}/_ext/1815454428/pic24_flash.o ${OBJECTDIR}/_ext/1815454428/pic24_spi.o ${OBJECTDIR}/_ext/1815454428/pic24_i2c.o ${OBJECTDIR}/_ext/1815454428/pic24_ecan.o ${OBJECTDIR}/_ext/1815454428/pic24_configbits.o ${OBJECTDIR}/_ext/1815454428/pic24_serial.o ${OBJECTDIR}/_ext/1815454428/pic24_adc.o ${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o ${OBJECTDIR}/_ext/1815454428/pic24_uart.o ${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o ${OBJECTDIR}/_ext/1472/main_ex8_keypad.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1815454428/pic24_timer.o.d ${OBJECTDIR}/_ext/1815454428/dataXfer.o.d ${OBJECTDIR}/_ext/1815454428/pic24_util.o.d ${OBJECTDIR}/_ext/1815454428/dataXferImpl.o.d ${OBJECTDIR}/_ext/1815454428/pic24_flash.o.d ${OBJECTDIR}/_ext/1815454428/pic24_spi.o.d ${OBJECTDIR}/_ext/1815454428/pic24_i2c.o.d ${OBJECTDIR}/_ext/1815454428/pic24_ecan.o.d ${OBJECTDIR}/_ext/1815454428/pic24_configbits.o.d ${OBJECTDIR}/_ext/1815454428/pic24_serial.o.d ${OBJECTDIR}/_ext/1815454428/pic24_adc.o.d ${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o.d ${OBJECTDIR}/_ext/1815454428/pic24_uart.o.d ${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o.d ${OBJECTDIR}/_ext/1472/main_ex8_keypad.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1815454428/pic24_timer.o ${OBJECTDIR}/_ext/1815454428/dataXfer.o ${OBJECTDIR}/_ext/1815454428/pic24_util.o ${OBJECTDIR}/_ext/1815454428/dataXferImpl.o ${OBJECTDIR}/_ext/1815454428/pic24_flash.o ${OBJECTDIR}/_ext/1815454428/pic24_spi.o ${OBJECTDIR}/_ext/1815454428/pic24_i2c.o ${OBJECTDIR}/_ext/1815454428/pic24_ecan.o ${OBJECTDIR}/_ext/1815454428/pic24_configbits.o ${OBJECTDIR}/_ext/1815454428/pic24_serial.o ${OBJECTDIR}/_ext/1815454428/pic24_adc.o ${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o ${OBJECTDIR}/_ext/1815454428/pic24_uart.o ${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o ${OBJECTDIR}/_ext/1472/main_ex8_keypad.o

# Source Files
SOURCEFILES=../pic24_code_examples/lib/src/pic24_timer.c ../pic24_code_examples/lib/src/dataXfer.c ../pic24_code_examples/lib/src/pic24_util.c ../pic24_code_examples/lib/src/dataXferImpl.c ../pic24_code_examples/lib/src/pic24_flash.c ../pic24_code_examples/lib/src/pic24_spi.c ../pic24_code_examples/lib/src/pic24_i2c.c ../pic24_code_examples/lib/src/pic24_ecan.c ../pic24_code_examples/lib/src/pic24_configbits.c ../pic24_code_examples/lib/src/pic24_serial.c ../pic24_code_examples/lib/src/pic24_adc.c ../pic24_code_examples/lib/src/pic24_clockfreq.c ../pic24_code_examples/lib/src/pic24_uart.c ../pic24_code_examples/lib/src/pic24_stdio_uart.c ../main_ex8_keypad.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/EX_8_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ128GP502
MP_LINKER_FILE_OPTION=,--script=p24HJ128GP502.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1815454428/pic24_timer.o: ../pic24_code_examples/lib/src/pic24_timer.c  .generated_files/flags/default/771ebfc95233a5da8e6fae3fd3724154547288b1 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_timer.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/dataXfer.o: ../pic24_code_examples/lib/src/dataXfer.c  .generated_files/flags/default/73af02544b1d93239e00321f3341edf2db22fe32 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/dataXfer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/dataXfer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/dataXfer.c  -o ${OBJECTDIR}/_ext/1815454428/dataXfer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/dataXfer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_util.o: ../pic24_code_examples/lib/src/pic24_util.c  .generated_files/flags/default/598e781735922aeb6d6830f47a18e0b52b7c1034 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_util.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_util.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_util.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/dataXferImpl.o: ../pic24_code_examples/lib/src/dataXferImpl.c  .generated_files/flags/default/dd64a43ca110fbdec1676eccbe706b2462e9bba .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/dataXferImpl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/dataXferImpl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/dataXferImpl.c  -o ${OBJECTDIR}/_ext/1815454428/dataXferImpl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/dataXferImpl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_flash.o: ../pic24_code_examples/lib/src/pic24_flash.c  .generated_files/flags/default/2183a4922f5be7ea25c727482ebdbe7691a5e531 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_flash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_flash.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_flash.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_spi.o: ../pic24_code_examples/lib/src/pic24_spi.c  .generated_files/flags/default/92c75d9feac70829384e97c22e7fd638b61eed64 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_spi.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_i2c.o: ../pic24_code_examples/lib/src/pic24_i2c.c  .generated_files/flags/default/e905718cae5b6a73e3437297c2dd996bd2af8d37 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_i2c.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_ecan.o: ../pic24_code_examples/lib/src/pic24_ecan.c  .generated_files/flags/default/c9d26f1a81e8088b91c682324c5eb101119fd648 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_ecan.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_ecan.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_ecan.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_ecan.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_ecan.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_configbits.o: ../pic24_code_examples/lib/src/pic24_configbits.c  .generated_files/flags/default/96850da53b479e4011679295350cba76520ecd3f .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_configbits.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_configbits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_configbits.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_configbits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_configbits.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_serial.o: ../pic24_code_examples/lib/src/pic24_serial.c  .generated_files/flags/default/1477183036b9800bbfb508d8db546b4fff2f9c1d .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_serial.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_serial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_serial.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_adc.o: ../pic24_code_examples/lib/src/pic24_adc.c  .generated_files/flags/default/36f8ca80e9973a624787d153e6b047f7d6ddbeb1 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_adc.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o: ../pic24_code_examples/lib/src/pic24_clockfreq.c  .generated_files/flags/default/541358d5241d5df1f011a2d75ceb1efcc8b94520 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_clockfreq.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_uart.o: ../pic24_code_examples/lib/src/pic24_uart.c  .generated_files/flags/default/f67e8d68e567e331a233efae93102c4b2aaafa3e .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_uart.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o: ../pic24_code_examples/lib/src/pic24_stdio_uart.c  .generated_files/flags/default/52454ca7db9d57f3b7539e91cc5a6f1911deaa1c .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_stdio_uart.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/main_ex8_keypad.o: ../main_ex8_keypad.c  .generated_files/flags/default/2dbb1481bea614cae5d25d3d9193f08f62937b98 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main_ex8_keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main_ex8_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main_ex8_keypad.c  -o ${OBJECTDIR}/_ext/1472/main_ex8_keypad.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/main_ex8_keypad.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1815454428/pic24_timer.o: ../pic24_code_examples/lib/src/pic24_timer.c  .generated_files/flags/default/47427eef2ba876dc673d21bc1e0590cc07d0d30e .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_timer.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_timer.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/dataXfer.o: ../pic24_code_examples/lib/src/dataXfer.c  .generated_files/flags/default/f4ca4459766f5f5d2404727e2ab173636fc3d36a .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/dataXfer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/dataXfer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/dataXfer.c  -o ${OBJECTDIR}/_ext/1815454428/dataXfer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/dataXfer.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_util.o: ../pic24_code_examples/lib/src/pic24_util.c  .generated_files/flags/default/28109d812b7a699c803e00d2200822671af13c4c .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_util.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_util.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_util.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/dataXferImpl.o: ../pic24_code_examples/lib/src/dataXferImpl.c  .generated_files/flags/default/99880670286e69602827a0f8cec67d80a0cb6d4a .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/dataXferImpl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/dataXferImpl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/dataXferImpl.c  -o ${OBJECTDIR}/_ext/1815454428/dataXferImpl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/dataXferImpl.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_flash.o: ../pic24_code_examples/lib/src/pic24_flash.c  .generated_files/flags/default/68c4740db7fb736363f17ffd112a042e0cdf32e5 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_flash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_flash.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_flash.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_spi.o: ../pic24_code_examples/lib/src/pic24_spi.c  .generated_files/flags/default/c12ac0b5500ee873f7f6a4169eba3fcc10726214 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_spi.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_spi.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_i2c.o: ../pic24_code_examples/lib/src/pic24_i2c.c  .generated_files/flags/default/18a96c6eca4d7a60a2741be4605b8f1b34ec9cf3 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_i2c.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_i2c.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_ecan.o: ../pic24_code_examples/lib/src/pic24_ecan.c  .generated_files/flags/default/63a3d09b13edfe10ae35e46e7438a477b4ebd47e .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_ecan.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_ecan.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_ecan.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_ecan.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_ecan.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_configbits.o: ../pic24_code_examples/lib/src/pic24_configbits.c  .generated_files/flags/default/191aca043884bd9ca014e45e40f7b6904cf6a054 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_configbits.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_configbits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_configbits.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_configbits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_configbits.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_serial.o: ../pic24_code_examples/lib/src/pic24_serial.c  .generated_files/flags/default/78aed76bf00d05701a66a5c818bf57c3eb434622 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_serial.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_serial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_serial.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_adc.o: ../pic24_code_examples/lib/src/pic24_adc.c  .generated_files/flags/default/d3e813119726238bc7913c4be902b11249c7bfb0 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_adc.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_adc.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o: ../pic24_code_examples/lib/src/pic24_clockfreq.c  .generated_files/flags/default/bbc3a5655ab42f0ad71affa5651c97e6a56c3bcc .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_clockfreq.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_clockfreq.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_uart.o: ../pic24_code_examples/lib/src/pic24_uart.c  .generated_files/flags/default/f6d0651bc2880ea61b87777e70014d52d216a47f .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_uart.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_uart.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o: ../pic24_code_examples/lib/src/pic24_stdio_uart.c  .generated_files/flags/default/a72c94dfed69ccd352e16505dd64387357b21510 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1815454428" 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../pic24_code_examples/lib/src/pic24_stdio_uart.c  -o ${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1815454428/pic24_stdio_uart.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/main_ex8_keypad.o: ../main_ex8_keypad.c  .generated_files/flags/default/a7167301d0b398e001d3a2b4519a5ca80eea8ca4 .generated_files/flags/default/c3bcb89a839b6aab43a2e4502bbfa70e66d2d91a
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main_ex8_keypad.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main_ex8_keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main_ex8_keypad.c  -o ${OBJECTDIR}/_ext/1472/main_ex8_keypad.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/main_ex8_keypad.o.d"        -g -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/EX_8_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/EX_8_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include"     -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/EX_8_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/EX_8_Keypad.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DHARDWARE_PLATFORM=5 -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../pic24_code_examples/lib/include" -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/EX_8_Keypad.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
