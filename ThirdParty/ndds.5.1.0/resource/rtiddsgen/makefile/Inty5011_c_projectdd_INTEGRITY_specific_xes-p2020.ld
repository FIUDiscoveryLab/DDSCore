// --- Default link map for INTEGRITY Virtual Address Spaces ---
//
// Section notes are interleaved within the link map.  More information
// can be found in the "Linker Directives Files" section of the "Building
// INTEGRITY Applications" chapter of the INTEGRITY Development Guide.
//

-sec
// text (readonly) and data (read/write) areas must be page-aligned
{
// text/readonly segment
        .picbase	0x10000 	:
	.text				:
        .syscall 			:
	.intercall	align(4)	:
	.interfunc			:
        .secinfo 			:
        .rodata align(16) 			:
	.sdata2	align(16)				:
        .fixaddr 			:
        .fixtype 			:
// .textchecksum MUST be the last section of the text/readonly segment
	.textchecksum			:

// data/readwrite segment
	.pidbase	align(0x4000)	:
        .data 				:
	.sdabase 	align(8)	:
        .sdata 		align(8)	:
// .datachecksum MUST be the last section of the data portion of the 
// data/read/write segment (i.e., it must come before the BSS sections).
	.datachecksum			:
        .sbss 				:
        .bss 				:
// intex will create a heap section unless the following section is uncommented.
// The size of intex heap section defaults to the value of DefaultHeapSize in
// default.bsp.  To override for a particular AddressSpace, define HeapSize in
// the AddressSpace section in the .int file.
//	.heap	align(16) pad(0x10000) 	:
//
// Argument passing section for POSIX system clients
	.argsection align(0x1000)       : {*(.argsection) .=max(.,isdefined(SysRegister)?0x2000:0);}
}
