CXXFLAGS += -MMD -MP
CXXFLAGS += -Isrc -Isrc/lib -std=c++11 -O3 -W -Wall -Wextra -Werror -g

all_srcs := $(shell find src -name *.cpp)
lib_srcs := $(shell find src/lib -name *.cpp)
app_srcs := $(shell find src/apps -name *.cpp)
tst_srcs := $(shell find src/test -name *.cpp)

all   : test apps
clean : ; @rm -rf obj
apps  : $(app_srcs:src/%.cpp=obj/%)
test  : obj/test/main ; @$<

-include $(all_srcs:src/%.cpp=obj/%.d)
.PRECIOUS : obj/%.o
	
obj/test/main : $(tst_srcs:src/%.cpp=obj/%.o)
obj/lib.a     : $(lib_srcs:src/%.cpp=obj/%.o) ; @ar rcs $@ $^
obj/%.o       : src/%.cpp ; @mkdir -p $(dir $@) ; $(COMPILE.cpp) $(OUTPUT_OPTION) $<
obj/%         : obj/%.o obj/lib.a ; @$(LINK.cpp) $(OUTPUT_OPTION) $^ obj/lib.a $(LDLIBS)