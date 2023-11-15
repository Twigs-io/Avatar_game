# Avatar: The Last Airbender: The Text Based RPG
 
Authors: 
[Jad Mukbel](https://github.com/jmukb001), 
[Pranesh Naagamuthu](https://github.com/Twigs-io), 
[Aaron Lim](https://github.com/DoubleAPowerBox), 
[Donovan Pilcher](https://github.com/Groovyfaun)

## Project Description
* Our group decided on making a game based off of Avatar: The Last Airbender as we are all fans of the series and the world it takes place in. We believe if we base our project upon a show we are passionate about, it will help us stay motivated to see it to its completion. That, and we would like to simulate duels between benders to finally, finally answer the question of who is the best character of all.

### Tools and Technologies
* We plan to use C++ as out primary coding language and we plan on using GitHub as a remote repository to keep our work together.
   
### Input/Output
* The input would be text-based, with inputs coming from the user directly when they type, and all of the output will be shown as text descriptions describing what is occurring within the game.

### Overview of what we are trying to achieve - 

A user will select single player mode or two-player mode.

From there, they will enter their player name, and be asked where both their parents are from, and whether their parents were benders, and if so, what kind.

Using the information entered above, their character’s power will be generated based on the hereditary probability of them being a bender or not. For example, if their mother is a water-bender, and their dad is a fire-bender, there is a 50% chance of their character being either bender. However if their mom is a water-bender, and dad a non-bender, they would have a 50% chance of being a non-bender. 

These steps will be repeated if the user initially selects two-player. If the user selects single-player, they may pick an automatically generated character from the members of Team Avatar, listed below. 

 * Aang - Air Bender
 * Katara - Water Bender
 * Toph - Earth Bender
 * Zuko - Fire Bender
 * Sokka - Non-Bender
 
After the user's character has been created, they will face either Character II or the CPU in a match. It will be similar to rock paper scissors or Pokemon, in the sense that one move will be stronger than another, but can be countered by another. 

We will take more time planning to discuss if sub-bending would take too much time for this project. For example, implementing the ability to utilize ice with water-bending, lava for earth-bending, etc. 

 For the CPU we can try and make it so that there are presets to select from such as the people from Avatar, and make their choice selection randomized.
 
 ## Class Diagram
 <img width="737" alt="image" src="https://user-images.githubusercontent.com/122484112/222884500-5c6b10a7-ad43-44c9-9543-64cacc430eea.png">
 
 Through the UI, GameManager will acquire and store all relevant information pertaining to the game, including both player's names, parental bends, and be able to return these data members. The Person/GameManager class will use the data members to construct the specific benders
 
 The person class will serve as the base class that every player will become. The class will contain the user name, an object of which bender, and health measure. The person will have a takeHit function, which will lower their health throughout the match, a userDodge function, which will return whether or not the user used a dodge move, and basicAttack function that all benders will inherit. Inherited from person, and through the program, a user will be either a waterbender, firebender, airbender, earthbender, or nonbender. They cannot be more than one of these inherited classes. Each bender will have one attack move and one defense move. Additional attacks may be implemented if time permits. 
 
Aside from this, an Arena class was generated to set the stage and location of the battle. With further implementation this may have an effect on the bender's speciality move.

  ![CSG](https://user-images.githubusercontent.com/113262801/222823914-4f5f2edf-78eb-4766-8476-b85732100bba.jpg)

We added BenderManager to the class diagram, to make it easier on the main fighting class and manageing the damage results, defence, health for 4 different bender classes. We Split the GameManager into subclasses due to the fact it was trying to do multiple things at the same time, now it each class operates different functions such as getting the inputs, determing the bend the player chooses, and displaying text for the user to choose. We added a GameManager fight, that does the basic loop for the class, which has seperate functions because then only it complies complies with the open close principal. 

* What SOLID principle(s) did you apply?
- Single Responsibility Principal - most of our classes and functions do one specific function and nothing more. This makes it easier to Unit Test our code, and also ensures it follows the Simple Design pattern.
- Open Closed Principal - we have code that can be easily extended with functions in the higher level so that it is easier to add onto the code and harder to take something away. The code is open for extension, but closed for modification. If somehow a 6th type of bender would be added, they would be able to
- Liskov Subsitution Principal - Used a vector of person classes (this is the parent) to store bending classes(child classes), this is completeing the requirement of this principal
- This change heleped with the readability of our code, and also the ease of change that can happen in the code

 ## Final UML
 ![CSG drawio](https://user-images.githubusercontent.com/113262801/226065242-7e1ac04f-3905-4c40-a1d8-fb0bf1de5c80.png)

 ## Screenshots
 Screenshots of the input/output after running your application
 Google Docs link containing all of the screenshots - https://docs.google.com/document/d/1PfPAvM-TexCbvAii4MKms_VlpLUZdXVaZhwOhXi3pNs/edit?usp=sharing
 ## Installation/Usage
 The program can be built using "cmake .", make, and compiled using the executable "./rpg"
 
 Unit tests can be ran using "cmake .", make, and compiled using the executable "./test"
 
 Vaalgrind can be ran using "valgrind --leak-check=full ./(executable)
 "
 ## Testing
 Unit tests were created using the GoogleTest framework in order to ensure functions were executing correctly and returning expected values. Through testing, we were able to detect bugs and prompted us to improve our code to handle these bugs. 
 On top of that, User gameplay was experimented to catch any conditions that may have been missed by the created unit tests.
 
 We ensured our main build, as well as unit tests, were free from memory leaks. Shown Below
 <img width="921" alt="image" src="https://user-images.githubusercontent.com/122484112/226200882-9982ac04-ea67-4dbd-b8a6-17cdba1f8c9f.png">
 <img width="913" alt="image" src="https://user-images.githubusercontent.com/122484112/226200726-ffa502c1-37df-450f-a149-8422d1fe75f5.png">

