# Virtualisation evaluation
| Type | Example | Main benefit | Trade-off |
|---|---|---|---|
| Type-1 | KVM, ESXi, Hyper-V, Xen | Runs directly on hardware; suitable for server workloads | Host management and licensing/skill needs |
| Type-2 | VirtualBox, VMware Workstation | Easy desktop testing | Host OS overhead and less predictable performance |

For the result portal, a Type-1 hypervisor is preferred for a private server environment where isolation, uptime and consolidation matter. Type-2 is appropriate for student demonstrations and development labs. Hardware-assisted virtualisation (Intel VT-x/AMD-V) improves VM execution support.
