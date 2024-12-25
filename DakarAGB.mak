PROJ = DakarAGB

cflags = -I "c:\dev\dakaragb"
SRC = $(PROJ).dsp
args = -v -w -g -l"c:\agb\lib\libagbsyscall.a" -p"c:\PROGRA~1\CYGNUS\THUMBELF-000512\H-I686-CYGWIN32\BIN" -g -I"c:\agb\lib"
bongo = -I"c:\PROGRA~1\CYGNUS\THUMBELF-000512\H-I686-CYGWIN32\lib\gcc-lib\thumb-elf\2.9-arm-000512"
cc = gbamake

$(PROJ)._bin:
	$(cc) $(args) $(SRC)

