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
ifeq "$(wildcard nbproject/Makefile-local-Test.mk)" "nbproject/Makefile-local-Test.mk"
include nbproject/Makefile-local-Test.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Test
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/sensorNode.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/sensorNode.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../framework/driver/mrf_miwi/src/drv_mrf_miwi_89xa.c ../framework/driver/mrf_miwi/src/drv_mrf_miwi_crc.c ../framework/driver/mrf_miwi/src/drv_mrf_miwi_security.c ../framework/miwi/src/miwi_nvm.c ../framework/miwi/src/miwi_p2p.c ../src/system_config/pic24hj128gp502_89xa/console.c ../src/system_config/pic24hj128gp502_89xa/delay.c ../src/system_config/pic24hj128gp502_89xa/spi.c ../src/system_config/pic24hj128gp502_89xa/symbol.c ../src/system_config/pic24hj128gp502_89xa/system.c ../src/demo_ouput.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o ${OBJECTDIR}/_ext/1310079843/miwi_nvm.o ${OBJECTDIR}/_ext/1310079843/miwi_p2p.o ${OBJECTDIR}/_ext/162297189/console.o ${OBJECTDIR}/_ext/162297189/delay.o ${OBJECTDIR}/_ext/162297189/spi.o ${OBJECTDIR}/_ext/162297189/symbol.o ${OBJECTDIR}/_ext/162297189/system.o ${OBJECTDIR}/_ext/1360937237/demo_ouput.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o.d ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o.d ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o.d ${OBJECTDIR}/_ext/1310079843/miwi_nvm.o.d ${OBJECTDIR}/_ext/1310079843/miwi_p2p.o.d ${OBJECTDIR}/_ext/162297189/console.o.d ${OBJECTDIR}/_ext/162297189/delay.o.d ${OBJECTDIR}/_ext/162297189/spi.o.d ${OBJECTDIR}/_ext/162297189/symbol.o.d ${OBJECTDIR}/_ext/162297189/system.o.d ${OBJECTDIR}/_ext/1360937237/demo_ouput.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o ${OBJECTDIR}/_ext/1310079843/miwi_nvm.o ${OBJECTDIR}/_ext/1310079843/miwi_p2p.o ${OBJECTDIR}/_ext/162297189/console.o ${OBJECTDIR}/_ext/162297189/delay.o ${OBJECTDIR}/_ext/162297189/spi.o ${OBJECTDIR}/_ext/162297189/symbol.o ${OBJECTDIR}/_ext/162297189/system.o ${OBJECTDIR}/_ext/1360937237/demo_ouput.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../framework/driver/mrf_miwi/src/drv_mrf_miwi_89xa.c ../framework/driver/mrf_miwi/src/drv_mrf_miwi_crc.c ../framework/driver/mrf_miwi/src/drv_mrf_miwi_security.c ../framework/miwi/src/miwi_nvm.c ../framework/miwi/src/miwi_p2p.c ../src/system_config/pic24hj128gp502_89xa/console.c ../src/system_config/pic24hj128gp502_89xa/delay.c ../src/system_config/pic24hj128gp502_89xa/spi.c ../src/system_config/pic24hj128gp502_89xa/symbol.c ../src/system_config/pic24hj128gp502_89xa/system.c ../src/demo_ouput.c ../src/main.c


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
	${MAKE}  -f nbproject/Makefile-Test.mk dist/${CND_CONF}/${IMAGE_TYPE}/sensorNode.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ128GP502
