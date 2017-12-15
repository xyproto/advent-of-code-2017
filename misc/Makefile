.PHONY: all opt extra testbuild test clang clangextra clangdebug debug run clean

clang ?= 0
extra ?= 0
debug ?= 0
opt ?= 0

ROOT_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

all:
	@test -f main.cpp \
	  && scons --file=${ROOT_DIR}/../misc/SConstruct -Q clang=${clang} extra=${extra} debug=${debug} opt=${opt} \
	  || scons --file=${ROOT_DIR}/../misc/SConstruct -Q testbuild clang=${clang} extra=${extra} debug=${debug} opt=${opt}

opt:
	@test -f main.cpp \
	  && scons --file=${ROOT_DIR}/../misc/SConstruct -Q opt=1 \
	  || scons --file=${ROOT_DIR}/../misc/SConstruct -Q opt=1

extra:
	@test -f main.cpp \
	  && scons --file=${ROOT_DIR}/../misc/SConstruct -Q extra=1 \
	  || scons --file=${ROOT_DIR}/../misc/SConstruct -Q testbuild extra=1

testbuild:
	@scons --file=${ROOT_DIR}/../misc/SConstruct -Q testbuild clang=${clang} extra=${extra} debug=${debug} opt=${opt}

test:
	@scons --file=${ROOT_DIR}/../misc/SConstruct -Q test clang=${clang} extra=${extra} debug=${debug} opt=${opt}

clang:
	@test -f main.cpp \
	  && scons --file=${ROOT_DIR}/../misc/SConstruct -Q clang=1 \
	  || scons --file=${ROOT_DIR}/../misc/SConstruct -Q testbuild clang=1

clangextra:
	@test -f main.cpp \
	  && scons --file=${ROOT_DIR}/../misc/SConstruct -Q clang=1 extra=1 \
	  || scons --file=${ROOT_DIR}/../misc/SConstruct -Q testbuild clang=1 extra=1

clangdebug:
	@test -f main.cpp \
	  && scons --file=${ROOT_DIR}/../misc/SConstruct -Q clang=1 debug=1 \
	  || scons --file=${ROOT_DIR}/../misc/SConstruct -Q testbuild clang=1 debug=1

debug:
	@test -f main.cpp \
	  && scons --file=${ROOT_DIR}/../misc/SConstruct -Q debug=1 \
	  || scons --file=${ROOT_DIR}/../misc/SConstruct -Q testbuild debug=1

run:
	@scons --file=${ROOT_DIR}/../misc/SConstruct -Q run clang=${clang} extra=${extra} debug=${debug} opt=${opt}

clean:
	@scons --file=${ROOT_DIR}/../misc/SConstruct -Q clean
