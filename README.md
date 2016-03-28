# sop-pos-generator
C++ sum of products and product of sums from truth table generator

https://en.wikipedia.org/wiki/Canonical_normal_form

usage: ./possop.out example_input.txt example_output.txt
or: ./possop.out example_input.txt

input file format:
first line :(# of input variables) (input varname #1) (input varname#2) ... (# of rows of truth table)
rest of the file should be the truth table with spaces between each number.

writes output to terminal and file if specified.