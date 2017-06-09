#ifndef _FUNCTIONPOINTERS_H_
#define _FUNCTIONPOINTERS_H_


#include <errno.h>
#include <gctypes.h>
#include <ogc/ipc.h>


u8* enableUsbLog = (u8*)0x805A0CD8;


//Not a function POINTER, but since we don't have libc...
void* memset(void *__s, int __c, unsigned int num)
{
	int i;
	for (i = 0 ; i < num ; i++) *((char*)__s+i) = __c;
	return __s;
}


s32 (*IOS_Ioctlv)(s32 fd, s32 ioctl, s32 cnt_in, s32 cnt_io, ioctlv *argv) = (void*)0x80213090;//0x80212a40;
//argument 3 is likely the desired alignment boundary,
//but we'll probably always want 0x20, so this
//macro makes it work more as expected
void* (*_iosAlloc)(s32 hid,s32 size,u32 always0x20WTH) = (void*)0x80213598;
#define iosAlloc(x,y) _iosAlloc(x,y,0x20)
void (*iosFree)(s32 hid,void *ptr) = (void*)0x802137a8;
void* (*IPC_GetBufferLo)() = (void*)0x80211ae8;
s32 (*iosCreateHeap)(void* bufferLo, s32 size) = (void*)0x80213468;
s32 (*IOS_Open)(const char *filepath,u32 mode) = (void*)0x802123a8;
s32 (*IOS_Close)(s32 fd) = (void*)0x80212588;

#endif
