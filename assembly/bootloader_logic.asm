section .text
    global _start

_start:
    ; Set up stack pointer
    mov esp, stack

    ; Load kernel into memory
    mov ah, 02h        ; BIOS function to read from disk
    mov al, 01h        ; Read one sector
    mov ch, 00h        ; Track number
    mov cl, 02h        ; Sector number
    mov dh, 00h        ; Head number
    mov dl, 00h        ; Drive number (first floppy drive)
    mov bx, 0x1000     ; Destination address in memory
    int 0x13           ; Call BIOS function to read sector into memory

    ; Jump to kernel code
    jmp 0x1000         ; Jump to the beginning of the kernel code

section .bss
    resb 4096         ; Reserve 4KB of memory for the stack

section .data
    ; No data in this example
