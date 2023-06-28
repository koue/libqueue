#
LOCALBASE?=	/usr/local
PROGS=		queue_test

CFLAGS= 	-Werror \
		-I${.CURDIR}/../src

LDFLAGS+=	-L${.CURDIR}/../src

LDADD.queue_test=	-lqueue

MAN=
MK_DEBUG_FILES=	no
MAKEOBJDIR= .

# keep this empty otherwise installation fails
install:

test:
	./queue_test

.include <bsd.progs.mk>
