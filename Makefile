ROOTCFLAGS    = $(shell root-config --cflags)
ROOTGLIBS     = $(shell root-config --glibs)

#RFCFLAGS    = $(shell restframes-config --cxxflags)
#RFGLIBS     = $(shell restframes-config --libs)

CXX            = g++

#CXXFLAGS       = -fPIC -Wall -O3 -g
CXXFLAGS       = $(filter-out -stdlib=libc++ -pthread , $(ROOTCFLAGS))
#CXXFLAGS       += $(filter-out -stdlib=libc++ -pthread , $(RFCFLAGS))

GLIBS          = $(filter-out -stdlib=libc++ -pthread , $(ROOTGLIBS))
#GLIBS         += $(filter-out -stdlib=libc++ -pthread , $(RFGLIBS))


INCLUDEDIR       = ./include/
SRCDIR           = ./src/
CXX	         += -I$(INCLUDEDIR) -I.
OUTOBJ	         = ./obj/

CC_FILES := $(wildcard src/*.cc)
HH_FILES := $(wildcard include/*.hh)
OBJ_FILES := $(addprefix $(OUTOBJ),$(notdir $(CC_FILES:.cc=.o)))

all: MakeReducedTree.x 

MakeReducedTree.x:  $(SRCDIR)MakeReducedTree.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o MakeReducedTree.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch MakeReducedTree.x

$(OUTOBJ)%.o: src/%.cc include/%.hh
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OUTOBJ)*.o 
	rm -f *.x
