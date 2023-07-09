# Linux-shell-simple-in-C
Build simple Linux shell in C using fork and execl() system call 
              OPERATING SYSTEM
              
Name: Saurbh Kumar

EXTERNAL COMMANDS:

i) ls
          ◼ ls:   this command displays the files and directories in tabular
                    form.
          ◼ ls -s: this command displays size before each file/directory in 
                       tabular form.
                       It also prints the total size of all the files/directories

          ◼ ls -l: this command displays the files and directories in a list.

         Note : any other ls command(other than ls,l,)

ii) rm
         ◼ rm file_name: this command remove/deletes the file file_name
                                    It does not delete any directory. 

         ◼ rm -r DIRNAME : It deletes files and Directories as well.
                               sub-files and sub-directories are deleted too.
         ◼ rm -v DIRNAME:  after deleting it display a delete confirmation 
                                          message

iii) cat
       ◼ cat :  it simply work as printf() function. Whatever we write it
                      simply prints on screen.
         
         ◼  cat -n file: it simply shows line number in front of each line of 
                              the file.
        ◼  cat -e filename: it basically adds “$” to the end of each line of 
                                       Of the file
        Note: we will get error if we use any other options 

 iv) mkdir
               ◼  mkdir dir: it simply makes a directory with name dir
                                         This command does not create sub-directory

                   ◼  mkdir -p dir/A/B: this creates directory with its sub-
                                                     directory.
                                                    Here dir has subdirectory A and A 
                                                    has subdirectory B
                  ◼  mkdir -v dir: after creating directory it displays a
                                            confirmation message. It do not create
                                            subdirectory
               
                  Note: we will get error if we use any other options                         
 

      v) date 
                  ◼  date: it will print the current date and time

                  ◼  date -r filename: it will print the last modified date of 
                                                        the file filename
                        ◼  date  +A:  prints the current day
  
                  ◼  date  +B: prints the current month           
                  ◼  date  +Y: print the current year
                            ◼  date  +%d/%m/%y:      prints only the current date
                     ◼  date  +%H:%M:%S:     prints the current time

         Note: Any other option other than above one's will print error

INTERNAL COMMAND:

   i) echo : it simply prints everything we write in a line
   ii) pwd : it prints the current running directory
   iii) cd :   it changes the directory

 HOW TO EXIT ?
 Just enter “end”    
      
Few test case:

ls
ls -l
ls -s
echo hello guys
cat
Hello world
cat -n file
cat -e file
mkdir dir
mkdir -p dir/a/b/c
mkdir -v dir
date
date  +%A
date  +%B
date  +%Y
date  +%d/%m/%y
date  +%d/%m/%Y
date -r file
rm file1
rm -r file2
rm -v file3


