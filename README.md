# Computer Systems Project 2
Created February 2020:
Second project for Computer Systems course. This project, written in C, takes a message and key, as txt files, and preforms an encryption on the message using the key. To do this, the user will call make in the terminal. This will create an executable called onetimepad. The user will then concatenate the message file, the delimiter file, and the key file and pipe this into the executable and send the output to an output.txt file. The delimiter is a txt file containing a single character whose value is 255. This is used to split up the message and key upon input. The output should be a mess of random characters. If the user preforms the same encryption using the output as the message and the same key, then the original message will be given. 
