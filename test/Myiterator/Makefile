OBJDIR := obj
CC = g++
OPTS = -O1
OFLAGS =  -g
CXXFLAGS =	-fopenmp -O2 -g -Wall -fmessage-length=0
CPPFILES = $(wildcard src/*.cpp)
OBJFILES = $(addprefix $(OBJDIR)/,$(patsubst %.cpp,%.o,$(notdir $(CPPFILES))))
EXECUTABLE = iter




all: $(EXECUTABLE)

iter: $(OBJFILES)
	$(CC) $(CXXFLAGS) $(OPTS) $(OFLAGS) $^ -o $@

obj/%.o: src/%.cpp
	mkdir -p ./obj
	$(CC) $(CXXFLAGS) $(OPTS) $(OFLAGS) -c -o $@ $<

#$(OBJFILES): | $(OBJDIR)

#$(OBJDIR):
#	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJFILES)
	rmdir $(OBJDIR)
	rm -f $(EXECUTABLE)
