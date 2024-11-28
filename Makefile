# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -I./src/structures/lists

# Diretórios
BASEDIR = $(shell cd)

SRCDIR = $(BASEDIR)
OBJDIR = $(SRCDIR)\obj
BINDIR = $(SRCDIR)\bin

# Arquivos principais
TARGET = $(BINDIR)/main.exe
LIBRARY = $(BINDIR)/libstructures.a

# Arquivos-fonte e objetos
LIB_SOURCES = $(SRCDIR)/structures/lists/linked_list.c
LIB_OBJECTS = $(OBJDIR)/linked_list.o
MAIN_SOURCE = $(SRCDIR)/main.c
MAIN_OBJECT = $(OBJDIR)/main.o

# Regras principais
all: create_dirs $(TARGET)

# Regra para criar diretórios
create_dirs:
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	@if not exist $(BINDIR) mkdir $(BINDIR)

# Regra para compilar o executável principal
$(TARGET): $(MAIN_OBJECT) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJECT) -L$(BINDIR) -lstructures

# Regra para compilar a biblioteca estática
$(LIBRARY): $(LIB_OBJECTS)
	ar rcs $@ $^

# Regra específica para compilar linked_list.o
$(OBJDIR)/linked_list.o: $(SRCDIR)/structures/lists/linked_list.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra específica para compilar main.o
$(OBJDIR)/main.o: $(MAIN_SOURCE)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza de arquivos gerados
clean:
	@if exist $(OBJDIR) rmdir /s /q $(OBJDIR)
	@if exist $(BINDIR) rmdir /s /q $(BINDIR)

# Regra para debug dos caminhos
debug:
	@echo "LIB_SOURCES = $(LIB_SOURCES)"
	@echo "LIB_OBJECTS = $(LIB_OBJECTS)"
	@echo "MAIN_SOURCE = $(MAIN_SOURCE)"
	@echo "MAIN_OBJECT = $(MAIN_OBJECT)"
