#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/cCGIHelper.o \
	${OBJECTDIR}/cCSS.o \
	${OBJECTDIR}/cEncounter.o \
	${OBJECTDIR}/cGUICgi.o \
	${OBJECTDIR}/cHelper.o \
	${OBJECTDIR}/cHelperSerializer.o \
	${OBJECTDIR}/cPair.o \
	${OBJECTDIR}/cPlayer.o \
	${OBJECTDIR}/cPlayerPool.o \
	${OBJECTDIR}/cRendererCGI.o \
	${OBJECTDIR}/cTournament.o \
	${OBJECTDIR}/cTournamentParameter.o \
	${OBJECTDIR}/iRenderable.o \
	${OBJECTDIR}/iRenderer.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x -lboost_program_options -lboost_serialization -lcgicc
CXXFLAGS=-std=c++0x -lboost_program_options -lboost_serialization -lcgicc

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ltm

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ltm: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ltm ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/cCGIHelper.o: cCGIHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cCGIHelper.o cCGIHelper.cpp

${OBJECTDIR}/cCSS.o: cCSS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cCSS.o cCSS.cpp

${OBJECTDIR}/cEncounter.o: cEncounter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cEncounter.o cEncounter.cpp

${OBJECTDIR}/cGUICgi.o: cGUICgi.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cGUICgi.o cGUICgi.cpp

${OBJECTDIR}/cHelper.o: cHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cHelper.o cHelper.cpp

${OBJECTDIR}/cHelperSerializer.o: cHelperSerializer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cHelperSerializer.o cHelperSerializer.cpp

${OBJECTDIR}/cPair.o: cPair.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cPair.o cPair.cpp

${OBJECTDIR}/cPlayer.o: cPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cPlayer.o cPlayer.cpp

${OBJECTDIR}/cPlayerPool.o: cPlayerPool.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cPlayerPool.o cPlayerPool.cpp

${OBJECTDIR}/cRendererCGI.o: cRendererCGI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cRendererCGI.o cRendererCGI.cpp

${OBJECTDIR}/cTournament.o: cTournament.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cTournament.o cTournament.cpp

${OBJECTDIR}/cTournamentParameter.o: cTournamentParameter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cTournamentParameter.o cTournamentParameter.cpp

${OBJECTDIR}/iRenderable.o: iRenderable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/iRenderable.o iRenderable.cpp

${OBJECTDIR}/iRenderer.o: iRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/iRenderer.o iRenderer.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/boost -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ltm

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
