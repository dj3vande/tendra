# $TenDRA$

INSTALL_PREFIX=		${INSTALL_DIR}/${TENDRA_VER}/${MACH_OS}/${MACH_VERS}/${MACH_CPU}

.if defined(IMACHINE)
INSTALL_TARGETS+=	install-machine
INSTALL_SUB+=		lib/machines
.endif

.if defined(PROG)
INSTALL_TARGETS+=	install-bin
INSTALL_SUB+=		bin
.if !defined(NOMAN)
MAN+=			${PROG}.1
.endif
.endif

.if defined(STARTUP)
INSTALL_TARGETS+=	install-startup
.endif

.if defined(API)
INSTALL_TARGETS+=	install-api
INSTALL_SUB+=		lib/include/${API}.api lib/include/shared/${API}.api
.endif

.if defined(INSTALL_ENV)
INSTALL_TARGETS+=	install-env
.endif

.if defined(MAN)
INSTALL_TARGETS+=	install-man
.endif

.if defined(PROG)
INSTALL_TARGETS+=	install-wrapper
.endif

.if defined(SHLIB)
INSTALL_TARGETS+=	install-shlib
INSTALL_SUB+=		lib/sys
.endif



# Our main target.
install-all: install-dir ${INSTALL_TARGETS}

# lib/machines: our machine dependent files.
install-machine:
.for i in ${MAKEDIR}
	${BIN_MKDIR} ${ARGS_MKDIR} ${INSTALL_PREFIX}/lib/machines/${i}
.endfor
.for i in ${DATA_INCLUDE}
	${BIN_INSTALL} ${.OBJDIR}/${i} \
		${INSTALL_PREFIX}/lib/machines/${i:C/(.*)\/.*$/\1/}
.endfor
.for i in ${DATA_STARTUP}
	${BIN_INSTALL} ${.OBJDIR}/${i} ${INSTALL_PREFIX}/lib/machines/startup
.endfor
	${BIN_INSTALL} ${.OBJDIR}/tokens/target_tok.tl ${INSTALL_PREFIX}/lib

# lib/startup: our startup files for compilation modes.
install-startup:
	${BIN_MKDIR} ${ARGS_MKDIR} ${INSTALL_PREFIX}/lib/startup/${STARTUP}
.for i in ${DATA}
	${BIN_INSTALL} ${INSTALL_FLAGS} ${.OBJDIR}/${i} \
		${INSTALL_PREFIX}/lib/startup/${STARTUP}
.endfor

# lib/apis: our api files.
install-api:
	for i in ${.OBJDIR}.api/*.h; do \
		${BIN_INSTALL} $$i ${INSTALL_PREFIX}/lib/include/${API}.api; \
	done
	for i in ${.OBJDIR:C/apis/apis\/shared/}.api/*.h; do \
		${BIN_INSTALL} $$i ${INSTALL_PREFIX}/lib/include/shared/${API}.api; \
	done
	${BIN_INSTALL} ${.OBJDIR:C/apis/apis\/lib/}/${API}.tl \
		${INSTALL_PREFIX}/lib

# lib/env: our environment files.
install-env:
	${BIN_MKDIR} ${ARGS_MKDIR} ${INSTALL_PREFIX}/env
.for i in ${DATA_COMMON} ${DATA} ${DATA_DEFAULT}
	${BIN_INSTALL} ${.OBJDIR}/${i} ${INSTALL_PREFIX}/env
.endfor

# installers/*, tools/*, utilities/*: our binary files.
install-bin:
	${BIN_INSTALL} ${INSTALL_FLAGS} ${.OBJDIR}/${PROG} ${INSTALL_PREFIX}/bin

# installers/*, producers/*, tools/*, utilities/*: our man pages.
install-man:
.for i in ${MAN}
	${BIN_MKDIR} ${ARGS_MKDIR} ${PREFIX}/man/man${i:E}
	${BIN_INSTALL} ${.CURDIR}/${i} ${PREFIX}/man/man${i:E}
.endfor

# lib/sys: our shared libraries
install-shlib:
	${BIN_INSTALL} ${.OBJDIR}/${SHLIB} ${INSTALL_PREFIX}/lib/sys

install-dir:
	for i in ${INSTALL_SUB}; do \
		${BIN_MKDIR} ${ARGS_MKDIR} ${INSTALL_PREFIX}/$$i; \
	done

#
# Hack; please fix
#
SED_WRAPPER_OPTS= -e "s%-INSTALL_PREFIX-%${INSTALL_PREFIX}%g"
install-wrapper:
	${BIN_MKDIR} ${ARGS_MKDIR} ${PREFIX}/bin
	${BIN_SED} ${SED_WRAPPER_OPTS} ${SRC_DIR}/src/tools/tcc/tcc.sh > \
		${PREFIX}/bin/tcc
	${BIN_CHMOD} +x ${PREFIX}/bin/tcc

.include "tendra.version.mk"
