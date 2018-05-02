# CC=g++
# EXT = cpp
# CFLAGS=
# LDFLAGS=
# RM=/bin/rm
# MAKE=/usr/bin/make
# MAKEDEPEND=/usr/X11R6/bin/makedepend
# SRC = $(wildcard *.$(EXT))
# OBJ=$(subst .cpp,.o,$(SRC))

# SUBDIR= src Board Cases

# .SUFFIXES: .cpp
# .cpp.o:
# 	$(CC) -c $(CFLAGS) $<

# all:
# 	for i in $(SUBDIRS); do (cd $$i; $(MAKE) all); done
# 	$(MAKE) sokoban

# sokoban: $(OBJ)
# 	$(CC) -o $@ $(LDFLAGS) $^

# clean:
# 	$(RM) -f $(OBJ) core *~
# 	for i in $(SUBDIRS); do (cd $$i; $(MAKE) clean); done

# depend:
# 	$(MAKEDEPEND) -- $(CFLAGS) -- $(SRC)
# 	for i in $(SUBDIRS); do (cd $$i; $(MAKE) depend); done


# EXT = cpp
# CXX = g++
# EXEC = exe
 
# CXXFLAGS =
# LDFLAGS = 
 
 
# OBJDIR = obj
# SRC = $(wildcard *.$(EXT))
# OBJ = $(SRC:.$(EXT)=.o)
# OBJ := $(addprefix $(OBJDIR)/, $(OBJ))
 
# all: $(EXEC)
 
# $(EXEC): $(OBJ)
# 	@$(CXX) -o $@ $^ $(LDFLAGS)
 
# $(OBJDIR)/%.o: %.$(EXT)
# 	@$(CXX) -o $@ -c $< $(CXXFLAGS)
 
# clean:
# 	@rm -rf $(OBJDIR)/*.o
# 	@rm -f $(EXEC)


# CC = gcc
# CFLAGS = -W -Wall -g
# LDFLAGS = 
 
# SRC = $(wildcard *.c)
# OBJS = $(SRC:.c=.o)
# AOUT = prog
 
# all : $(AOUT) 
 
# prog : $(OBJS)
# 	$(CC) $(LDFLAGS) -o $@ $^
# %.o : %.c
# 	$(CC) $(CFLAGS) -o $@ -c $<
# clean :
# 	@rm *.o
# cleaner : clean
# 	@rm $(AOUT)

#-----Macros---------------------------------
CXX = g++
CXXFLAGS = 
 

#-----Final product----------------------
PRODUCT = sokoban
 

#-----File Location----------------------
SRCDST = src src/Board src/Board/Case
OBJDST = obj/
EXEDST = exe
 

#-----File List----------------------
SRC = $(foreach dir,$(SRCDST),$(wildcard $(dir)/*.cpp))
OBJ = $(addsuffix .o, $(basename $(foreach source,$(SRC),$(subst $(dir $(source)),$(OBJDST),$(source)))))
OBJ = $(addprefix obj/, $(addsuffix .o, $(basename $(SRC))))

#-----Base rules---------------------------------
obj/src/%.o : src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#-----Main rule---------------------------------
all: $(OBJ)
	$(CXX) $(CXXFLAGS) -o ${EXEDST}/${PRODUCT} $(OBJ)

#-----Other stuff----------------------------
depend:
	makedepend $(CXXFLAGS) -Y $(SRC)
 

clean:
	rm -f $(OBJ)
	rm -f ${EXEDST}/${PRODUCT}