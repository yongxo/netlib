
#"this is a make edited by lay " 


 
CPP = g++
CC = gcc 
SHARED= -shared -o
FPIC= -fPIC -c

MYDIR = /mnt/hgfs/sharefile/RHPC_QT/netlib

MYSRC_DIR = $(MYDIR)/src

src_dir = src
build_dir = build

LIBS  = -lstdc++ -L"lib" -lpthread \
	-L"/usr/local/lib" \
	-lSockets \

INCS = -I"/usr/local/include/Sockets" \

CXXINCS = $(INCS)
BIN = main
CXXFLAGS = $(CXXINCS)
CFLAGS = $(INCS)
RM = rm -f

MYSRC_SOURCES = $(addprefix $(MYSRC_DIR)/, \
main.cpp)


MYSRC_OBJECTS=$(patsubst %.cpp,%.o,$(MYSRC_SOURCES))

LINKOBJ = 

$(BIN): $(MYSRC_OBJECTS)
	$(CPP) -g $(MYSRC_OBJECTS) -o  $@  $(LIBS)
$(MYSRC_OBJECTS):%.o:%.cpp 
	$(CPP) -c  $<  -o $@  $(CXXFLAGS)
.PHONY: clean
clean:
	$(RM) $(MYSRC_DIR)/*.o
