//
//  SIPless.c
//  SIPless
//
//  Created by Timm Kandziora on 12.02.18.
//  Copyright © 2018 Timm Kandziora. All rights reserved.
//

#include "SIPless.h"

static uintptr_t pe_state_address = 0;

kern_return_t set_csr(u_int32_t config)
{
    set_kernel_writing(true);
    
    struct PE_state pepe = *(struct PE_state *)pe_state_address;
    boot_args *args = (boot_args *)pepe.bootArgs;
    args->csrActiveConfig = config;
    
    set_kernel_writing(false);
    
    return KERN_SUCCESS;
}

kern_return_t SIPless_start(kmod_info_t * ki, void *d)
{
    LSI("Hei.");
    
    vm_offset_t fnctn = (vm_offset_t)printf;
    vm_offset_t up_addr = 0;
    vm_kernel_unslide_or_perm_external(fnctn, &up_addr);
    vm_offset_t kaslr_slide = fnctn - up_addr;
    uintptr_t base = (uintptr_t)(kaslr_slide + 0xffffff8000200000);
    
    pe_state_address = find_sym(base, "PE_state");
    
    if (pe_state_address != 0) {
        LSI("Successfully solved _PE_state ...");
    } else {
        LSI("Couldn't solve _PE_state, aborting ...");
        
        return KERN_FAILURE;
    }
    
    LSI("Setting new SIP configuration ...");
    
    set_csr(CSR_ALLOW_UNTRUSTED_KEXTS | CSR_ALLOW_UNRESTRICTED_NVRAM);
    
    LSI("Done. :)");
    
    return KERN_SUCCESS;
}

kern_return_t SIPless_stop(kmod_info_t *ki, void *d)
{
    return KERN_SUCCESS;
}
