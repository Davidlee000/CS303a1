#include "functions.h"

int check_num_present(int x, int myarray[150]) {
	for (int i = 0; i <150; i++) {
		if (x == myarray[i]) {
			return i;
		}

	}
}

int modify_at_index(int index, int value, int myarray[150]) {
	
	int temp = myarray[index];
	myarray[index] = value;
	return temp;
}

// assumes that none of the values in the file are zeros and there are zeros at the end
void add_int(int x, int myarray[150]) {
	for (int i = 0; i < 150; i++) {
		if (myarray[i] == 0) {
			myarray[i] = x;
			break;
		}
	}
}
//assumes that there are zeros at the end
void remove_int(int index, int myarray[150]) {
	for (int i = index; i < 149; i++) {
		myarray[i] = myarray[i + 1];
	}
}