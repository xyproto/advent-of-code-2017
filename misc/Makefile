.PHONY: all clean run test testbuild

clang ?= 0
extra ?= 0
debug ?= 0

all:
	@test -f main.cpp \
	  && scons --file=../misc/SConstruct -Q clang=${clang} extra=${extra} debug=${debug} \
	  || scons --file=../misc/SConstruct -Q testbuild clang=${clang} extra=${extra} debug=${debug}

extra:
	@test -f main.cpp \
	  && scons --file=../misc/SConstruct -Q extra=1 \
	  || scons --file=../misc/SConstruct -Q testbuild extra=1

testbuild:
	@scons --file=../misc/SConstruct -Q extra=1 testbuild clang=${clang} extra=${extra} debug=${debug}

test:
	@scons --file=../misc/SConstruct -Q test clang=${clang} extra=${extra} debug=${debug}

clang:
	@test -f main.cpp \
	  && scons --file=../misc/SConstruct -Q clang=1 \
	  || scons --file=../misc/SConstruct -Q testbuild clang=1

clangextra:
	@test -f main.cpp \
	  && scons --file=../misc/SConstruct -Q clang=1 extra=1 \
	  || scons --file=../misc/SConstruct -Q testbuild clang=1 extra=1

clangdebug:
	@test -f main.cpp \
	  && scons --file=../misc/SConstruct -Q clang=1 debug=1 \
	  || scons --file=../misc/SConstruct -Q testbuild clang=1 debug=1

debug:
	@test -f main.cpp \
	  && scons --file=../misc/SConstruct -Q debug=1 \
	  || scons --file=../misc/SConstruct -Q testbuild debug=1

run:
	@scons --file=../misc/SConstruct -Q run clang=${clang} extra=${extra} debug=${debug}

clean:
	@scons --file=../misc/SConstruct -Q clean
