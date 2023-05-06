# ENGG1340-Group66
Team Members:
  Zhong   Lin      3035988586    Zhonglin1231
  Wang    Qifan    3035973452    HKUfanfan
  Li      Junzhe   3035973854    KingofLaniakea
  Li      Haiying  3035973490    FalconLi
  
Description:
  It is a adventure game. Our map is just like the Haking Wong. The player acts in a role who is pursuing for the offer of his desired major in HKU. In the game, the player needs to control the role using "w""a""s""d"(you can also type multiple same keys for saving time) and use his wisdom to overcome obstacles in the way to achieve success. There are 6 little challenges in our game and if and only if you pass 5 or 6 subgames can you win the whole game. (simply going to the destination and the program will be ended). Every game is in a single room. There is a door matching to each room which looks like a "\/"  and it may be the key to start a subgame. when you meet a door, then you can choose to enter the game or not by inputting y or n. Among these games, you may have time limit or some other difficulties. Every concrete rule of a little game will be given when you are going to play it. 
  
Features:
  1. Random numbers are included in our games, so that various consequences will influence the result (Almost all the games)(requirement 1: Generation of random game sets or events).
  2. Various data structure are defined by 'strut' to storage the data made in our game (e.g. 128functions, choice game)(requirement2: Data structures for storing game status).
  3. Whether there is a way to success is provided using dynamic management to player in order to increase the fun of the game (e.g. Stonegame & Choice)(requirement3: Dynamic memory management).
  4. File input is utilized to receive the information of the map, the background of the game and so on (main.cpp)(requirement4: File input/output).
  5. Games are written in separate files to reduce the difficulty of debugging (requirement5: Program codes in multiple files).
  6. Multithreading method is used to implement unique input requirements (e.g. choice.cpp).
  7. Standard Template Libraries are implemented in the coding to achieve different functions (e.g. colorful texts, timing).
 
 
Non-standard C++ Libraries:
  No C++ Libraries that need to be downloaded from website or other places are included.
  
How to compile and execute:
  Makefile is provided. You can simply type "make main" to compile our code and run it using "./main". Then you can follow the rule which will be given in our game. Also, you can use clean to remove all the files.
  
