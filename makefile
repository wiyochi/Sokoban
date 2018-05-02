CXX = g++
CXXFLAGS = 
 

#-----Final product----------------------
PRODUCT = sokoban
 

#-----File Location----------------------
SRCDST = src src/Board src/Board/Case src/Level
OBJDST = obj/
EXEDST = exe
 

#-----File List----------------------
SRC = $(foreach dir,$(SRCDST),$(wildcard $(dir)/*.cpp))
OBJPATH = $(addsuffix .o, $(basename $(foreach source,$(SRC),$(subst $(dir $(source)),$(OBJDST),$(source)))))
OBJ = $(addsuffix .o, $(basename $(SRC)))
objet = 

#-----Base rules---------------------------------
%.o : %.cpp
	$(eval objet = $(subst $(dir $@),$(OBJDST),$@))
	$(CXX) $(CXXFLAGS) -c $< -o $(objet)

#-----Main rule---------------------------------
all: $(OBJ)
	$(CXX) $(CXXFLAGS) -o ${EXEDST}/${PRODUCT} $(OBJPATH)

#-----Other stuff----------------------------
depend:
	makedepend $(CXXFLAGS) -Y $(SRC)
 

clean:
	rm -f $(OBJ)
	rm -f ${EXEDST}/${PRODUCT}