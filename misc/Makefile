.PHONY: all clean run test testbuild

all:
	@test -f main.cpp && scons --file=../misc/SConstruct -Q || (scons --file=../misc/SConstruct -Q testbuild)

testbuild:
	@scons --file=../misc/SConstruct -Q testbuild

test:
	@scons --file=../misc/SConstruct -Q extra=1 test

clang:
	@test -f main.cpp && scons --file=../misc/SConstruct -Q clang=1 || (scons --file=../misc/SConstruct -Q testbuild clang=1)

debug:
	@test -f main.cpp && scons --file=../misc/SConstruct -Q debug=1 || (scons --file=../misc/SConstruct -Q testbuild debug=1)

run:
	@scons --file=../misc/SConstruct -Q run extra=1

clean:
	@scons --file=../misc/SConstruct -Q clean


