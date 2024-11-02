#
# Copyright (C) 2024 Ramon Asuncion <ramon@b1t.dev>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation;
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

CC=gcc
CFLAGS=-I./include -std=gnu99 -Wall -g #-DDEBUG
LDFLAGS=

INC=./include
SRC=./src
OBJ=./obj
DOC=./doc
BIN=./bin

vpath %.h ./include
vpath %.c ./src

EXECS = avl_test

all: mkpaths $(EXECS)

mkpaths:
	@ mkdir -p $(OBJ)
	@ mkdir -p $(BIN)
doc:
	doxygen

$(OBJ)/%.o: $(SRC)/%.c $(INC)/avl_tree.h
	$(CC) $(CFLAGS) -c $< -o $@

avl_test: $(OBJ)/avl_test.o $(OBJ)/avl_tree.o
	@ mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(OBJ)/avl_test.o $(OBJ)/avl_tree.o -o $(BIN)/$@ $(LDFLAGS)

.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* core* *~ $(SRC)/*~ $(INC)/*~ $(DOC)/*

