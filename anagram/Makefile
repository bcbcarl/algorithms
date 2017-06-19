CXXFLAGS := -std=c++11 -O3
RM := rm -rf

.PHONY: all
all: build
	@$(CURDIR)/main

.PHONY: build
build: main.cc
	@$(CXX) $(CXXFLAGS) -S $<
	@$(CXX) main.s -o main

.PHONY: clean
clean:
	@$(RM) main main.s main.dSYM
