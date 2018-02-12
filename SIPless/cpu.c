//
//  cpu.c
//  Paramara
//
//  Created by Timm Kandziora on 20.03.17.
//  Copyright © 2017 Timm Kandziora. All rights reserved.
//

#include "cpu.h"

static kern_return_t set_wp_bit(boolean_t enable)
{
    /*
     TODO: Use lock so we don't risk someone else changing cr0 ...
     */
    
    uintptr_t cr0 = get_cr0();
    
    if (enable) {
        cr0 = cr0 | CR0_WP;
    } else {
        cr0 = cr0 & ~CR0_WP;
    }
    
    set_cr0(cr0);
    
    if (((get_cr0() & CR0_WP) != 0 && enable) || ((get_cr0() & CR0_WP) == 0 && !enable)) {
        return KERN_SUCCESS;
    } else {
        return KERN_FAILURE;
    }
}

kern_return_t set_kernel_writing(boolean_t enable)
{
    kern_return_t ret = KERN_SUCCESS;
    
    if (enable) ml_set_interrupts_enabled(false);
    
    if (set_wp_bit(!enable) != KERN_SUCCESS) {
        enable = false;
        ret = KERN_FAILURE;
    }
    
    if (!enable) ml_set_interrupts_enabled(true);
    
    return ret;
}
