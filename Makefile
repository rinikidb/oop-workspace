# Compiler
CC = g++

# Compiler flags
#CFLAGS = -std=c++17 -Wall -Wextra -Werror
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system 

# Source files
SRCS = main.cpp Player.cpp LevelManager.cpp UIManager.cpp AudioManager.cpp LevelSelectionScreen.cpp Slicer.cpp Food.cpp PowerUp.cpp Obstacle.cpp GameOverScreen.cpp StartScreen.cpp Button.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = game

# Build rule
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(EXEC) $(OBJS)