catch: main.o analyse.o construct_protocol.o str.o protocol_print.o Instrument.o
	gcc -IC:/Users/28254/Desktop/file/Program/npcap-sdk-1.11/Include/** -LC:/Users/28254/Desktop/file/Program/npcap-sdk-1.11/Lib/x64 -o catch main.o analyse.o construct_protocol.o  str.o protocol_print.o Instrument.o -lwpcap

protocol_print.o: ./Analyse/protocol_print.c ./type/defn.h ./type/protocol.h ./type/variety.h
	gcc -c ./Analyse/protocol_print.c 

main.o: main.c ./type/defn.h 
	gcc  -c main.c 



construct_protocol.o: ./Construct/construct_protocol.c ./type/defn.h ./type/protocol.h ./type/variety.h
	gcc -c  ./Construct/construct_protocol.c 

analyse.o: ./Analyse/analyse.c ./type/defn.h ./type/protocol.h ./type/variety.h
	gcc -c  ./Analyse/analyse.c 

Instrument.o: ./Instrument/Instrument.c ./type/defn.h
	gcc -c ./Instrument/Instrument.c
	
str.o: ./STRING/str.c ./type/defn.h
	gcc -c ./STRING/str.c 










clean:
	del a.out main.o analyse.o construct_protocol.o str.o catch protocol_print.o

