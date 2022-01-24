# SpellChecker
 Simple SpellChecker
 
## Prerequisites
 - CMake 3.12 or later

## Add new dictionaries
 - Add the *.dic file in the resources folder
 - Add the new file to the line in CMakeLists.txt: e.g. set(data resources/german.dic resources/english.dic)

## Use dictionaries
 - Command line: Use -name=MyDict.dic to use a dictionary from the resources folder
 - Command line: Use -custom=Path/To/File.dic to use a dictionary from a custom location 