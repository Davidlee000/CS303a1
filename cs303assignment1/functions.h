#pragma once
#include<iostream>
#include<fstream>

//returns array location
int check_num_present(int x, int array[150]);

//returns former value at location
int modify_at_index(int index, int value, int array[150]);

void add_int(int x, int array[150]);

void remove_int(int index, int array[150]);