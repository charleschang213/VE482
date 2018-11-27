cmd_/root/VE482/challenge/t6/t6.o := gcc -Wp,-MD,/root/VE482/challenge/t6/.t6.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/7/include -I/root/linux-next/arch/x86/include -I./arch/x86/include/generated  -I/root/linux-next/include -I./include -I/root/linux-next/arch/x86/include/uapi -I./arch/x86/include/generated/uapi -I/root/linux-next/include/uapi -I./include/generated/uapi -include /root/linux-next/include/linux/kconfig.h -include /root/linux-next/include/linux/compiler_types.h  -I/root/VE482/challenge/t6 -I/root/VE482/challenge/t6 -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -DCC_HAVE_ASM_GOTO -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time -DCONFIG_X86_X32_ABI -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_SSSE3=1 -DCONFIG_AS_AVX=1 -DCONFIG_AS_AVX2=1 -DCONFIG_AS_AVX512=1 -DCONFIG_AS_SHA1_NI=1 -DCONFIG_AS_SHA256_NI=1 -Wno-sign-compare -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register -Wa,arch/x86/kernel/macros.s -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-int-in-bool-context -O2 --param=allow-store-data-races=0 -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -g -gdwarf-4 -pg -mrecord-mcount -mfentry -DCC_USING_FENTRY -Wdeclaration-after-statement -Wvla -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init  -DMODULE  -DKBUILD_BASENAME='"t6"' -DKBUILD_MODNAME='"t6"' -c -o /root/VE482/challenge/t6/t6.o /root/VE482/challenge/t6/t6.c

source_/root/VE482/challenge/t6/t6.o := /root/VE482/challenge/t6/t6.c

