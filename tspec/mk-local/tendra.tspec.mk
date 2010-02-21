# TenDRA make build infrastructure
#
# $Id$

.if !defined(_TENDRA_WORK_TSPEC_MK_)
_TENDRA_WORK_TSPEC_MK_=1

.include <tendra.base.mk>
.include <tendra.functions.mk>



TSPEC_TIOUT=	${OBJ_DIR}/share/TenDRA/include
TSPEC_TSOUT=	${OBJ_DIR}/share/TenDRA/src

TSPEC_FLAGS+=	-O${TSPEC_TIOUT}
TSPEC_FLAGS+=	-S${TSPEC_TSOUT}

ALL_APIS=	${BASE_APIS} ${EXT_APIS}


.for api in ${BASE_APIS}
${TSPEC_TIOUT}/${api}.api ${TSPEC_TSOUT}/${api}.api: ${TSPEC}
	@${ECHO} "==> Creating base API source for ${api}"
	${TSPEC} ${TSPEC_FLAGS} -I${BASE_DIR}/base ${api}
.endfor

.for api in ${EXT_APIS}
${TSPEC_TIOUT}/${api}.api ${TSPEC_TSOUT}/${api}.api: ${TSPEC}
	@${ECHO} "==> Creating extension API source for ${api}"
	${TSPEC} ${TSPEC_FLAGS} -I${BASE_DIR}/base -I${BASE_DIR}/extension ${api}
.endfor



#
# User-facing targets
#

all:: ${TSPEC} ${ALL_APIS:C/^/${TSPEC_TIOUT}\//g:C/$/.api/g} \
               ${ALL_APIS:C/^/${TSPEC_TSOUT}\//g:C/$/.api/g}


clean::


install:: all
	@${CONDCREATE} "${SHARE_DIR}/tspec"
	${INSTALL} -m 755 -d ${SHARE_DIR}/tspec
	${COPY} -R ${OBJ_DIR}/share/TenDRA ${SHARE_DIR}/tspec



.endif	# !defined(_TENDRA_WORK_TSPEC_MK_)