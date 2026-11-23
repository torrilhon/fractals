# ---------------------------------------------------------------------------
VERSION = BCB.01
# ---------------------------------------------------------------------------
!ifndef BCB
BCB = $(MAKEDIR)\..
!endif
# ---------------------------------------------------------------------------
PROJECT = Fraktal.exe
OBJFILES = Fraktal.obj FrakMain.obj Frak1.obj FrakTrans.obj
RESFILES = Fraktal.res
RESDEPEN = $(RESFILES) FrakMain.dfm FrakTrans.dfm
LIBFILES =
DEFFILE =
# ---------------------------------------------------------------------------
CFLAG1 = -O2 -O-S -Hc -w -k- -r -vi -c -a4 -b- -w-par -w-inl -Vx -Ve -x 
CFLAG2 = -I$(BCB)\bin;$(BCB)\include;$(BCB)\include\vcl;. \
   -H=$(BCB)\lib\vcl.csm 
PFLAGS = -U$(BCB)\bin;$(BCB)\lib\obj;$(BCB)\lib \
   -I$(BCB)\bin;$(BCB)\include;$(BCB)\include\vcl;. \
   -AWinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE -$L- \
   -$D- -JPHNV -M     
RFLAGS = -i$(BCB)\bin;$(BCB)\include;$(BCB)\include\vcl;. 
LFLAGS = -L$(BCB)\bin;$(BCB)\lib\obj;$(BCB)\lib -aa -Tpe -x -V4.0

IFLAGS = 
LINKER = ilink32
# ---------------------------------------------------------------------------
ALLOBJ = c0w32.obj $(OBJFILES)
ALLRES = $(RESFILES)
ALLLIB = $(LIBFILES) vcl.lib import32.lib cp32mt.lib 
# ---------------------------------------------------------------------------
.autodepend

$(PROJECT): $(OBJFILES) $(RESDEPEN)
    $(BCB)\BIN\$(LINKER) @&&!
    $(LFLAGS) +
    $(ALLOBJ), +
    $(PROJECT),, +
    $(ALLLIB), +
    $(DEFFILE), +
    $(ALLRES) 
!

.pas.hpp:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.pas.obj:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.cpp.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $* 

.c.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $**

.rc.res:
    $(BCB)\BIN\brcc32 $(RFLAGS) $<
#-----------------------------------------------------------------------------
