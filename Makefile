CC = g++
COPTFLAGS = -O3 -g

prim: Driver.o Graph.o Prim.o MinHeap.o AdjacencyList.o
	$(CC) $(COPTFLAGS) -o $@ $^

clean:
	rm -f core *.o *~ insert_test search_test edit_distance

# eof	
