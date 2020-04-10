//
// Created by alon on 09/04/20.
//
#include "osm.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    cout << osm_operation_time(100000000) << endl;
    cout << osm_function_time(100000000) << endl;
    cout << osm_syscall_time(1000000) << endl;
}