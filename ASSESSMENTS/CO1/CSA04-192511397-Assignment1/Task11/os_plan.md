# Task 11 – Recommended Operating-System Plan

| Component | OS type and structure | Essential services/protection | I/O approach |
|---|---|---|---|
| Bedside monitors | Embedded hard RTOS; microkernel preferred | Fixed-priority scheduling, watchdog, secure boot, minimal validated services | Interrupt-driven sensor input |
| Nurses’ tablets | Managed mobile OS | Encryption, MDM, authentication, power management | Wireless network; offline queue with safe sync |
| Doctors’ workstations | Desktop OS, modular/hybrid kernel | MFA, endpoint protection, role-based access, audit | Standard interrupt/DMA |
| Patient database | Clustered server OS; modular Linux-style kernel | Replication, transactions, backups, RBAC, audit, fail-over | High-speed SSD and network |
| MRI server | Multiprocessor server OS | Parallel scheduling, GPU/driver control, large memory | DMA and high-throughput storage |
| Partner hospitals | Distributed services | Mutual authentication, encryption, authorization, consistency controls | Secure APIs and replicated links |

Limitations and risks: RTOS devices require strict validation and controlled updates; clustering adds operational complexity; replication can introduce consistency lag; mobile devices can be lost; networks and cloud services can fail. Mitigate with redundancy, backups, monitoring, tested recovery, encryption, least privilege and clinical downtime procedures.

The plan scales to three hospitals by using federated identity, secure inter-hospital APIs, replicated services and centrally monitored clusters. Each hospital should retain local operation for critical clinical workflows if the WAN/cloud link is unavailable.

## Alternative: two large virtualized servers
Consolidation can improve utilization and simplify deployment, but virtualization adds hypervisor scheduling, memory overhead and shared-failure risk. A noisy VM could affect monitor latency if real-time devices share the host. Keep bedside alarm control on dedicated validated embedded hardware. Use VMs for non-real-time servers with CPU/memory reservations, redundancy and tested fail-over. Two hosts still require quorum/fencing and independent power/network/storage failure planning.
