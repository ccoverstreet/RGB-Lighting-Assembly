# Simple Assembly-Like Language for RGB lights

This project is a crude attempt at creating an assembly like language for controlling RGB lighting behavior in an Arduino. The idea is to have a fixed stack of unsigned integers where each element represents a function call or argument. The goal is to have a base set of instructions that allow for essential behaviors like loops and branching statements. The key feature of this language is being very lightweight so that minimal storage is used on the arduino. 

The first implementation test would be in some ESP8266 controlled RGB lights. The endgoal is to be able to submit programs to the controller that can then be executed to perform custom lighting sequences. 

A fun goal that probably won't happen is to make a higher level language that compiles down into this assembly like language.

## Instruction Set

Current Size Allocated: 16 instructions

