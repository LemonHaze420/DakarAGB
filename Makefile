_AGBDIR = C://agb/
.SFILES	=	start.s 
.CFILES	=	Dakar.c \
			Dakar_DataEvents.c \
			Dakar_Logic.c Dakar_LogicGame.c Dakar_LogicGameRender.c Dakar_LogicMenu.c \
			Graphics.c Sound.c Controls.c Interrupts.c Platform.c \
			vector.c matrix.c car.c fixed.c \
			Globals.c share.c \
			Debug.c	\
                        alphaset1.c mainmenu.c track.c RawData.c trackdata.c Map.c

.OFILES	=	$(.SFILES:.s=.o) $(.CFILES:.c=.o)
.AFILES	=	
ASFLAGS	=	-I$(_AGBDIR)/include -mthumb-interwork
CFLAGS	=	-g -O2 -D GRAPHICS_SUPPORT_MODE_0 -D GRAPHICS_SUPPORT_MODE_4 -I$(_AGBDIR)/include -mthumb-interwork \
                -nostdlib -Wall # -save-temps

LDFLAGS	 +=	-Map $(MAPFILE) -nostartfiles \
		-Ttext 0x08000000 -Tbss 0x03000000 \
	#	-L$(_AGBDIR)lib/ -l isagbprn -l agbsyscall \
		-Tlnkscript 
DEPENDFILE	=	Makedepend
MAPFILE		=	DakarAGB.map
TARGET_ELF	=	DakarAGB.elf
TARGET_BIN	=	DakarAGB.bin

$(TARGET_BIN): $(TARGET_ELF)
	objcopy -v -O binary $< $@

$(TARGET_ELF): $(.OFILES) Makefile $(.AFILES) $(DEPENDFILE)
	@echo > $(MAPFILE)
	$(CC) -g -o $@ $(.OFILES) -Wl,$(LDFLAGS)

.PHONY: all clean depend data

all:	clean depend data $(TARGET_BIN)

clean_data:
	$(foreach .ADIR_TMP, $(dir $(.AFILES)), make -C $(.ADIR_TMP) clean;)

depend:
	$(CC) $(CFLAGS) -M $(.CFILES) > $(DEPENDFILE)

$(DEPENDFILE): 
	$(CC) $(CFLAGS) -M $(.CFILES) > $(DEPENDFILE)

.SUFFIXES: .s .c .o .a

include Gasdepend
include $(DEPENDFILE)
data:
	$(foreach .ADIR_TMP, $(dir $(.AFILES)), make -C $(.ADIR_TMP);)

