I created a function called "MyCommand" that, when used in the AutoCAD command line, displays the message "Hello <Name> in the world of AutoCAD." 
Here are the steps:
 
1. Initialization: Unlocked and registered the application as MDI aware. 
2. Printed a message in the AutoCAD command line to indicate that the application has been loaded. Also, registered a new modal command called "MYCOMMAND"
3. within the   "MyGroup" group, linking it to the MyCommand function in the CProject3App class.
4. Custom Command (MyCommand): Defined the behavior of the custom command "MYCOMMAND" to
  print the message Hello this is pratik and welcome World of AutoCAD on command line.
5. Unload: Printed a message in the AutoCAD command line to indicate that the application is being unloaded.
