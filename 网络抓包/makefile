OBJECT = main.o protocol_print.o analyse.o build.o construct_protocol.o init.o send.o \
terminal.o common.o data_link_opt.o protocol_up_type_opt.o arp_opt.o
 
catch: $(OBJECT)
	gcc -IC:/Users/28254/Desktop/file/Program/npcap-sdk-1.11/Include/** -LC:/Users/28254/Desktop/file/Program/npcap-sdk-1.11/Lib/x64  -o catch $(OBJECT) -lwpcap

main.o: main.c ./type/defn.h 
	gcc  -c main.c 

protocol_print.o: ./Analyse/protocol_print.c ./type/init_variety.h
	gcc -c ./Analyse/protocol_print.c 

analyse.o: ./Analyse/analyse.c ./type/init_variety.h
	gcc -c  ./Analyse/analyse.c 

#Build
build.o: ./Build/build.c ./type/init_variety.h
	gcc -c ./Build/build.c
#Cmd
arp_opt.o: ./Cmd/arp_opt.c ./type/init_variety.h
	gcc -c ./Cmd/arp_opt.c

#Construct
construct_protocol.o: ./Construct/construct_protocol.c ./type/init_variety.h
	gcc -c  ./Construct/construct_protocol.c 

#Init
init.o: ./Init/init.c ./type/init_variety.h
	gcc -c ./Init/init.c

#Send
send.o: ./Send/send.c ./type/init_variety.h
	gcc -c ./Send/send.c 

#Terminal
terminal.o: ./Terminal/terminal.c ./type/init_variety.h
	gcc -c ./Terminal/terminal.c

	
#Tool
common.o: ./Tool/common.c ./type/init_variety.h
	gcc -c ./Tool/common.c 

data_link_opt.o: ./Tool/data_link_opt.c ./type/init_variety.h
	gcc -c ./Tool/data_link_opt.c

protocol_up_type_opt.o: ./Tool/protocol_up_type_opt.c ./type/init_variety.h
	gcc -c ./Tool/protocol_up_type_opt.c 


clean:
	del $(OBJECT) catch

