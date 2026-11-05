# Task 1 – Requirements of Each Computing Environment

## Ranked requirements
| Environment | Priority 1 | Priority 2 | Priority 3 | Priority 4 |
|---|---|---|---|---|
| Bedside monitors | Deterministic alarm response (≤10 ms target) | Reliability and integrity | Isolation/security | Low memory and power |
| Nurses’ tablets | Battery life and mobility | Secure access | Usable interface | Offline tolerance and synchronization |
| Doctors’ workstations | Data confidentiality | Interactive response | Availability | Peripheral and display support |
| Patient-record database | Continuous availability | Integrity, access control and audit | Concurrent throughput | Backup and recovery |
| MRI imaging server | High throughput/parallel processing | Memory and I/O bandwidth | Availability | Controlled resource scheduling |
| Partner-hospital link | Secure communication | Consistency and availability | Interoperability | Scalable network throughput |

## Evaluation and conflicts
The monitor alarm deadline is safety-critical: average speed is insufficient if a worst-case scheduling delay can exceed 10 ms. Battery efficiency matters strongly on tablets, while the database prioritizes durable transactions and recovery. MRI processing benefits from multiple CPUs and high-throughput storage. The partner link needs authenticated, encrypted communication and a distributed data model.

Conflicts include low power versus continuous communication, low latency versus high multi-user throughput, and strict isolation versus convenient sharing. Patient alarms, correct patient identity, medication/allergy records, and durable clinical transactions are the highest safety concerns.

Historical lessons: batch systems are appropriate for non-urgent MRI post-processing and backups; time-sharing supports many doctors and nurses; personal-computer systems suit desktop workstations; mobile OS techniques such as sleep states and radio power management suit tablets. Real-time scheduling is required for monitor alarms.

## Alternative: one general-purpose OS everywhere
A general-purpose OS may have excellent average response but ordinarily cannot promise a hard 10 ms worst-case deadline under arbitrary load. A validated real-time kernel can provide bounded scheduling and interrupt latency. A full desktop OS also consumes more RAM, storage and background CPU on small monitors and increases patch/configuration effort across unlike devices. A uniform OS simplifies some administration but creates a common failure/security domain. Therefore, a single OS image is not justified.
