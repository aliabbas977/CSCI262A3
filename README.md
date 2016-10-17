# CSCI262 Assignment 3

## Structure

Code stuff:

>traffic.h    : class declarations

>traffic.cpp  : initial input and the driver code (i.e. the actual program stuff)

>activity.cpp : activity engine and log generator stuff

>analysis.cpp : analysis engine stuff

>alert.cpp    : alert engine stuff

>makefile     : obviously for make (to compile on banshee)

Other:

>report.md    : put your report text in this markup file (to be put into a docx/pdf later)

Add any more files as necessary!

## Notes

Please avoid putting the following *in headers*:

>using namespace std;

Instead *in headers* please prefix standard library functions used with 'std::' as in:

>std::cout << "Hello World" << std::endl;

Please use cerr for error messages and cout for standard output.

## Useful References

* Google C++ Style Guide https://google.github.io/styleguide/cppguide.html
* Cppcheck http://cppcheck.sourceforge.net
* Git Cheat Sheet https://services.github.com/kit/downloads/github-git-cheat-sheet.pdf
* Markdown Cheatsheet https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet
* Makefiles - A tutorial by example http://mrbook.org/blog/tutorials/make/
