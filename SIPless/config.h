//
//  config.h
//  Paramara
//
//  Created by Timm Kandziora on 14.11.16.
//  Copyright © 2016 Timm Kandziora. All rights reserved.
//

#ifndef config_h
#define config_h

#include <libkern/libkern.h>

#define PRODUCT "SIPless"
#define LSI(message, ...) printf("[" PRODUCT "] " message "\n", ## __VA_ARGS__)
#define LFN printf("[" PRODUCT "] %s\n", __func__)
#define LSIAFN(message, ...) printf("[" PRODUCT "] %s" message "\n", __func__,  ## __VA_ARGS__)

#define LSIAP(str, ptr) \
do \
{ \
uintptr_t _p = (uintptr_t)(ptr); \
LSI(str ": 0x%08x%08x", ((uint32_t *)&_p)[1], ((uint32_t *)&_p)[0]); \
} while(0)

#define YOSEMITE    14
#define EL_CAPITAN  15
#define SIERRA      16
#define HIGH_SIERRA 17

#define KERNEL_PATH "/System/Library/Kernels/kernel"

#endif /* config_h */
