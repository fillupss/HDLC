# HDLC
This project is about designing the concept of how an HDLC works in communication systems, where if the first flag is detected then the data will start transmitting and when another flag is detected then the system knows that is the last bit of data. The flag for this case is 01111110.

This project was done using a Macbook Pro on the Eclipse IDE so it will not work on Windows or Linux since there is a library exclusive for the Mac. 
To run this project, go to the terminal on your IDE and type the commands of "gcc -o output HDLC.c -lncurses" followed by "./output
", where output can be any name since that is the file the program will be compiled to and ran.
