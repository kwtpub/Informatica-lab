CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = src
OBJDIR = bin
TARGET = $(OBJDIR)/main

# Исходные файлы
SOURCES = $(SRCDIR)/main.c \
          $(SRCDIR)/untils/untils.c \
          $(SRCDIR)/sorts/bubbleSort/bubbleSort.c \
          $(SRCDIR)/sorts/insertionSort/insertionSort.c \
          $(SRCDIR)/sorts/selectSort/selectSort.c

# Объектные файлы
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Создание директорий для объектных файлов
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	@mkdir -p $(OBJDIR)
	$(CC) $(OBJECTS) -o $(TARGET)

# Сборка только main.c с untils.c (быстрая компиляция для тестирования)
quick: $(OBJDIR)/main.o $(OBJDIR)/untils/untils.o
	@mkdir -p $(OBJDIR)
	$(CC) $(OBJDIR)/main.o $(OBJDIR)/untils/untils.o -o $(TARGET)

# Очистка
clean:
	rm -rf $(OBJDIR)

# Пересборка
rebuild: clean $(TARGET)

.PHONY: clean rebuild quick

