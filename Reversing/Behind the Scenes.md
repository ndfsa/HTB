# Behind the Scenes
When running this program on ghidra some undefined instructions UD2, which are not essential to the execution of the program. So you can safely ignore this instructions and replace them with NOP.

After that, the decompiler should work, and the conditions start making more sense, the flag is directly written in the conditions.
