CXX := g++
CXXFLAGS := -Wall -g -std=c++20 -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations
SRCDIR := src
OBJDIR := obj

# list of source files
SRCS := $(wildcard $(SRCDIR)/*.cpp)

# list of object files
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# required libraries
LIBS := -lncurses

.PHONY: all clean

all: agduria

# link object files to target executable
agduria: $(OBJS)
	$(CXX) $(LIBS) -o $@ $^

# compile files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p '$(@D)'
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f agduria
	rm -f $(OBJDIR)/*.o

