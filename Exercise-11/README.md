Overview
This ObjectARX application defines a function called commandAndSystemVariable that interacts with the CIRCLERAD system variable in AutoCAD. The function performs the following tasks:

Retrieves the current value of the CIRCLERAD system variable using acedGetVar and displays it using acutPrintf.
Defines a center point for a circle (pt) and a radius (rrad).
Executes the CIRCLE command with the provided values using acedCommandS.
Pauses for user input before completing the circle using the PAUSE option with another call to the CIRCLE command.
Sets the value of the CIRCLERAD system variable back to its original value using acedSetVar.
Usage
Build and Load:

Open the ObjectARX project in Microsoft Visual Studio.
Build the project and load the resulting DLL in AutoCAD.
Run the Command:

In AutoCAD, enter the custom command associated with the commandAndSystemVariable function (e.g., "MYCOMMAND").
Interact with CIRCLERAD:

The function will retrieve the current value of the CIRCLERAD system variable, display it, create a circle with specified values, and pause for user input.

