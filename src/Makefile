#
MK_PROFILE=	no
LOCALBASE?=	/usr/local
LIB=		queue
LIBDIR=		${LOCALBASE}/lib
INCSDIR=	${LOCALBASE}/include
CFLAGS+=	-Wall -Wstrict-prototypes -fPIC -I${.CURDIR}
SRCS=		file.c queue.c libqueue.h
INCS=		libqueue.h
NO_OBJ=		yes

.include <bsd.lib.mk>
