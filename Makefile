#-----------------------------------------------------------------------
#Copyright (C) 2021 by Shriram Ravindranathan
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#You should have received a copy of the GNU General Public License
#along with this program. If not, see <https://www.gnu.org/licenses/>.
#-----------------------------------------------------------------------

#--------------------------------------------------------------------
#
# USAGE: make build // for building the whole project
#
# OR: make targetname
#
#--------------------------------------------------------------------

INCLUDES = -I ./include/

SOURCES = ./src/main.c\
		  ./src/filePrint.c

CC = gcc
LD = -L ./
LDFLAGS = -Wl
CFLAGS = -Werror\
		 -Wall\
		 -g\
		 -O0
CPPFLAGS = $(INCLUDES)

# GENERATE ALL THE COMPILED OBJECT FILES
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# GENERATE THE OUTPUT FILE EXECUTABLE
piglatinize.out : $(SOURCES:.c=.o)
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) -L ./ -o $@

.PHONY:build
build: piglatinize.out

.PHONY: compile-all 
compile-all: $(SOURCES:.c=.o)

.PHONY: clean
clean:
	rm -rf ./src/*.o ./src/*.i ./src/*.asm ./*.out ./*.map ./src/*.d


