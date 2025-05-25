# Compilateur à utiliser
CXX = g++

# Drapeaux de compilation
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror

# Nom de l'exécutable final
TARGET = a.out

# Liste des fichiers sources C++
SRCS = $(wildcard *.cpp)

# Liste des fichiers objets correspondants
OBJS = $(SRCS:.cpp=.o)

# Liste des fichiers d'en-tête
HDRS = $(wildcard *.hpp)

# Règle par défaut : construire l'exécutable
all: $(TARGET)

# Règle pour lier les fichiers objets en un exécutable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Règle pour compiler les fichiers sources en fichiers objets
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
