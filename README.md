# SNHU-CS210
# Cameron Beck
# Module 8

"Summarize the project and what problem it was solving."

The project I want to summarize is the first project. In it, I was tasked to design a digital clock that comes with the options menu with the following: add a second, add a minute, and add an hour. When I say a digital clock, I mean a clock that displays both the 12-hour and 24-hour clock at the same time.

"What did you do particularly well?"

What I did particulary well in that project was that I implemented multiple functions fitted for certain activities. For example, in the main function in the while loop, I always call for the display time and display menu functions after the user gives their initial inputs. If the user selects either options 1, 2, or 3, I increment a value by one based off the user's choice. Afterwards the display time function carries the three parameters of hours, minutes, and seconds to that function. In the display function, I have two more functions within it that converts the time accordingly for both the 12-hour clock and 24-hour clock just to save time from rewritting codes over and over again.

"Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?"

The part that I could enhance my code would be incrementing an hour, minute, and second after the variable reaches a certain number after the user increments a spot. For example if the user seconds roles past 59, it should add one minute. If user minutes roll past 59, then an hour should be incremented. These improvement makes my code more efficient by making it function perfectly like an actual clock.

"Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?"

The pieces of code that I found to be the most challenging was converting the display time from integer to string. I had to create multiple if statements that if a number was below 10, then I concat a 0 string next to the number. My entire thought process was that I could have the numbers on the clock display as an integer but couldn't because of that fact of a variable value being below 10 must have a 0 before the number converted as a string. For example if the time is 1 hour, 3 minutes, and 24 seconds, I have to display it as 01:03:24 as a string text, not an integer. The tools that helped me overcome this issue was zyBooks. zyBooks helped me get an understanding about the if statements, integer, and string output so that I can combine all of the values together in one big string output.

"What skills from this project will be particularly transferable to other projects or course work?"

The skills from the first project that will be transferable to other projects is creating multiple functions. Doing so will help save time, effort, and energy generating code. Also class functions too, even though it was absent in the first project. Establishing public, private values, and calling a class object within a code (and calling class functions) is just as useful as establishing multiple functions without using the class object.

"How did you make this program maintainable, readable, and adaptable?"

I made the program maintainable, readable, and adaptable by writing comments under every action of the code describing it's purpose. Another thing I did was made sure to call the display functions everytime to print out all of the main menu items, and both of its 12-hour and 24-hour clock. I also made sure to add stars around the display texts to separate from the other texts to make sure the display text values were arranged nice and neet just like how the examples from the instructions showed.
