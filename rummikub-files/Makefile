PRG=gcc0.exe

GCC=g++
GCCFLAGS=-Wall -Werror -Wextra -std=c++11 -pedantic -Wconversion -O2 -Wno-unused-result

OBJECTS0=rummikub.cpp
DRIVER0=driver.cpp

VALGRIND_OPTIONS=-q --leak-check=full
DIFF_OPTIONS=-y --strip-trailing-cr --suppress-common-lines -b

gcc0:
	$(GCC) -o $(PRG) $(DRIVER0) $(OBJECTS0) $(GCCFLAGS)
0 1 2 3:
	#echo "running test$@"
	#@echo "should run in less than 200 ms"
	@echo "should run in less than 200 ms"
	./$(PRG) $@ >studentout$@
	diff out$@ studentout$@ $(DIFF_OPTIONS) 
mem0 mem1 mem2 mem3:
	@echo "should run in less than 3000 ms"
	valgrind $(VALGRIND_OPTIONS) ./$(PRG) $(subst mem,,$@) 1>/dev/null 2>difference$@
	@echo "lines after this are memory errors"; cat difference$@
clean : 
	rm *.exe student* difference*
