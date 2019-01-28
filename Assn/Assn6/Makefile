VERSION = -std=c++11
CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(DEBUG)
LFLAGS = -Wall $(VERSION) $(DEBUG)

INCS = Sequence.h
SRCS = Sequence.cpp \
	testComplex.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = testComplex

all: $(SRCS) $(EXEC)

# To make an object from source
#.cpp.o:
%.o:%.cpp $(INCS)
	$(CXX) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $@

# for Windows
clean:
	del *.o  $(EXEC).exe
	@echo clean done

# for UNIX / Linux
#remove:
#	\rm -f *.o  $(EXEC)
#	@echo clean done
