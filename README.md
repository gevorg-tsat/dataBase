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

