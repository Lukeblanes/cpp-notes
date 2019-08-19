
target:
	g++ example2.cpp -O3 -g -o a.out

nonOp:
	g++ example2.cpp -g -o a.out

#Instructions with tools

#time_ex:
#	time ./a.out

#callgrind:
#	valgrind --tool=callgrind --dump-line=yes ./a.out

#callgrind_read:
#	callgrind_annotate --auto=yes callgrind.out.*

cachegrind:
	valgrind --tool=cachegrind ./a.out

# more info on cachegrind output
grind_annotate:
	cg_annotate --auto=yes cachegrind.out