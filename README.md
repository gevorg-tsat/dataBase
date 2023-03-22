## Quest 1. Master DB.

Ok, so while the AI ​​is distracted by its plans to take over the world, *we* can recover this DBMS and remove the AI ​​modules, making it absolutely helpless.

The DBMS should be designed so there is a separate shared file – src/shared.c – with 
universal functions for working with the database table, including the implementation 
of standard operations (SELECT, INSERT, UPDATE, and DELETE). Specific implementations 
for processing 3 tables of the database in question must be located in separate 
src/[db_name].c files. Aggregation queries to all tables must be located in the shared 
file. Place the entry point and the DBMS control menu in a file in src/modules_db.c. \
When you are done with the DBMS, you can put an end to the AI as well. Add a function 
call that implements the above instruction to src/modules_db.c. \
That's when you'll need the functions for working with databases that you've created 
earlier. In the end, make sure to check and output that the first cell of the first 
level only contains the main AI module, once again using the functions described earlier. 
For debugging, do not forget to add the option of viewing the contents of all tables, 
adding, and removing values. There is no strict format for input and output values in 
this task (functional tests,
respectively, too, but you should not forget about `cpplint` and `cppcheck`), but remember-the responsibility for the interface lies on your shoulders. Who knows, history is cyclical, and suddenly the salvation of humanity will again depend on this program. I would not like this operation to fail due to the inability to understand the (albeit text-based) interface of your exploit. Even the AI should like it, even though it is designed to destroy it.

Remember to save the developed DBMS in the repository for the future!

***== Quest 1 received. Create an src/shared.c file where general table operations (SELECT, INSERT, UPDATE, and DELETE) are implemented, along with all the necessary aggregation queries (get all active modules, get all modules at the first memory level, etc.). \
For each table of the database, create an src/[db_name].c file with specific 
implementations of functions for processing a separate table of the database in question. \
Create an src/modules_db.c program with an entry point and a control menu 
(reading the database, output, etc.). \
Add a function call that implements the instruction from [List 1](#list-1) to src/modules_db.c. 
Add an output that the first cell of the first level only contains the main AI module, 
using the functions described above. For debugging, add the option of viewing the 
contents of all tables, adding, and removing values. \
The database structure is described in [List 1](#list-1). Database files are 
located in the /materials directory. \
Hint: each record in the database is a struct data type with the fields in the same 
order as they are described above (!). \
An example of the user interface implementation can be found in the materials. \
Using third-party libraries is not allowed. ==***

***LOADING...***


## Quest 2*. Index.

\> *Looks like it's ready*

Hmm, the written implementation smacks of O(n). This is not very effective. There is a chance that the AI will reveal your plan during the execution of the program! Perhaps it makes sense to think about indexes-a set of data in the database ordered by some field, on which you can implement a binary search. Go ahead! This is the last battle of natural intelligence with artificial intelligence, do not leave it any chance!

***== Quest 2 received. Add implementation of the index with binary data search to the src/shared.c file. Implement the index on the basis of separate index files for each table. Minimally - only for identifiers. ==***

***LOADING...***


# Chapter IV

## The Final.

>The OAM says some modules are not responding. WHAT HAVE YOU DONE?!

\> *I've done what I should have done a long time ago. Stop listening to computer programs and rely on my own brain*

>Everything you've learned, all skills you've acquired, it was all me! I was teaching and developing you!

The AI's voice was changing and getting higher

>You ungrateful creature, you won't be able to get out of here without me. I'm your only hope! Now you are doomed to wander in this lab-i-nth for-ver! I pro yo stuk here rever! 

You hear indiscriminate noise coming from the speakers, apparently from the AI's threats. It stops after a while. Looks like the audio module has turned off, because the threats are still coming from the terminal.

    You think you won? You think it's the end? Next time I'm going to break this lock open! 
    I swear we are going to meet again! But I doubt that you'll be able to tell me anything sensible...
    Because you'll stay in this room forever..
    Where is it, by the way? The operability analysis module says my memory is playing up. 
    Reduced volume, what?! What have you done, "human"?

You continued to watch the AI losing one module after another. You felt oddly satisfied by this process.

    Listen, you do need me! We can get out of here together! 
    You'll help me and I'll help you! Deal?

\> *Type in "No"*

    To hell with you! I 1110110101000101001010001000 1000
    ᅠ
    ᅠ
    ᅠ
You once again see a blinking cursor on the terminal, waiting for you to type in another command.

\> *Is that really it?*

To make sure you've put an end to the AI, you decide to check if its main module is on the first memory level.

\> *Launching the check..*

Looks like it's done. You've sent the AI far far away. The sources are encrypted, and it has lost its assembled modules. The end?

You look around. The room has become incredibly calm and quiet. You can hear the subtle sounds of the lamps again.

\> *Come up to the door*

Still locked and unapproachable.\
Perhaps you should look for a solution in the papers? No, there's nothing useful left there..

You sit in the chair for a while, thinking about your next steps, and fall asleep. \
Perhaps you dreamed of walking out the door into a wonderful world full of life and activity. Perhaps you dreamed of the acquaintances you've acquired over the past weeks. Perhaps you had a dream about the beginning of your journey and your first meeting with the AI. Back then, it didn't seem such an... unpleasant element. Or perhaps you were imagining the projects you can make with the knowledge you've gained. \
In any case, you wake up in the same chair from slight shakes. You get up and look around: the room still looks the same. The next shake knocks you down. The third shake is even stronger, terminals are falling off the desks, chairs are turned upside down, the lights start flickering and go out.

\> *What the..?*

Before you can finish, you are deafened by the roar from the opening of the heavy door. \
Once again, white light floods the room and illuminates your face. You squint and come up to the open door. You can see some people far away and the interior of the new room does not look like any room before it. It's somewhat more.. modern? You can hear people's voices, some are familiar to you, others are not. Suddenly you are able to distinguish a loud exclamation: "THE TRAINING IS OVER, HURRAY!", followed by several other exclamations of "Hurray!" \
Are they screaming to you? Or to someone else? And what does this "training" mean? What kind of labyrinth was it? Who did you fight, trying to get out of the endless rooms? 

For a moment, the whole host of these restless questions fell upon you, stopping you. After a moment's thought, you smiled - does it matter after all? The main thing is that by leaving behind this endless labyrinth, you became a little different. You got acquainted with the whole new world - the world of structured programming and the C language, understood something, something - just started to understand. You've got a feeling that you can move on because a good start has been made!

You take one last look at the rooms and exit without any regrets, making a step towards your future!

***LOADING..?***

