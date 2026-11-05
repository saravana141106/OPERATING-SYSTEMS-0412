# Task 2 – Type of Operating System for Each Environment

| Environment | Recommended OS type | Reason | Rejected alternative |
|---|---|---|---|
| Patient monitors | Embedded hard real-time OS (RTOS) | Bounded interrupt and task latency; small footprint | General-purpose desktop OS has no inherent hard deadline guarantee |
| Nurses’ tablets | Handheld/mobile OS | Power management, touch UI, secure device management | Server OS is too heavy and unsuitable for mobile interaction |
| Doctors’ workstations | Desktop/time-sharing OS | Interactive applications, multitasking and peripheral support | RTOS is unnecessarily restrictive |
| Patient database | Clustered server OS | Redundant nodes, fail-over and concurrent transactions | One standalone machine is a single point of failure |
| MRI imaging | Multiprocessor server OS | Parallel CPU/GPU workloads and high memory bandwidth | Single-processor design limits throughput |
| Partner hospitals | Distributed system | Networked services, replicated/shared records and independent sites | One central machine creates distance and availability dependency |

A symmetric multiprocessing (SMP) design is preferred for the imaging server because processors share memory and the OS schedules work across available CPUs. Asymmetric multiprocessing can be useful in specialized systems with a dedicated controller, but it is less flexible for general MRI workloads.

The database should use a cluster with health monitoring, replicated storage or database replication, quorum/fencing, and tested fail-over. A cluster reduces downtime but does not remove the need for backups or protection against logical corruption.

## Alternative: one large multiprocessor database machine
A large SMP machine can offer high throughput and simpler administration, but remains a single failure domain (motherboard, power, OS crash, storage controller). A cluster can continue service after a node failure, at the cost of network, replication and coordination overhead. For patient records, availability and recovery justify the cluster.
