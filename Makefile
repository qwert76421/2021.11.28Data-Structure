CC=g++
EXE=main.exe
OBJS=main.o Treap.o SortedArray.o SkipList.o

$(EXE) : $(OBJS) 
	$(CC) -o $(EXE) $(OBJS) 

%.o : %.cpp
	$(CC) -c -o $@ $< 

clean : 
	rm $(EXE) $(OBJS) 