deps_/root/VE482/challenge/t6/t6.o := \
  /root/linux-next/include/linux/kconfig.h \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  /root/linux-next/include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  /root/linux-next/include/linux/compiler_attributes.h \
  /root/linux-next/include/linux/compiler-gcc.h \
    $(wildcard include/config/cc/optimize/for/debugging.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /root/linux-next/include/linux/module.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/modules/tree/lookup.h) \
    $(wildcard include/config/livepatch.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/function/error/injection.h) \
    $(wildcard include/config/strict/module/rwx.h) \
  /root/linux-next/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  /root/linux-next/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /root/linux-next/include/uapi/linux/types.h \
  /root/linux-next/arch/x86/include/uapi/asm/types.h \
  /root/linux-next/include/uapi/asm-generic/types.h \
  /root/linux-next/include/asm-generic/int-ll64.h \
  /root/linux-next/include/uapi/asm-generic/int-ll64.h \
  /root/linux-next/arch/x86/include/uapi/asm/bitsperlong.h \
  /root/linux-next/include/asm-generic/bitsperlong.h \
  /root/linux-next/include/uapi/asm-generic/bitsperlong.h \
  /root/linux-next/include/uapi/linux/posix_types.h \
  /root/linux-next/include/linux/stddef.h \
  /root/linux-next/include/uapi/linux/stddef.h \
  /root/linux-next/include/linux/compiler_types.h \
  /root/linux-next/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/x86/32.h) \
  /root/linux-next/arch/x86/include/uapi/asm/posix_types_64.h \
  /root/linux-next/include/uapi/asm-generic/posix_types.h \
  /root/linux-next/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
    $(wildcard include/config/page/poisoning/zero.h) \
  /root/linux-next/include/linux/const.h \
  /root/linux-next/include/uapi/linux/const.h \
  /root/linux-next/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/arch/has/refcount.h) \
    $(wildcard include/config/panic/timeout.h) \
  /usr/lib/gcc/x86_64-linux-gnu/7/include/stdarg.h \
  /root/linux-next/include/linux/linkage.h \
  /root/linux-next/include/linux/stringify.h \
  /root/linux-next/include/linux/export.h \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/module/rel/crcs.h) \
    $(wildcard include/config/have/arch/prel32/relocations.h) \
    $(wildcard include/config/trim/unused/ksyms.h) \
  /root/linux-next/include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/kasan.h) \
  /root/linux-next/arch/x86/include/asm/barrier.h \
  /root/linux-next/arch/x86/include/asm/alternative.h \
  /root/linux-next/arch/x86/include/asm/asm.h \
  /root/linux-next/arch/x86/include/asm/nops.h \
    $(wildcard include/config/mk7.h) \
    $(wildcard include/config/x86/p6/nop.h) \
    $(wildcard include/config/x86/64.h) \
  /root/linux-next/include/asm-generic/barrier.h \
  /root/linux-next/include/linux/kasan-checks.h \
  /root/linux-next/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/x86/alignment/16.h) \
  /root/linux-next/include/linux/bitops.h \
  /root/linux-next/include/linux/bits.h \
  /root/linux-next/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/x86/cmov.h) \
  /root/linux-next/arch/x86/include/asm/rmwcc.h \
  /root/linux-next/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  /root/linux-next/include/asm-generic/bitops/sched.h \
  /root/linux-next/arch/x86/include/asm/arch_hweight.h \
  /root/linux-next/arch/x86/include/asm/cpufeatures.h \
  /root/linux-next/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/x86/minimum/cpu/family.h) \
    $(wildcard include/config/math/emulation.h) \
    $(wildcard include/config/x86/pae.h) \
    $(wildcard include/config/x86/cmpxchg64.h) \
    $(wildcard include/config/x86/use/3dnow.h) \
    $(wildcard include/config/matom.h) \
    $(wildcard include/config/paravirt.h) \
  /root/linux-next/arch/x86/include/asm/disabled-features.h \
    $(wildcard include/config/x86/intel/mpx.h) \
    $(wildcard include/config/x86/smap.h) \
    $(wildcard include/config/x86/intel/umip.h) \
    $(wildcard include/config/x86/intel/memory/protection/keys.h) \
    $(wildcard include/config/x86/5level.h) \
    $(wildcard include/config/page/table/isolation.h) \
  /root/linux-next/include/asm-generic/bitops/const_hweight.h \
  /root/linux-next/include/asm-generic/bitops/le.h \
  /root/linux-next/arch/x86/include/uapi/asm/byteorder.h \
  /root/linux-next/include/linux/byteorder/little_endian.h \
  /root/linux-next/include/uapi/linux/byteorder/little_endian.h \
  /root/linux-next/include/linux/swab.h \
  /root/linux-next/include/uapi/linux/swab.h \
  /root/linux-next/arch/x86/include/uapi/asm/swab.h \
  /root/linux-next/include/linux/byteorder/generic.h \
  /root/linux-next/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /root/linux-next/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  /root/linux-next/include/linux/typecheck.h \
  /root/linux-next/include/linux/printk.h \
    $(wildcard include/config/message/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/quiet.h) \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk/nmi.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  /root/linux-next/include/linux/init.h \
    $(wildcard include/config/strict/kernel/rwx.h) \
  /root/linux-next/include/linux/kern_levels.h \
  /root/linux-next/include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /root/linux-next/include/uapi/linux/kernel.h \
  /root/linux-next/include/uapi/linux/sysinfo.h \
  /root/linux-next/arch/x86/include/asm/cache.h \
    $(wildcard include/config/x86/l1/cache/shift.h) \
    $(wildcard include/config/x86/internode/cache/shift.h) \
    $(wildcard include/config/x86/vsmp.h) \
  /root/linux-next/include/linux/dynamic_debug.h \
    $(wildcard include/config/jump/label.h) \
  /root/linux-next/include/linux/jump_label.h \
    $(wildcard include/config/have/arch/jump/label/relative.h) \
  /root/linux-next/arch/x86/include/asm/jump_label.h \
  /root/linux-next/include/linux/build_bug.h \
  /root/linux-next/include/linux/stat.h \
  /root/linux-next/arch/x86/include/uapi/asm/stat.h \
  /root/linux-next/include/uapi/linux/stat.h \
  /root/linux-next/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  /root/linux-next/include/linux/seqlock.h \
    $(wildcard include/config/debug/lock/alloc.h) \
  /root/linux-next/include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/preempt.h) \
  /root/linux-next/include/linux/preempt.h \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/trace/preempt/toggle.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  /root/linux-next/arch/x86/include/asm/preempt.h \
  /root/linux-next/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/x86/64/smp.h) \
  /root/linux-next/include/asm-generic/percpu.h \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  /root/linux-next/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /root/linux-next/include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
    $(wildcard include/config/virtualization.h) \
    $(wildcard include/config/amd/mem/encrypt.h) \
  /root/linux-next/include/linux/thread_info.h \
    $(wildcard include/config/thread/info/in/task.h) \
    $(wildcard include/config/have/arch/within/stack/frames.h) \
    $(wildcard include/config/hardened/usercopy.h) \
  /root/linux-next/include/linux/bug.h \
    $(wildcard include/config/bug/on/data/corruption.h) \
  /root/linux-next/arch/x86/include/asm/bug.h \
    $(wildcard include/config/debug/bugverbose.h) \
  /root/linux-next/include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
    $(wildcard include/config/bug.h) \
  /root/linux-next/include/linux/restart_block.h \
  /root/linux-next/include/linux/time64.h \
    $(wildcard include/config/64bit/time.h) \
  /root/linux-next/include/linux/math64.h \
    $(wildcard include/config/arch/supports/int128.h) \
  /root/linux-next/arch/x86/include/asm/div64.h \
  /root/linux-next/include/asm-generic/div64.h \
  /root/linux-next/include/uapi/linux/time.h \
  /root/linux-next/arch/x86/include/asm/current.h \
  /root/linux-next/arch/x86/include/asm/thread_info.h \
    $(wildcard include/config/vm86.h) \
    $(wildcard include/config/frame/pointer.h) \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/ia32/emulation.h) \
  /root/linux-next/arch/x86/include/asm/page.h \
  /root/linux-next/arch/x86/include/asm/page_types.h \
    $(wildcard include/config/physical/start.h) \
    $(wildcard include/config/physical/align.h) \
    $(wildcard include/config/dynamic/physical/mask.h) \
  /root/linux-next/include/linux/mem_encrypt.h \
    $(wildcard include/config/arch/has/mem/encrypt.h) \
  /root/linux-next/arch/x86/include/asm/mem_encrypt.h \
  /root/linux-next/arch/x86/include/uapi/asm/bootparam.h \
  /root/linux-next/include/linux/screen_info.h \
  /root/linux-next/include/uapi/linux/screen_info.h \
  /root/linux-next/include/linux/apm_bios.h \
  /root/linux-next/include/uapi/linux/apm_bios.h \
  /root/linux-next/include/uapi/linux/ioctl.h \
  /root/linux-next/arch/x86/include/uapi/asm/ioctl.h \
  /root/linux-next/include/asm-generic/ioctl.h \
  /root/linux-next/include/uapi/asm-generic/ioctl.h \
  /root/linux-next/include/linux/edd.h \
  /root/linux-next/include/uapi/linux/edd.h \
  /root/linux-next/arch/x86/include/asm/ist.h \
  /root/linux-next/arch/x86/include/uapi/asm/ist.h \
  /root/linux-next/include/video/edid.h \
    $(wildcard include/config/x86.h) \
  /root/linux-next/include/uapi/video/edid.h \
  /root/linux-next/arch/x86/include/asm/page_64_types.h \
    $(wildcard include/config/dynamic/memory/layout.h) \
    $(wildcard include/config/randomize/base.h) \
  /root/linux-next/arch/x86/include/asm/kaslr.h \
    $(wildcard include/config/randomize/memory.h) \
  /root/linux-next/arch/x86/include/asm/page_64.h \
    $(wildcard include/config/debug/virtual.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/x86/vsyscall/emulation.h) \
  /root/linux-next/include/linux/range.h \
  /root/linux-next/include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  /root/linux-next/include/linux/pfn.h \
  /root/linux-next/include/asm-generic/getorder.h \
  /root/linux-next/arch/x86/include/asm/cpufeature.h \
    $(wildcard include/config/x86/feature/names.h) \
  /root/linux-next/arch/x86/include/asm/processor.h \
    $(wildcard include/config/kvm.h) \
    $(wildcard include/config/stackprotector.h) \
    $(wildcard include/config/paravirt/xxl.h) \
    $(wildcard include/config/x86/debugctlmsr.h) \
    $(wildcard include/config/cpu/sup/amd.h) \
    $(wildcard include/config/xen.h) \
  /root/linux-next/arch/x86/include/asm/processor-flags.h \
  /root/linux-next/arch/x86/include/uapi/asm/processor-flags.h \
  /root/linux-next/arch/x86/include/asm/math_emu.h \
  /root/linux-next/arch/x86/include/asm/ptrace.h \
  /root/linux-next/arch/x86/include/asm/segment.h \
    $(wildcard include/config/xen/pv.h) \
    $(wildcard include/config/x86/32/lazy/gs.h) \
  /root/linux-next/arch/x86/include/uapi/asm/ptrace.h \
  /root/linux-next/arch/x86/include/uapi/asm/ptrace-abi.h \
  /root/linux-next/arch/x86/include/asm/paravirt_types.h \
    $(wildcard include/config/pgtable/levels.h) \
    $(wildcard include/config/paravirt/debug.h) \
  /root/linux-next/arch/x86/include/asm/desc_defs.h \
  /root/linux-next/arch/x86/include/asm/kmap_types.h \
    $(wildcard include/config/debug/highmem.h) \
  /root/linux-next/include/asm-generic/kmap_types.h \
  /root/linux-next/arch/x86/include/asm/pgtable_types.h \
    $(wildcard include/config/mem/soft/dirty.h) \
    $(wildcard include/config/proc/fs.h) \
  /root/linux-next/arch/x86/include/asm/pgtable_64_types.h \
  /root/linux-next/arch/x86/include/asm/sparsemem.h \
  /root/linux-next/include/asm-generic/pgtable-nop4d.h \
  /root/linux-next/arch/x86/include/asm/nospec-branch.h \
    $(wildcard include/config/retpoline.h) \
  /root/linux-next/arch/x86/include/asm/alternative-asm.h \
  /root/linux-next/arch/x86/include/asm/msr-index.h \
  /root/linux-next/arch/x86/include/asm/spinlock_types.h \
    $(wildcard include/config/paravirt/spinlocks.h) \
  /root/linux-next/include/asm-generic/qspinlock_types.h \
  /root/linux-next/include/asm-generic/qrwlock_types.h \
  /root/linux-next/include/asm-generic/ptrace.h \
  /root/linux-next/arch/x86/include/uapi/asm/sigcontext.h \
  /root/linux-next/arch/x86/include/asm/msr.h \
  /root/linux-next/arch/x86/include/asm/msr-index.h \
  /root/linux-next/arch/x86/include/uapi/asm/errno.h \
  /root/linux-next/include/uapi/asm-generic/errno.h \
  /root/linux-next/include/uapi/asm-generic/errno-base.h \
  /root/linux-next/arch/x86/include/asm/cpumask.h \
  /root/linux-next/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  /root/linux-next/include/linux/bitmap.h \
  /root/linux-next/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
    $(wildcard include/config/fortify/source.h) \
  /root/linux-next/include/uapi/linux/string.h \
  /root/linux-next/arch/x86/include/asm/string.h \
  /root/linux-next/arch/x86/include/asm/string_64.h \
    $(wildcard include/config/x86/mce.h) \
    $(wildcard include/config/arch/has/uaccess/flushcache.h) \
  /root/linux-next/arch/x86/include/uapi/asm/msr.h \
  /root/linux-next/arch/x86/include/asm/atomic.h \
  /root/linux-next/arch/x86/include/asm/cmpxchg.h \
  /root/linux-next/arch/x86/include/asm/cmpxchg_64.h \
  /root/linux-next/arch/x86/include/asm/atomic64_64.h \
  /root/linux-next/include/asm-generic/atomic-instrumented.h \
  /root/linux-next/include/linux/tracepoint-defs.h \
  /root/linux-next/include/linux/atomic.h \
  /root/linux-next/include/linux/atomic-fallback.h \
    $(wildcard include/config/generic/atomic64.h) \
  /root/linux-next/include/asm-generic/atomic-long.h \
  /root/linux-next/include/linux/static_key.h \
  /root/linux-next/arch/x86/include/asm/paravirt.h \
    $(wildcard include/config/debug/entry.h) \
  /root/linux-next/arch/x86/include/asm/frame.h \
  /root/linux-next/arch/x86/include/asm/special_insns.h \
  /root/linux-next/arch/x86/include/asm/fpu/types.h \
  /root/linux-next/arch/x86/include/asm/unwind_hints.h \
  /root/linux-next/arch/x86/include/asm/orc_types.h \
  /root/linux-next/include/linux/personality.h \
  /root/linux-next/include/uapi/linux/personality.h \
  /root/linux-next/include/linux/err.h \
  /root/linux-next/include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /root/linux-next/arch/x86/include/asm/irqflags.h \
  /root/linux-next/include/linux/bottom_half.h \
  /root/linux-next/include/linux/spinlock_types.h \
  /root/linux-next/include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
  /root/linux-next/include/linux/rwlock_types.h \
  /root/linux-next/arch/x86/include/asm/spinlock.h \
  /root/linux-next/arch/x86/include/asm/qspinlock.h \
  /root/linux-next/include/asm-generic/qspinlock.h \
  /root/linux-next/arch/x86/include/asm/qrwlock.h \
  /root/linux-next/include/asm-generic/qrwlock.h \
  /root/linux-next/include/linux/rwlock.h \
  /root/linux-next/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
    $(wildcard include/config/generic/lockbreak.h) \
  /root/linux-next/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  /root/linux-next/include/linux/time32.h \
  /root/linux-next/include/linux/uidgid.h \
    $(wildcard include/config/multiuser.h) \
    $(wildcard include/config/user/ns.h) \
  /root/linux-next/include/linux/highuid.h \
  /root/linux-next/include/linux/kmod.h \
  /root/linux-next/include/linux/umh.h \
  /root/linux-next/include/linux/gfp.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/zone/device.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/cma.h) \
  /root/linux-next/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/vm/pgflags.h) \
  /root/linux-next/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/zsmalloc.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/page/extension.h) \
    $(wildcard include/config/deferred/struct/page/init.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  /root/linux-next/include/linux/wait.h \
  /root/linux-next/include/uapi/linux/wait.h \
  /root/linux-next/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  /root/linux-next/include/linux/nodemask.h \
  /root/linux-next/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  /root/linux-next/include/linux/page-flags-layout.h \
    $(wildcard include/config/numa/balancing.h) \
  include/generated/bounds.h \
  /root/linux-next/include/linux/memory_hotplug.h \
    $(wildcard include/config/arch/has/add/pages.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  /root/linux-next/include/linux/notifier.h \
    $(wildcard include/config/tree/srcu.h) \
  /root/linux-next/include/linux/errno.h \
  /root/linux-next/include/uapi/linux/errno.h \
  /root/linux-next/include/linux/mutex.h \
    $(wildcard include/config/mutex/spin/on/owner.h) \
    $(wildcard include/config/debug/mutexes.h) \
  /root/linux-next/include/linux/osq_lock.h \
  /root/linux-next/include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  /root/linux-next/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/spin/on/owner.h) \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  /root/linux-next/arch/x86/include/asm/rwsem.h \
  /root/linux-next/include/linux/srcu.h \
    $(wildcard include/config/tiny/srcu.h) \
    $(wildcard include/config/srcu.h) \
  /root/linux-next/include/linux/rcupdate.h \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/stall/common.h) \
    $(wildcard include/config/no/hz/full.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
    $(wildcard include/config/tasks/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/arch/weak/release/acquire.h) \
  /root/linux-next/include/linux/rcutree.h \
  /root/linux-next/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
    $(wildcard include/config/wq/watchdog.h) \
  /root/linux-next/include/linux/timer.h \
    $(wildcard include/config/debug/objects/timers.h) \
    $(wildcard include/config/no/hz/common.h) \
  /root/linux-next/include/linux/ktime.h \
  /root/linux-next/include/linux/jiffies.h \
  /root/linux-next/include/linux/timex.h \
  /root/linux-next/include/uapi/linux/timex.h \
  /root/linux-next/include/uapi/linux/param.h \
  /root/linux-next/arch/x86/include/uapi/asm/param.h \
  /root/linux-next/include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /root/linux-next/include/uapi/asm-generic/param.h \
  /root/linux-next/arch/x86/include/asm/timex.h \
  /root/linux-next/arch/x86/include/asm/tsc.h \
    $(wildcard include/config/x86/tsc.h) \
  include/generated/timeconst.h \
  /root/linux-next/include/linux/timekeeping.h \
  /root/linux-next/include/linux/timekeeping32.h \
  /root/linux-next/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  /root/linux-next/include/linux/rcu_segcblist.h \
  /root/linux-next/include/linux/srcutree.h \
  /root/linux-next/include/linux/rcu_node_tree.h \
    $(wildcard include/config/rcu/fanout.h) \
    $(wildcard include/config/rcu/fanout/leaf.h) \
  /root/linux-next/include/linux/completion.h \
  /root/linux-next/arch/x86/include/asm/mmzone.h \
  /root/linux-next/arch/x86/include/asm/mmzone_64.h \
  /root/linux-next/arch/x86/include/asm/smp.h \
    $(wildcard include/config/x86/local/apic.h) \
    $(wildcard include/config/x86/io/apic.h) \
    $(wildcard include/config/debug/nmi/selftest.h) \
  /root/linux-next/arch/x86/include/asm/mpspec.h \
    $(wildcard include/config/eisa.h) \
    $(wildcard include/config/x86/mpparse.h) \
  /root/linux-next/arch/x86/include/asm/mpspec_def.h \
  /root/linux-next/arch/x86/include/asm/x86_init.h \
  /root/linux-next/arch/x86/include/asm/apicdef.h \
  /root/linux-next/arch/x86/include/asm/apic.h \
    $(wildcard include/config/x86/x2apic.h) \
  /root/linux-next/arch/x86/include/asm/fixmap.h \
    $(wildcard include/config/provide/ohci1394/dma/init.h) \
    $(wildcard include/config/pci/mmconfig.h) \
    $(wildcard include/config/x86/intel/mid.h) \
    $(wildcard include/config/acpi/apei/ghes.h) \
    $(wildcard include/config/intel/txt.h) \
  /root/linux-next/arch/x86/include/asm/acpi.h \
    $(wildcard include/config/acpi/apei.h) \
    $(wildcard include/config/acpi.h) \
    $(wildcard include/config/acpi/numa.h) \
  /root/linux-next/include/acpi/pdc_intel.h \
  /root/linux-next/arch/x86/include/asm/numa.h \
    $(wildcard include/config/numa/emu.h) \
  /root/linux-next/arch/x86/include/asm/topology.h \
    $(wildcard include/config/sched/mc/prio.h) \
  /root/linux-next/include/asm-generic/topology.h \
  /root/linux-next/arch/x86/include/asm/mmu.h \
    $(wildcard include/config/modify/ldt/syscall.h) \
  /root/linux-next/arch/x86/include/asm/realmode.h \
    $(wildcard include/config/acpi/sleep.h) \
  /root/linux-next/arch/x86/include/asm/io.h \
    $(wildcard include/config/mtrr.h) \
    $(wildcard include/config/x86/pat.h) \
  arch/x86/include/generated/asm/early_ioremap.h \
  /root/linux-next/include/asm-generic/early_ioremap.h \
    $(wildcard include/config/generic/early/ioremap.h) \
  /root/linux-next/include/asm-generic/iomap.h \
    $(wildcard include/config/has/ioport/map.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/generic/iomap.h) \
  /root/linux-next/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  /root/linux-next/include/asm-generic/io.h \
    $(wildcard include/config/virt/to/bus.h) \
  /root/linux-next/include/linux/logic_pio.h \
    $(wildcard include/config/indirect/pio.h) \
  /root/linux-next/include/linux/fwnode.h \
  /root/linux-next/include/linux/vmalloc.h \
  /root/linux-next/include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  /root/linux-next/include/linux/rbtree.h \
  /root/linux-next/include/linux/overflow.h \
  /root/linux-next/arch/x86/include/uapi/asm/vsyscall.h \
  /root/linux-next/include/asm-generic/fixmap.h \
  /root/linux-next/include/linux/mm_types.h \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/userfaultfd.h) \
    $(wildcard include/config/have/arch/compat/mmap/bases.h) \
    $(wildcard include/config/membarrier.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
    $(wildcard include/config/arch/want/batched/unmap/tlb/flush.h) \
    $(wildcard include/config/hmm.h) \
  /root/linux-next/include/linux/mm_types_task.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/arch/enable/split/pmd/ptlock.h) \
  /root/linux-next/arch/x86/include/asm/tlbbatch.h \
  /root/linux-next/include/linux/auxvec.h \
  /root/linux-next/include/uapi/linux/auxvec.h \
  /root/linux-next/arch/x86/include/uapi/asm/auxvec.h \
  /root/linux-next/include/linux/uprobes.h \
    $(wildcard include/config/uprobes.h) \
  /root/linux-next/arch/x86/include/asm/uprobes.h \
  /root/linux-next/arch/x86/include/asm/hardirq.h \
    $(wildcard include/config/kvm/intel.h) \
    $(wildcard include/config/have/kvm.h) \
    $(wildcard include/config/x86/thermal/vector.h) \
    $(wildcard include/config/x86/mce/threshold.h) \
    $(wildcard include/config/x86/mce/amd.h) \
    $(wildcard include/config/hyperv.h) \
  /root/linux-next/arch/x86/include/asm/io_apic.h \
  /root/linux-next/arch/x86/include/asm/irq_vectors.h \
    $(wildcard include/config/pci/msi.h) \
  /root/linux-next/include/linux/topology.h \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/sched/smt.h) \
  /root/linux-next/include/linux/smp.h \
    $(wildcard include/config/up/late/init.h) \
  /root/linux-next/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
  /root/linux-next/include/linux/sysctl.h \
    $(wildcard include/config/sysctl.h) \
  /root/linux-next/include/uapi/linux/sysctl.h \
  /root/linux-next/include/linux/elf.h \
  /root/linux-next/arch/x86/include/asm/elf.h \
    $(wildcard include/config/x86/x32/abi.h) \
  /root/linux-next/arch/x86/include/asm/user.h \
  /root/linux-next/arch/x86/include/asm/user_64.h \
  /root/linux-next/arch/x86/include/asm/fsgsbase.h \
  /root/linux-next/arch/x86/include/asm/vdso.h \
    $(wildcard include/config/x86/x32.h) \
  /root/linux-next/include/uapi/linux/elf.h \
  /root/linux-next/include/uapi/linux/elf-em.h \
  /root/linux-next/include/linux/kobject.h \
    $(wildcard include/config/uevent/helper.h) \
    $(wildcard include/config/debug/kobject/release.h) \
  /root/linux-next/include/linux/sysfs.h \
  /root/linux-next/include/linux/kernfs.h \
    $(wildcard include/config/kernfs.h) \
  /root/linux-next/include/linux/idr.h \
  /root/linux-next/include/linux/radix-tree.h \
  /root/linux-next/include/linux/xarray.h \
    $(wildcard include/config/xarray/multi.h) \
  /root/linux-next/include/linux/kconfig.h \
  /root/linux-next/include/linux/fs_context.h \
  /root/linux-next/include/linux/refcount.h \
    $(wildcard include/config/refcount/full.h) \
  /root/linux-next/arch/x86/include/asm/refcount.h \
  /root/linux-next/include/linux/kobject_ns.h \
  /root/linux-next/include/linux/kref.h \
  /root/linux-next/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /root/linux-next/include/linux/rbtree_latch.h \
  /root/linux-next/include/linux/error-injection.h \
  /root/linux-next/arch/x86/include/asm/error-injection.h \
  /root/linux-next/include/asm-generic/error-injection.h \
  /root/linux-next/arch/x86/include/asm/module.h \
    $(wildcard include/config/unwinder/orc.h) \
    $(wildcard include/config/m486.h) \
    $(wildcard include/config/m586.h) \
    $(wildcard include/config/m586tsc.h) \
    $(wildcard include/config/m586mmx.h) \
    $(wildcard include/config/mcore2.h) \
    $(wildcard include/config/m686.h) \
    $(wildcard include/config/mpentiumii.h) \
    $(wildcard include/config/mpentiumiii.h) \
    $(wildcard include/config/mpentiumm.h) \
    $(wildcard include/config/mpentium4.h) \
    $(wildcard include/config/mk6.h) \
    $(wildcard include/config/mk8.h) \
    $(wildcard include/config/melan.h) \
    $(wildcard include/config/mcrusoe.h) \
    $(wildcard include/config/mefficeon.h) \
    $(wildcard include/config/mwinchipc6.h) \
    $(wildcard include/config/mwinchip3d.h) \
    $(wildcard include/config/mcyrixiii.h) \
    $(wildcard include/config/mviac3/2.h) \
    $(wildcard include/config/mviac7.h) \
    $(wildcard include/config/mgeodegx1.h) \
    $(wildcard include/config/mgeode/lx.h) \
  /root/linux-next/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  /root/linux-next/arch/x86/include/asm/orc_types.h \
  /root/linux-next/include/linux/miscdevice.h \
  /root/linux-next/include/uapi/linux/major.h \
  /root/linux-next/include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/generic/msi/irq/domain.h) \
    $(wildcard include/config/pinctrl.h) \
    $(wildcard include/config/generic/msi/irq.h) \
    $(wildcard include/config/dma/cma.h) \
    $(wildcard include/config/arch/has/sync/dma/for/device.h) \
    $(wildcard include/config/arch/has/sync/dma/for/cpu.h) \
    $(wildcard include/config/arch/has/sync/dma/for/cpu/all.h) \
    $(wildcard include/config/of.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  /root/linux-next/include/linux/ioport.h \
  /root/linux-next/include/linux/klist.h \
  /root/linux-next/include/linux/pm.h \
    $(wildcard include/config/vt/console/sleep.h) \
    $(wildcard include/config/pm.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  /root/linux-next/include/linux/ratelimit.h \
  /root/linux-next/include/linux/sched.h \
    $(wildcard include/config/virt/cpu/accounting/native.h) \
    $(wildcard include/config/sched/info.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/psi.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/arch/has/scaled/cputime.h) \
    $(wildcard include/config/virt/cpu/accounting/gen.h) \
    $(wildcard include/config/posix/timers.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/ubsan.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/intel/rdt.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/rseq.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/kcov.h) \
    $(wildcard include/config/bcache.h) \
    $(wildcard include/config/vmap/stack.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/gcc/plugin/stackleak.h) \
    $(wildcard include/config/debug/aid/for/syzbot.h) \
    $(wildcard include/config/arch/task/struct/on/stack.h) \
    $(wildcard include/config/debug/rseq.h) \
  /root/linux-next/include/uapi/linux/sched.h \
  /root/linux-next/include/linux/pid.h \
  /root/linux-next/include/linux/rculist.h \
  /root/linux-next/include/linux/sem.h \
  /root/linux-next/include/uapi/linux/sem.h \
  /root/linux-next/include/linux/ipc.h \
  /root/linux-next/include/linux/rhashtable-types.h \
  /root/linux-next/include/uapi/linux/ipc.h \
  /root/linux-next/arch/x86/include/uapi/asm/ipcbuf.h \
  /root/linux-next/include/uapi/asm-generic/ipcbuf.h \
  /root/linux-next/arch/x86/include/uapi/asm/sembuf.h \
  /root/linux-next/include/linux/shm.h \
  /root/linux-next/include/uapi/linux/shm.h \
  /root/linux-next/include/uapi/asm-generic/hugetlb_encode.h \
  /root/linux-next/arch/x86/include/uapi/asm/shmbuf.h \
  /root/linux-next/include/uapi/asm-generic/shmbuf.h \
  /root/linux-next/arch/x86/include/asm/shmparam.h \
  /root/linux-next/include/linux/kcov.h \
  /root/linux-next/include/uapi/linux/kcov.h \
  /root/linux-next/include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  /root/linux-next/include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/time/low/res.h) \
    $(wildcard include/config/timerfd.h) \
  /root/linux-next/include/linux/timerqueue.h \
  /root/linux-next/include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
    $(wildcard include/config/have/arch/seccomp/filter.h) \
    $(wildcard include/config/seccomp/filter.h) \
    $(wildcard include/config/checkpoint/restore.h) \
  /root/linux-next/include/uapi/linux/seccomp.h \
  /root/linux-next/arch/x86/include/asm/seccomp.h \
  /root/linux-next/arch/x86/include/asm/unistd.h \
  /root/linux-next/arch/x86/include/uapi/asm/unistd.h \
  arch/x86/include/generated/uapi/asm/unistd_64.h \
  arch/x86/include/generated/asm/unistd_64_x32.h \
  /root/linux-next/arch/x86/include/asm/ia32_unistd.h \
  arch/x86/include/generated/asm/unistd_32_ia32.h \
  /root/linux-next/include/asm-generic/seccomp.h \
  /root/linux-next/include/uapi/linux/unistd.h \
  /root/linux-next/include/linux/resource.h \
  /root/linux-next/include/uapi/linux/resource.h \
  /root/linux-next/arch/x86/include/uapi/asm/resource.h \
  /root/linux-next/include/asm-generic/resource.h \
  /root/linux-next/include/uapi/asm-generic/resource.h \
  /root/linux-next/include/linux/latencytop.h \
  /root/linux-next/include/linux/sched/prio.h \
  /root/linux-next/include/linux/signal_types.h \
    $(wildcard include/config/old/sigaction.h) \
  /root/linux-next/include/uapi/linux/signal.h \
  /root/linux-next/arch/x86/include/asm/signal.h \
  /root/linux-next/arch/x86/include/uapi/asm/signal.h \
  /root/linux-next/include/uapi/asm-generic/signal-defs.h \
  /root/linux-next/arch/x86/include/uapi/asm/siginfo.h \
  /root/linux-next/include/uapi/asm-generic/siginfo.h \
  /root/linux-next/include/linux/psi_types.h \
  /root/linux-next/include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  /root/linux-next/include/uapi/linux/rseq.h \
  /root/linux-next/arch/x86/include/asm/device.h \
    $(wildcard include/config/intel/iommu.h) \
    $(wildcard include/config/amd/iommu.h) \
    $(wildcard include/config/sta2x11.h) \
    $(wildcard include/config/x86/dev/dma/ops.h) \
    $(wildcard include/config/pci/domains.h) \
  /root/linux-next/include/linux/pm_wakeup.h \
  /root/linux-next/include/linux/fs.h \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/cgroup/writeback.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/fs/encryption.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fs/dax.h) \
    $(wildcard include/config/mandatory/file/locking.h) \
    $(wildcard include/config/migration.h) \
  /root/linux-next/include/linux/wait_bit.h \
  /root/linux-next/include/linux/kdev_t.h \
  /root/linux-next/include/uapi/linux/kdev_t.h \
  /root/linux-next/include/linux/dcache.h \
  /root/linux-next/include/linux/rculist_bl.h \
  /root/linux-next/include/linux/list_bl.h \
  /root/linux-next/include/linux/bit_spinlock.h \
  /root/linux-next/include/linux/lockref.h \
    $(wildcard include/config/arch/use/cmpxchg/lockref.h) \
  /root/linux-next/include/linux/stringhash.h \
    $(wildcard include/config/dcache/word/access.h) \
  /root/linux-next/include/linux/hash.h \
    $(wildcard include/config/have/arch/hash.h) \
  /root/linux-next/include/linux/path.h \
  /root/linux-next/include/linux/list_lru.h \
    $(wildcard include/config/memcg/kmem.h) \
  /root/linux-next/include/linux/shrinker.h \
  /root/linux-next/include/linux/capability.h \
  /root/linux-next/include/uapi/linux/capability.h \
  /root/linux-next/include/linux/semaphore.h \
  /root/linux-next/include/linux/fcntl.h \
  /root/linux-next/include/uapi/linux/fcntl.h \
  /root/linux-next/arch/x86/include/uapi/asm/fcntl.h \
  /root/linux-next/include/uapi/asm-generic/fcntl.h \
  /root/linux-next/include/uapi/linux/fiemap.h \
  /root/linux-next/include/linux/migrate_mode.h \
  /root/linux-next/include/linux/percpu-rwsem.h \
  /root/linux-next/include/linux/rcuwait.h \
  /root/linux-next/include/linux/rcu_sync.h \
  /root/linux-next/include/linux/delayed_call.h \
  /root/linux-next/include/linux/uuid.h \
  /root/linux-next/include/uapi/linux/uuid.h \
  /root/linux-next/include/linux/errseq.h \
  /root/linux-next/include/linux/ioprio.h \
  /root/linux-next/include/linux/sched/rt.h \
  /root/linux-next/include/linux/iocontext.h \
  /root/linux-next/include/uapi/linux/fs.h \
  /root/linux-next/include/uapi/linux/limits.h \
  /root/linux-next/include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  /root/linux-next/include/linux/percpu_counter.h \
  /root/linux-next/include/uapi/linux/dqblk_xfs.h \
  /root/linux-next/include/linux/dqblk_v1.h \
  /root/linux-next/include/linux/dqblk_v2.h \
  /root/linux-next/include/linux/dqblk_qtree.h \
  /root/linux-next/include/linux/projid.h \
  /root/linux-next/include/uapi/linux/quota.h \
  /root/linux-next/include/linux/nfs_fs_i.h \
  /root/linux-next/include/linux/mm.h \
    $(wildcard include/config/have/arch/mmap/rnd/bits.h) \
    $(wildcard include/config/have/arch/mmap/rnd/compat/bits.h) \
    $(wildcard include/config/arch/uses/high/vma/flags.h) \
    $(wildcard include/config/arch/has/pkeys.h) \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/parisc.h) \
    $(wildcard include/config/sparc64.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/dev/pagemap/ops.h) \
    $(wildcard include/config/pci/p2pdma.h) \
    $(wildcard include/config/shmem.h) \
    $(wildcard include/config/debug/vm/rb.h) \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/hugetlbfs.h) \
  /root/linux-next/include/linux/percpu-refcount.h \
  /root/linux-next/include/linux/page_ext.h \
    $(wildcard include/config/idle/page/tracking.h) \
  /root/linux-next/include/linux/stacktrace.h \
    $(wildcard include/config/stacktrace.h) \
    $(wildcard include/config/user/stacktrace/support.h) \
  /root/linux-next/include/linux/stackdepot.h \
  /root/linux-next/include/linux/page_ref.h \
    $(wildcard include/config/debug/page/ref.h) \
  /root/linux-next/include/linux/page-flags.h \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/thp/swap.h) \
    $(wildcard include/config/ksm.h) \
  /root/linux-next/include/linux/memremap.h \
  /root/linux-next/arch/x86/include/asm/pgtable.h \
    $(wildcard include/config/debug/wx.h) \
    $(wildcard include/config/have/arch/transparent/hugepage/pud.h) \
    $(wildcard include/config/have/arch/soft/dirty.h) \
    $(wildcard include/config/arch/enable/thp/migration.h) \
  /root/linux-next/arch/x86/include/asm/pgtable_64.h \
  /root/linux-next/arch/x86/include/asm/pgtable-invert.h \
  /root/linux-next/include/asm-generic/pgtable.h \
    $(wildcard include/config/have/arch/huge/vmap.h) \
    $(wildcard include/config/x86/espfix64.h) \
  /root/linux-next/include/linux/huge_mm.h \
  /root/linux-next/include/linux/sched/coredump.h \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
  /root/linux-next/include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
    $(wildcard include/config/debug/tlbflush.h) \
    $(wildcard include/config/debug/vm/vmacache.h) \
  /root/linux-next/include/linux/vm_event_item.h \
    $(wildcard include/config/memory/balloon.h) \
    $(wildcard include/config/balloon/compaction.h) \
  /root/linux-next/include/linux/slab.h \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/have/hardened/usercopy/allocator.h) \
    $(wildcard include/config/slab.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
  /root/linux-next/include/linux/kasan.h \
  /root/linux-next/arch/x86/include/asm/uaccess.h \
    $(wildcard include/config/x86/intel/usercopy.h) \
  /root/linux-next/arch/x86/include/asm/smap.h \
  /root/linux-next/arch/x86/include/asm/extable.h \
  /root/linux-next/arch/x86/include/asm/uaccess_64.h \
  /root/VE482/challenge/t6/t6.h \

/root/VE482/challenge/t6/t6.o: $(deps_/root/VE482/challenge/t6/t6.o)

$(deps_/root/VE482/challenge/t6/t6.o):
