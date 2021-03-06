#ifndef _DEFINES_H_
#define _DEFINES_H_
#include <Python.h>

#define MODULE_NAME "ics"
#define MODULE_DESCRIPTION "Copyright Intrepid Control Systems, Inc."

#ifdef _cplusplus
extern "C" {
#endif

int setup_module_defines(PyObject* module);

#ifdef _cplusplus
}
#endif // extern "C" {

#endif