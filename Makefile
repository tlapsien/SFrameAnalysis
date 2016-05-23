# Package information
LIBRARY = Analysis
OBJDIR  = obj
DEPDIR  = $(OBJDIR)/dep
SRCDIR  = src
INCDIR  = include



USERCXXFLAGS := -g

#INCLUDES += -I$(LHAPDFDIR)/include
#INCLUDES += -I/nfs/dust/cms/user/marchesi/LHAPDF/install/include/
INCLUDES += -I$(FASTJETDIR)/include
INCLUDES += -I$(FASTJETDIR)/../include
INCLUDES += -I$(FASTJETDIR)/include/contribs/RecursiveTools
USERLDFLAGS += $(shell root-config --libs) -lMinuit
USERLDFLAGS +=  /nfs/dust/cms/user/tlapsien/fastjet-install/lib/libRecursiveTools.a
USERLDFLAGS +=  /nfs/dust/cms/user/tlapsien/fastjet-install/lib/libJetsWithoutJets.a
USERLDFLAGS +=  /nfs/dust/cms/user/tlapsien/fastjet-install/lib/libEnergyCorrelator.a
USERLDFLAGS +=  /nfs/dust/cms/user/tlapsien/fastjet-install/lib/libVariableR.a	
USERLDFLAGS +=  /nfs/dust/cms/user/tlapsien/fastjet-install/lib/libClusteringVetoPlugin.a
USERLDFLAGS +=  /nfs/dust/cms/user/tlapsien/fastjet-install/lib/libHHTopTagger.a


include $(SFRAME_DIR)/SFrameTools/Makefile.defs
