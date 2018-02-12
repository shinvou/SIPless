//
//  cpu.h
//  Paramara
//
//  Created by Timm Kandziora on 20.03.17.
//  Copyright © 2017 Timm Kandziora. All rights reserved.
//

#ifndef cpu_h
#define cpu_h

#include <i386/proc_reg.h>
#include <libkern/libkern.h>
#include <mach/kern_return.h>
#include <machine/machine_routines.h>

kern_return_t set_kernel_writing(boolean_t);

#endif /* cpu_h */
