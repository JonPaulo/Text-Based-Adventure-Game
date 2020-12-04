#source: https://oregonstate.instructure.com/courses/1719543/pages/lecture-makefiles?module_item_id=18712398

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGs += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -w

SRCS = main.cpp game.cpp item.cpp space.cpp car.cpp garage.cpp room.cpp yard.cpp outside.cpp store.cpp
 
HEADERS = game.hpp item.hpp space.hpp

OBJS = main.o

output: ${SRCS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${SRCS} -o output

${OBJS}: ${SRCS} 
	${CXX} ${CXXFLAGS} -c $(@: .o = .cpp)

clean:
	rm output
