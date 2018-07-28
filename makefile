CC = g++
DEPS = main.cpp cam.h debugTimer.h disp.cpp disp.h math3d.h mesh.cpp mesh.h obj_loader.cpp obj_loader.h shader.cpp shader.h stb_image.c stb_image.h texture.cpp texture.h transform.h util.h obj.h obj.cpp 
GL = -lGL -lGLU -lGLEW -lglut -lSDL2
STD = -std=c++11

RELEASE = bin/cmder

make: main.cpp
	 $(CC) $(DEPS) $(GL) $(STD) -o $(RELEASE)

clean:
	rm *.out


# WORKDIR = `pwd`

# CC = gcc
# CXX = g++ -std=c++11
# AR = ar
# LD = g++
# WINDRES = windres

# INC =
# CFLAGS = -Wall
# RESINC =
# LIBDIR =
# LIB = -lSDL2 -lGLEW -lGL
# LDFLAGS =

# INC_DEBUG = $(INC)
# CFLAGS_DEBUG = $(CFLAGS) -g
# RESINC_DEBUG = $(RESINC)
# RCFLAGS_DEBUG = $(RCFLAGS)
# LIBDIR_DEBUG = $(LIBDIR)
# LIB_DEBUG = $(LIB)
# LDFLAGS_DEBUG = $(LDFLAGS)
# OBJDIR_DEBUG = obj/Debug
# DEP_DEBUG =
# OUT_DEBUG = bin/cmder

# INC_RELEASE = $(INC)
# CFLAGS_RELEASE = $(CFLAGS) -O2
# RESINC_RELEASE = $(RESINC)
# RCFLAGS_RELEASE = $(RCFLAGS)
# LIBDIR_RELEASE = $(LIBDIR)
# LIB_RELEASE = $(LIB)
# LDFLAGS_RELEASE = $(LDFLAGS) -s
# OBJDIR_RELEASE = obj/Release
# DEP_RELEASE =
# OUT_RELEASE = bin/Release/OpenGLTest

# OBJ_DEBUG = $(OBJDIR_DEBUG)/texture.o $(OBJDIR_DEBUG)/stb_image.o $(OBJDIR_DEBUG)/shader.o $(OBJDIR_DEBUG)/obj_loader.o $(OBJDIR_DEBUG)/mesh.o $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/display.o

# OBJ_RELEASE = $(OBJDIR_RELEASE)/texture.o $(OBJDIR_RELEASE)/stb_image.o $(OBJDIR_RELEASE)/shader.o $(OBJDIR_RELEASE)/obj_loader.o $(OBJDIR_RELEASE)/mesh.o $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/display.o

# all: debug release

# clean: clean_debug clean_release

# before_debug:
# 	test -d bin/Debug || mkdir -p bin/Debug
# 	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

# after_debug:

# debug: before_debug out_debug after_debug

# out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
# 	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

# $(OBJDIR_DEBUG)/texture.o: texture.cpp
# 	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c texture.cpp -o $(OBJDIR_DEBUG)/texture.o

# $(OBJDIR_DEBUG)/stb_image.o: stb_image.c
# 	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c stb_image.c -o $(OBJDIR_DEBUG)/stb_image.o

# $(OBJDIR_DEBUG)/shader.o: shader.cpp
# 	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c shader.cpp -o $(OBJDIR_DEBUG)/shader.o

# $(OBJDIR_DEBUG)/obj_loader.o: obj_loader.cpp
# 	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c obj_loader.cpp -o $(OBJDIR_DEBUG)/obj_loader.o

# $(OBJDIR_DEBUG)/mesh.o: mesh.cpp
# 	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c mesh.cpp -o $(OBJDIR_DEBUG)/mesh.o

# $(OBJDIR_DEBUG)/main.o: main.cpp
# 	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

# $(OBJDIR_DEBUG)/display.o: disp.cpp
# 	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c disp.cpp -o $(OBJDIR_DEBUG)/display.o

# $(OBJDIR_RELEASE)/obj.o: obj.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c obj.cpp -o $(OBJDIR_RELEASE)/obj.o

# clean_debug:
# 	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
# 	rm -rf bin/Debug
# 	rm -rf $(OBJDIR_DEBUG)

# before_release:
# 	test -d bin/Release || mkdir -p bin/Release
# 	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

# after_release:

# release: before_release out_release after_release

# out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
# 	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

# $(OBJDIR_RELEASE)/texture.o: texture.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c texture.cpp -o $(OBJDIR_RELEASE)/texture.o

# $(OBJDIR_RELEASE)/stb_image.o: stb_image.c
# 	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c stb_image.c -o $(OBJDIR_RELEASE)/stb_image.o

# $(OBJDIR_RELEASE)/shader.o: shader.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c shader.cpp -o $(OBJDIR_RELEASE)/shader.o

# $(OBJDIR_RELEASE)/obj_loader.o: obj_loader.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c obj_loader.cpp -o $(OBJDIR_RELEASE)/obj_loader.o

# $(OBJDIR_RELEASE)/mesh.o: mesh.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c mesh.cpp -o $(OBJDIR_RELEASE)/mesh.o

# $(OBJDIR_RELEASE)/main.o: main.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

# $(OBJDIR_RELEASE)/display.o: disp.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c disp.cpp -o $(OBJDIR_RELEASE)/display.o

# $(OBJDIR_RELEASE)/obj.o: obj.cpp
# 	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c obj.cpp -o $(OBJDIR_RELEASE)/obj.o

# clean_release:
# 	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
# 	rm -rf bin/Release
# 	rm -rf $(OBJDIR_RELEASE)

# .PHONY: before_debug after_debug clean_debug before_release after_release clean_release

