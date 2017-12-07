.PHONY: all clean run test testbuild

all:
	@test -f main.cpp && scons --file=../misc/SConstruct -Q || (scons --file=../misc/SConstruct -Q testbuild)

testbuild:
	@scons --file=../misc/SConstruct -Q testbuild

test:
	@scons --file=../misc/SConstruct -Q test

run:
	@scons --file=../misc/SConstruct -Q run

clean:
	@scons --file=../misc/SConstruct -Q clean


