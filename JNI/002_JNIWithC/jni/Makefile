# Define a variable for classpath
CLASS_PATH = ../bin

# Define a virtual path for .class in the bin directory
vpath %.class $(CLASS_PATH)

# $* matches the target filename without the extension
HelloJNI.h : HelloJNI.class
	javah -classpath $(CLASS_PATH) $*
	
all : libhello.jnilib

# $@ matches the target, $< matches the first dependancy
libhello.jnilib : HelloJNI.o HelloJNICPP.o HelloJNI.h
	gcc -D -Wl, -dynamiclib -o $@ HelloJNI.o HelloJNICPP.o -lstdc++
	
HelloJNI.o : HelloJNI.c HelloJNI.h
	gcc -D __int64="long long" -I"/Library/Java/JavaVirtualMachines/jdk1.8.0_91.jdk/Contents/Home/include" -I"/Library/Java/JavaVirtualMachines/jdk1.8.0_91.jdk/Contents/Home/include/darwin" -c -o $@ $<
	
HelloJNICPP.o : HelloJNICPP.cpp HelloJNI.h
	g++ -D __int64="long long" -I"/Library/Java/JavaVirtualMachines/jdk1.8.0_91.jdk/Contents/Home/include" -I"/Library/Java/JavaVirtualMachines/jdk1.8.0_91.jdk/Contents/Home/include/darwin" -c -o $@ $<
	
clean :
	rm HelloJNI.h HelloJNI.o HelloJNICPP.cpp