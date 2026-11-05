# I/O methods
- Programmed I/O: CPU actively checks and moves data.
- Interrupt-driven I/O: device interrupts CPU when service is needed.
- DMA: device/controller transfers blocks to memory; CPU handles setup/completion.
MRI bulk image transfer is the strongest DMA use case. See the report for the 500 MiB interrupt-per-word comparison.
