NAME           = functionwithparameters

PHP_CONFIG     = php-config

CPP            = g++
CPP_FLAGS      = -Wall -c -I. -O2 -std=c++11

CP             = cp -f
RM             = rm -f

PREFIX         = /usr
LIBRARY_DIR    = $(shell ${PHP_CONFIG} --extension-dir)
PHP_CONFIG_DIR = $(shell ${PHP_CONFIG} --ini-dir)

LD             = g++
LD_FLAGS       = -Wall -shared -O2

EXTENSION      = ${NAME}.so
PHPINIFILE     = 30-${NAME}.ini

SOURCES        = $(wildcard *.cpp)
OBJECTS        = $(SOURCES:%.cpp=%.o)

.PHONY: all clean install uninstall ${OBJECTS} ${EXTENSION}

all: ${OBJECTS} ${EXTENSION}

${OBJECTS}:
	${CPP} ${CPP_FLAGS} -fpic -o $@ ${@:%.o=%.cpp}

${EXTENSION}: ${OBJECTS}
	${LD} ${LD_FLAGS} -o $@ ${OBJECTS} -lphpcpp

clean:
	${RM} *.obj *~* ${OBJECTS} ${EXTENSION}

install: ${EXTENSION}
	${CP} ${EXTENSION} ${LIBRARY_DIR}
	${CP} ${PHPINIFILE}	${PHP_CONFIG_DIR}

uninstall:
	${RM} ${LIBRARY_DIR}/${EXTENSION}
	${RM} ${PHP_CONFIG_DIR}/${PHPINIFILE}
