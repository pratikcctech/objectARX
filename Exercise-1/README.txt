1) to start with the exercise-1 ,first we need to create the project.
2) to create project click on the new project in the home screen.
3) the project can be also be created by going to files and then new project.
4) then search for mfc dynamic library and then select next.
5) then after creating the project, next step is to configure that project.
6) so for configuration first go to the properties section and add the add the directories by going into c++ section and then general section and tab named additional include directories.
7) then the next step is to select the runtime library .
8) so to do this go the code-genertion section and change the runtime library o the multi-threded DLL.
9) now go into the linker section and then general and select the outfile path and change it to arx extention.
10) also in same section add the additional library by selecting the the path into c drive and autocad folder file named the libx64.
11) then add AdditionalDependencies by going into the input section .
12) add following dependencies.
	rxapi.lib
	• acdb20.lib
	• acge20.lib
	• acad.lib
	• ac1st20.lib
	• accore.lib
13) and click ok.
14) then add the entry point of the code in the .def life
15) in this way the configuration of the the project is done.
