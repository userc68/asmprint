// LNX PRINT ASM
// X86-64 Because 32b is obsolete

#ifndef ASMP_H
#define ASMP_H


typedef unsigned long asm_s_int;

// made my own printf in inline assembly
void asmprint(const char *strn) {

  asm_s_int strn_len = 0;
  while (strn[strn_len]) strn_len++;

  asm (
    ".intel_syntax noprefix;"
    "mov rax, 1;"              // sys_write
    "mov rdi, 1;"              // stdout
    "mov rsi, %[strn];"        // buffer
    "mov rdx, %[strn_len];"    // length of string
    "syscall;"
    ".att_syntax prefix;" 
    : 
    : [strn] "r" (strn), [strn_len] "r" (strn_len)
    : "rax", "rdi", "rsi", "rdx"
  );

}

void asmprintln(const char *strn) {
  asmprint(strn);
  asmprint("\n");
}

#endif