MP_LINKER_FILE_OPTION=,--script=p24HJ128GP502.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o: ../framework/driver/mrf_miwi/src/drv_mrf_miwi_89xa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/638162376" 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o.d 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/driver/mrf_miwi/src/drv_mrf_miwi_89xa.c  -o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o: ../framework/driver/mrf_miwi/src/drv_mrf_miwi_crc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/638162376" 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/driver/mrf_miwi/src/drv_mrf_miwi_crc.c  -o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o: ../framework/driver/mrf_miwi/src/drv_mrf_miwi_security.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/638162376" 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o.d 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/driver/mrf_miwi/src/drv_mrf_miwi_security.c  -o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1310079843/miwi_nvm.o: ../framework/miwi/src/miwi_nvm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1310079843" 
	@${RM} ${OBJECTDIR}/_ext/1310079843/miwi_nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1310079843/miwi_nvm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/miwi/src/miwi_nvm.c  -o ${OBJECTDIR}/_ext/1310079843/miwi_nvm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1310079843/miwi_nvm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1310079843/miwi_nvm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1310079843/miwi_p2p.o: ../framework/miwi/src/miwi_p2p.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1310079843" 
	@${RM} ${OBJECTDIR}/_ext/1310079843/miwi_p2p.o.d 
	@${RM} ${OBJECTDIR}/_ext/1310079843/miwi_p2p.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/miwi/src/miwi_p2p.c  -o ${OBJECTDIR}/_ext/1310079843/miwi_p2p.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1310079843/miwi_p2p.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1310079843/miwi_p2p.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/console.o: ../src/system_config/pic24hj128gp502_89xa/console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/console.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/console.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/console.c  -o ${OBJECTDIR}/_ext/162297189/console.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/console.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/console.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/delay.o: ../src/system_config/pic24hj128gp502_89xa/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/delay.c  -o ${OBJECTDIR}/_ext/162297189/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/delay.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/delay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/spi.o: ../src/system_config/pic24hj128gp502_89xa/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/spi.c  -o ${OBJECTDIR}/_ext/162297189/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/symbol.o: ../src/system_config/pic24hj128gp502_89xa/symbol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/symbol.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/symbol.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/symbol.c  -o ${OBJECTDIR}/_ext/162297189/symbol.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/symbol.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/symbol.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/system.o: ../src/system_config/pic24hj128gp502_89xa/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/system.c  -o ${OBJECTDIR}/_ext/162297189/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/demo_ouput.o: ../src/demo_ouput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/demo_ouput.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/demo_ouput.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_ouput.c  -o ${OBJECTDIR}/_ext/1360937237/demo_ouput.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/demo_ouput.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/demo_ouput.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o: ../framework/driver/mrf_miwi/src/drv_mrf_miwi_89xa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/638162376" 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o.d 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/driver/mrf_miwi/src/drv_mrf_miwi_89xa.c  -o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_89xa.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o: ../framework/driver/mrf_miwi/src/drv_mrf_miwi_crc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/638162376" 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/driver/mrf_miwi/src/drv_mrf_miwi_crc.c  -o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_crc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o: ../framework/driver/mrf_miwi/src/drv_mrf_miwi_security.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/638162376" 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o.d 
	@${RM} ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/driver/mrf_miwi/src/drv_mrf_miwi_security.c  -o ${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/638162376/drv_mrf_miwi_security.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1310079843/miwi_nvm.o: ../framework/miwi/src/miwi_nvm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1310079843" 
	@${RM} ${OBJECTDIR}/_ext/1310079843/miwi_nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1310079843/miwi_nvm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/miwi/src/miwi_nvm.c  -o ${OBJECTDIR}/_ext/1310079843/miwi_nvm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1310079843/miwi_nvm.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1310079843/miwi_nvm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1310079843/miwi_p2p.o: ../framework/miwi/src/miwi_p2p.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1310079843" 
	@${RM} ${OBJECTDIR}/_ext/1310079843/miwi_p2p.o.d 
	@${RM} ${OBJECTDIR}/_ext/1310079843/miwi_p2p.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../framework/miwi/src/miwi_p2p.c  -o ${OBJECTDIR}/_ext/1310079843/miwi_p2p.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1310079843/miwi_p2p.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1310079843/miwi_p2p.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/console.o: ../src/system_config/pic24hj128gp502_89xa/console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/console.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/console.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/console.c  -o ${OBJECTDIR}/_ext/162297189/console.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/console.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/console.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/delay.o: ../src/system_config/pic24hj128gp502_89xa/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/delay.c  -o ${OBJECTDIR}/_ext/162297189/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/delay.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/delay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/spi.o: ../src/system_config/pic24hj128gp502_89xa/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/spi.c  -o ${OBJECTDIR}/_ext/162297189/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/spi.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/symbol.o: ../src/system_config/pic24hj128gp502_89xa/symbol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/symbol.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/symbol.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/symbol.c  -o ${OBJECTDIR}/_ext/162297189/symbol.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/symbol.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/symbol.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/162297189/system.o: ../src/system_config/pic24hj128gp502_89xa/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/162297189" 
	@${RM} ${OBJECTDIR}/_ext/162297189/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/162297189/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/pic24hj128gp502_89xa/system.c  -o ${OBJECTDIR}/_ext/162297189/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/162297189/system.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/162297189/system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/demo_ouput.o: ../src/demo_ouput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/demo_ouput.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/demo_ouput.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_ouput.c  -o ${OBJECTDIR}/_ext/1360937237/demo_ouput.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/demo_ouput.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/demo_ouput.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -O0 -I"../src" -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/sensorNode.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/sensorNode.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src"     -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/sensorNode.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/sensorNode.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -I"../framework" -I"../src/system_config/pic24hj128gp502_89xa" -I"../src" -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/sensorNode.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Test
	${RM} -r dist/Test

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
