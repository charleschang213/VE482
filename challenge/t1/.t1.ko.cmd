cmd_/root/VE482/challenge/t1/t1.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -T ./scripts/module-common.lds  --build-id  -o /root/VE482/challenge/t1/t1.ko /root/VE482/challenge/t1/t1.o /root/VE482/challenge/t1/t1.mod.o ;  true
