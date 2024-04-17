COMPILER := arm-none-eabi-gcc.exe

.PHONY = clean system_Musca-B1.o startup_Musca-B1.o main.o all

clean:
	del /F /Q .\Debug\*.*
system_Musca-B1.o:
	$(COMPILER) -Wall -mcpu=cortex-m33 -mfloat-abi=soft -gdwarf-2 -g -c ./Source/system_Musca-B1.c -I./Include -I./../../CMSIS/Core/Include -Wa,-adhlns=./Debug/system_Musca-B1.lst -o ./Debug/system_Musca-B1.o
startup_Musca-B1.o:
	$(COMPILER) -Wall -mcpu=cortex-m33 -mfloat-abi=soft -gdwarf-2 -g -c ./Source/startup_Musca-B1.c -I./Include -I./../../CMSIS/Core/Include -Wa,-adhlns=./Debug/startup_Musca.lst -o ./Debug/startup_Musca-B1.o
main.o:
	$(COMPILER) -Wall -mcpu=cortex-m33 -mfloat-abi=soft -gdwarf-2 -g -c ./Source/main.c -I./Include -I./../CMSIS/Core/Include -Wa,-adhlns=./Debug/main.lst -o ./Debug/main.o
all: system_Musca-B1.o startup_Musca-B1.o main.o
	$(COMPILER) ./Debug/main.o ./Debug/startup_Musca-B1.o ./Debug/system_Musca-B1.o -Wall -mcpu=cortex-m33 -O0 -g --specs=nosys.specs -T ./Linker_script/GNU/gnu_linker.ld -Wl,-Map,./Debug/Musca_bare.map --output=./Debug/Musca_bare.elf > ./Debug/log.txt
