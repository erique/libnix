/* Automatically generated header (sfdc 1.11)! Do not edit! */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if 0 && defined (__libnix__)

#include <stabs.h>
void* ConsoleDevice[2] = { 0, "console.device" };
ADD2LIB(ConsoleDevice);

#elif defined (__AMIGAOS4__)

#undef __USE_INLINE__
#define _NO_INLINE
#include <exec/libraries.h>
#include <devices/inputevent.h>
#include <devices/keymap.h>

#include <interfaces/console.h>
#include <proto/exec.h>
#include <assert.h>

__attribute__((weak)) struct Device * ConsoleDevice = NULL;
__attribute__((weak)) struct ConsoleDeviceIFace* IConsoleDevice = NULL;

void __init_ConsoleDevice(void) __attribute__((constructor));
void __exit_ConsoleDevice(void) __attribute__((destructor));

void __init_ConsoleDevice(void) {
  if (ConsoleDevice == NULL) {
    ConsoleDevice = (struct Device *) IExec->OpenLibrary("console.device", 0);
    assert(ConsoleDevice != NULL);
  }
  if (IConsoleDevice == NULL) {
    IConsoleDevice = (struct ConsoleDeviceIFace*) IExec->GetInterface((struct Library*) ConsoleDevice, "main", 1, NULL);
    assert(IConsoleDevice != NULL);
  }
}

void __exit_ConsoleDevice(void) {
  IExec->DropInterface((struct Interface*) IConsoleDevice);
  IExec->CloseLibrary((struct Library*) ConsoleDevice);
}


#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */
