# Executable names:
EXE = finalproj
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o readFromFile.o graph.o BFS.o GridTraversal.o 


# mp_traverals specific stuff
CLEAN_RM = test finalproj map_graph.png map_path.png map_trans_graph.png

# Generated files


# Use the cs225 makefile template:
include cs225/make/cs225.mk

