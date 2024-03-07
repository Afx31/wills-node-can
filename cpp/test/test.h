#ifndef TEST_H
#define TEST_H

#include "nan.h"

NAN_METHOD(Hello);
NAN_METHOD(HeresANumber);
NAN_METHOD(AddTenToThisNumber);

NAN_MODULE_INIT(Init);

#endif
