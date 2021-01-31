# Simple Assembly-Like Language for RGB lights

This project is a crude attempt at creating an assembly like language for controlling RGB lighting behavior in an Arduino. The idea is to have a fixed stack of unsigned integers where each element represents a function call or argument. The goal is to have a base set of instructions that allow for essential behaviors like loops and branching statements. The key feature of this language is being very lightweight so that minimal storage is used on the arduino. 

The first implementation test would be in some ESP8266 controlled RGB lights. The endgoal is to be able to submit programs to the controller that can then be executed to perform custom lighting sequences. 

A fun goal that probably won't happen is to make a higher level language that compiles down into this assembly like language.

## Status

All code is currently header only as the design of the interface is changing frequently. Header only might be viable for distribution since this should be a single includefor Arduino.

## Instruction Set and Architecture


All instructions take the form of a `int instruction(int stack_index, unsigned int *argv)`. The argv pointer points to the stack at the index of the called instruction.

R1: Loop register

Current Size Allocated: 16 instructions

 - 0x00000000: noop
 - 0x00000001: go_to
   - Returns the first argument as the new current index.
 - 0x00000002: jump
   - Relative goto, adds the first argument to the current stack index
 - 0x00000003: jump_eq
   - Jumps if R1 == (second arg) by first argument
 - 0x00000004: jump_lt
   - Jumps if R1 < (second arg) by first argument
 - 0x00000005: jump_gt
   - Jumps if R1 > (second arg) by first argument
 - 0x00000006: jump_lt_eq
   - Jumps if R1 <= (second arg) by first argument
 - 0x00000007: jump_gt_eq
   - Jumps if R1 >= (second arg) by first argument
 - 0x00000008: set_R1
   - Sets R1 to first argument
 - 0x00000009: increment_R1
   - Increments R1 by first argument
 - 0x0000000a: decrement_R1
   - Decrements R1 by first argument
 - 0x0000000b: sleep
   - Sleeps by first argument (in milliseconds)

 
