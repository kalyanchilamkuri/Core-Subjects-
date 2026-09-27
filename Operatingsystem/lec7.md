# when we press the power button , here's what happens

Power Button Pressed
         ↓
CPU starts
         ↓
BIOS/UEFI Firmware runs
         ↓
POST (checks hardware)
         ↓
Looks for Bootloader (MBR/EFI)
         ↓
Bootloader runs
         ↓
Loads Kernel & OS
         ↓
Login screen shows up!



# *pc turns on*

### power reaches all the components - cpu,Ram,motherboard,harddrive
### but all these components dont know what to do yet, they need instructions.

## cpu starts looking for instructions

### cpu initializes itself(like cleaning itself and settingup registers), then it looks for the set of instructions - these are not stored on the harddisk,they are stored in a small chip on the motherboard called BIOS chip.

## BIOS/UEFI

### BIOS=Basic Input Output System

### 1) it is a firmware stored in ROM on our motherboard
### 2) it helps talk to basic hardware(keyboard,disk,display)

### In modern pcs , instead of BIOS , we use UEFI (unified extensible firmware interface).It's like BIOS but smarter and more powerful (has GUI, mouse support,more features)

## POST(power-on selft-test)

### BIOS/UEFI starts by doing a POST
#### It checks:is the RAM okay?CPU?Keyboard?Display?
#### If something is wrong(like RAM is missing),it gives you an error and stops booting, if every thing is okay then it proceeds

## v. BIOS/UEFI Loads Bootloader
### Now BIOS/UEFI looks for a bootloader.
### On older systems, it checks the MBR (Master Boot Record) of the storage device (like HDD or SSD).
### On modern systems, it looks in the EFI system partition.

## Bootloader Time!
### the bootloader isa small program whose only job is to load the full operating system.
### bootloader starts the kernel(the heart of os),then it sets up user space , loads system processes and services,Now our os is up and running







 