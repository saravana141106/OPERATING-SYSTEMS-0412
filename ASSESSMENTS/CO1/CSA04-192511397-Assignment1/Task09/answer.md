# Task 9 – Memory Hierarchy and I/O Systems

| Level | Typical role | Relative access |
|---|---|---|
| CPU registers | Current instructions/data | Fastest, very small |
| CPU cache (L1/L2/L3) | Frequently reused data | Very fast, small |
| Main memory (RAM) | Running programs and active patient data | Nanosecond scale |
| SSD | OS, database files, active MRI data | Microsecond scale |
| Hard disk | Bulk/archival storage | Millisecond scale |
| Network storage/cloud | Shared records and long-term archive | Network-dependent, typically higher latency |

Keep monitor readings and immediate alarm state in RAM, with durable event logs sent to a protected local gateway/server. Keep active patient records and database indexes on redundant low-latency SSD storage, with encrypted backups. MRI images require high-capacity, high-throughput local/parallel storage and archival storage. Replicated records and backups can be stored at a separate site/cloud subject to privacy and retention policy.

Programmed I/O makes the CPU repeatedly manage transfers; interrupt-driven I/O lets a device notify the CPU when ready; DMA transfers blocks between device and memory with limited CPU involvement. DMA is preferred for large MRI image transfers because it avoids one CPU-managed operation per word. Interrupt-driven I/O is appropriate for relatively small or event-driven monitor data.

Caching speeds repeated record/index lookups, but stale cache entries can create consistency risks. The database must use transaction and cache-coherence/invalidation mechanisms so clinicians do not act on stale patient data.

## Alternative: interrupt per word for 500 MB MRI transfer
If each word is 4 bytes, 500 MiB contains 131,072,000 words and would generate roughly that many interrupts. Even at a hypothetical 1 microsecond of CPU handling per interrupt, this is about 131 seconds of CPU time, excluding transfer overhead. DMA instead uses block transfers and a much smaller number of completion interrupts. A DMA buffer must be large enough for efficient blocks but bounded to avoid excessive memory pressure.
