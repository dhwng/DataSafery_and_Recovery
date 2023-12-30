#ifndef HEADER_H
#define HEADER_H
#include "VolumeSys.h"
#include <iostream>

using namespace std;

bool createVolume(const string& volumeName, uint64_t volumeSize);
void formatVolume(const string& volumeName, VolumeSys& vls);

#endif